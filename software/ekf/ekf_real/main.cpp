#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "ekf.h"
#include "utils.h"

using namespace std;

#define pule_per_revolution     780
#define wheel_diameter          0.065

ekf_t ekf;
ekf_params_t ekf_params = {
    .robot_width = 0.24,
    .control_motion_factor = 0.001f,
    .control_turn_factor = 0.001f,

    .tag_cart_x = 0.0f,
    .tag_cart_y = 0.0f,

    .measurement_distance_stddev = 0.05f,
    .measurement_angle_stddev = 10.0 / 180.0 * M_PI,
};

int main(){
    string line;
    ifstream file_control_measurement("../control_measurement.txt");
    ofstream file_correction("../correction.txt");

    sphere_t spheres[3];
    uint8_t sphere_idx = 0;
    float yaw = 0;
    while (getline(file_control_measurement, line))
    {
        vector<string> components = split(line, " ");
        if(components[0] == "M"){
            cout << line << endl;
            spheres[sphere_idx].x = stof(components[1]);
            spheres[sphere_idx].y = stof(components[2]);
            spheres[sphere_idx].z = 3;
            spheres[sphere_idx].r = stof(components[4]);
            yaw = stof(components[5])/180*M_PI;
            sphere_idx++;
            if(sphere_idx == 3) break;
        }
    }

    trilateration_result_t trilateration_result;
    trilaterate(spheres, &trilateration_result);
    cout << trilateration_result.PA.x << " "
    << trilateration_result.PA.y << " "
    << trilateration_result.PA.z << " "
    << yaw << "\n";

    ekf.x = trilateration_result.PA.x;
    ekf.y = trilateration_result.PA.y;
    ekf.theta = yaw;

    ekf.cov[0][0] = 0.1;
    ekf.cov[1][1] = 0.1;
    ekf.cov[2][2] = (50.0 / 180.0 * M_PI);
    
    ekf.cov[0][0] = ekf.cov[0][0]*ekf.cov[0][0];
    ekf.cov[1][1] = ekf.cov[1][1]*ekf.cov[1][1];
    ekf.cov[2][2] = ekf.cov[2][2]*ekf.cov[2][2];

    ekf_init(&ekf, &ekf_params);
    
    int cnt = 0;
    while (getline(file_control_measurement, line))
    {
        vector<string> components = split(line, " ");
        if(components[0] == "C"){
            float l = -stof(components[1]);
            float r = -stof(components[2]);
            ekf_control_t control;
            control.l = l/pule_per_revolution*(M_PI*wheel_diameter);
            control.r = r/pule_per_revolution*(M_PI*wheel_diameter);
            ekf_predict(&ekf, &control);
        }
        else if(components[0] == "M"){
            ekf_measurement_t m;
            m.rx = stof(components[1]);
            m.ry = stof(components[2]);
            if (abs(m.rx) < 1 && abs(m.ry) < 1) continue;
            m.range = sqrt(stof(components[4])*stof(components[4]) - 3*3);
            m.yaw = stof(components[5])/180*M_PI;
            printf("m: %f %f %f %f\n", m.rx, m.ry, m.range, m.yaw);
            ekf_correct(&ekf, &m);
            file_correction << "F " << ekf.x*300+500 << " " << ekf.y*300+3000 << " " << ekf.theta << endl;
            // cnt++;
            // if(cnt == 10) break;
        }
    }

    // for(int i=0; i<controls.size(); i++){
    //     cout << i << endl;
        // ekf_predict(&ekf_fake, &controls[i]);
        // file_prediction << "F " << ekf_fake.x << " " << ekf_fake.y << " " << ekf_fake.theta << endl;
        // file_prediction << "E " << ekf_fake.cov[0][0] << " " \
        //                         << ekf_fake.cov[0][1] << " " \
        //                         << ekf_fake.cov[0][2] << " " \
        //                         << ekf_fake.cov[1][0] << " " \
        //                         << ekf_fake.cov[1][1] << " " \
        //                         << ekf_fake.cov[1][2] << " " \
        //                         << ekf_fake.cov[2][0] << " " \
        //                         << ekf_fake.cov[2][1] << " " \
        //                         << ekf_fake.cov[2][2] << endl;

    //     cout << "C: " << controls[i].r << " " <<controls[i].l << endl;
    //     ekf_predict(&ekf, &controls[i]);
    //     cout << ekf.x << " " << ekf.y << " " << ekf.theta << endl;
    //     for(int j=0; j<measurements[i].size(); j++){
    //         ekf_correct(&ekf, &measurements[i][j]);
    //         cout << "M: " << measurements[i][j].rx << " " << measurements[i][j].ry << " " << measurements[i][j].range << " " << measurements[i][j].yaw << endl;
    //         cout << ekf.x << " " << ekf.y << " " << ekf.theta << endl;
    //     }
    //     cout << "---------" << endl;

    //     file_correction << "F " << ekf.x << " " << ekf.y << " " << ekf.theta << endl;
    //     file_correction << "E " << ekf.cov[0][0] << " " \
    //                             << ekf.cov[0][1] << " " \
    //                             << ekf.cov[0][2] << " " \
    //                             << ekf.cov[1][0] << " " \
    //                             << ekf.cov[1][1] << " " \
    //                             << ekf.cov[1][2] << " " \
    //                             << ekf.cov[2][0] << " " \
    //                             << ekf.cov[2][1] << " " \
    //                             << ekf.cov[2][2] << endl;

    //     // if(i==686) break;
    // }

    file_control_measurement.close();
    file_correction.close();
    return 0;
}