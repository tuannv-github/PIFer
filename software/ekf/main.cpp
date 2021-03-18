#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "ekf.h"

using namespace std;

std::vector<ekf_control_t> controls;
std::vector<std::vector<ekf_measurement_t>> measurements;

ekf_t ekf;
ekf_params_t ekf_params = {
    .robot_width = 0.16f,
    .control_motion_factor = 0.4f,
    .control_turn_factor = 0.8f,

    .tag_cart_x = 0.0f,
    .tag_cart_y = 0.0f,

    .measurement_distance_stddev = 0.1f,
    .measurement_angle_stddev = 0.05f,
};

int main(){
    string line;
    ifstream file_control("../sim/control.txt");
    ifstream file_measurement("../sim/measurement.txt");
    ifstream file_reference("../sim/reference.txt");
    // ofstream file_prediction("../sim/prediction.txt");
    ofstream file_correction("../sim/correction.txt");

    int control_counter, measurement_counter;

    control_counter = 0;
    while (getline(file_control, line))
    {
        // cout << line << endl;
        ekf_control_t control;
        std::string::size_type sz;
        control.l = std::stof(line,&sz);
        control.r = std::stof(line.substr(sz));
        // cout << control.l << " " << control.r << endl;
        controls.push_back(control);
        control_counter++;
    }
    cout << "control: " << control_counter << endl;

    measurement_counter = 0;
    std::vector<ekf_measurement_t> measurement;
    while (getline(file_measurement, line))
    {
        // cout << line << endl;
        if(line.size() == 1){
            measurements.push_back(measurement);
            measurement.clear();
            continue;
        }
        ekf_measurement_t m;
        istringstream in(line);
        in >> m.rx >> m.ry >> m.range >> m.yaw;

        measurement.push_back(m);
        measurement_counter++;
    }
    cout << "measurement: " << measurement_counter << endl;

    if(control_counter != measurement_counter/4){
        cout << "control_counter != measurement_counter/4"<< endl;
    }

    {
        getline(file_reference, line);
        istringstream in(line);
        in >> ekf.x >> ekf.y >> ekf.theta;
    }

    ekf.cov[0][0] = 0.0f;
    ekf.cov[1][1] = 0.0f;
    ekf.cov[2][2] = 0.0f;
    
    ekf_init(&ekf, &ekf_params);
    // ekf_t ekf_fake = ekf;
    for(int i=0; i<controls.size(); i++){
        cout << i << endl;
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

        cout << "C: " << controls[i].r << " " <<controls[i].l << endl;
        ekf_predict(&ekf, &controls[i]);
        cout << ekf.x << " " << ekf.y << " " << ekf.theta << endl;
        for(int j=0; j<measurements[i].size(); j++){
            ekf_correct(&ekf, &measurements[i][j]);
            cout << "M: " << measurements[i][j].rx << " " << measurements[i][j].ry << " " << measurements[i][j].range << " " << measurements[i][j].yaw << endl;
            cout << ekf.x << " " << ekf.y << " " << ekf.theta << endl;
        }
        cout << "---------" << endl;

        file_correction << "F " << ekf.x << " " << ekf.y << " " << ekf.theta << endl;
        file_correction << "E " << ekf.cov[0][0] << " " \
                                << ekf.cov[0][1] << " " \
                                << ekf.cov[0][2] << " " \
                                << ekf.cov[1][0] << " " \
                                << ekf.cov[1][1] << " " \
                                << ekf.cov[1][2] << " " \
                                << ekf.cov[2][0] << " " \
                                << ekf.cov[2][1] << " " \
                                << ekf.cov[2][2] << endl;

        // if(i==686) break;
    }

    // file_prediction.close();
    file_correction.close();
    return 0;
}