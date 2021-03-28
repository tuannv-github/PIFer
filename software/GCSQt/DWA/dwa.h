#ifndef _DWA_H_
#define _DWA_H_

#include <QVector>
#include <TrajectoryGen/trajectorygen.h>

#define DWA_WIDTH_V     50
#define DWA_WIDTH_W     50
#define DWA_SIM_PERIOD  5
#define DWA_SIM_STEP    0.1
#define DWA_SIM_SIZE    ((int)(DWA_SIM_PERIOD/DWA_SIM_STEP))

typedef struct{
    float v_min;
    float v_max;
    float w_min;
    float w_max;
}dwa_params_t;

typedef struct{
    float x;
    float y;
    float w;
}dwa_state_t;

typedef struct{
    float v[DWA_WIDTH_V];
    float w[DWA_WIDTH_W];
    dwa_state_t hypothesis[DWA_WIDTH_V][DWA_WIDTH_W][DWA_SIM_SIZE];
    int v_idx;
    int w_idx;
}dwa_t;

void dwa_init(dwa_t *dwa, dwa_params_t *params);
void dwa_gen(dwa_t *dwa, dwa_state_t *state);
void dwa_score(dwa_t *dwa, QVector<trajectory_point_2d_t> ref_traj);

#endif
