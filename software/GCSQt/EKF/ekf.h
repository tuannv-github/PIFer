#ifndef _EKF_H_
#define _EKF_H_

#include <stdint.h>
#include <math.h>

typedef struct{
    float robot_width;
    float control_motion_factor;
    float control_turn_factor;

    float tag_cart_x;
    float tag_cart_y;

    float measurement_distance_stddev;
    float measurement_angle_stddev;

    float pule_per_revolution;
    float wheel_diameter;

    /*Internal variable*/
    float tag_polar_r;
    float tag_polar_theta;
}ekf_params_t;

typedef struct{
    float x;
    float y;
    float theta;
    float cov[3][3];

    float G[3][3];
    float V[3][2];
    float h[2];
    float H[2][3];
    float Q[2][2];

    ekf_params_t *params;
}ekf_t;

typedef struct
{
    float l;
    float r;
}ekf_control_t;

typedef struct
{
    float rx;
    float ry;
    float range;
    float yaw;
}ekf_measurement_t;

typedef struct{
    float x;
    float y;
    float w;
}ekf_state_t;

void ekf_init(ekf_t *ekf, ekf_params_t *params);
void ekf_predict(ekf_t *ekf, ekf_control_t *c);
void ekf_correct(ekf_t *ekf, ekf_measurement_t *m);

#endif
