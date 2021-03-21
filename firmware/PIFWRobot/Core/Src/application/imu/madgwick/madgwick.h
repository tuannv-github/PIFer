#ifndef MadgwickAHRS_h
#define MadgwickAHRS_h

void madwgick_init(float beta);
void madwgick_gam_update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz, float dt);
void madwgick_ga_update(float gx, float gy, float gz, float ax, float ay, float az, float dt);
void magwick_get_rpy(float rpy[3]);

#endif
