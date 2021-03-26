#include "dwa.h"

#include <limits>

void dwa_init(dwa_t *dwa, dwa_params_t *params){
    float step_v, step_w;
    step_v = (params->v_max - params->v_min)/DWA_WIDTH_V;
    step_w = (params->w_max - params->w_min)/DWA_WIDTH_W;
    for(int i=0; i<DWA_WIDTH_V; i++){
        dwa->v[i] = params->v_min + step_v*i;
    }
    for(int i=0; i<DWA_WIDTH_W; i++){
        dwa->w[i] = params->w_min + step_w*i;
    }
}

static void dwa_forward(dwa_state_t *new_state, dwa_state_t *old_state, float v, float w){
    new_state->x = old_state->x +v*cos(old_state->w)*DWA_SIM_STEP;
    new_state->y = old_state->y + v*sin(old_state->w)*DWA_SIM_STEP;
    new_state->w = old_state->w + w*DWA_SIM_STEP;
}

void dwa_gen(dwa_t *dwa, dwa_state_t *state){
    for(int i=0; i<DWA_WIDTH_V; i++){
        for(int j=0; j<DWA_WIDTH_W; j++){
            dwa->hypothesis[i*j][0].x = state->x;
            dwa->hypothesis[i*j][0].y = state->y;
            dwa->hypothesis[i*j][0].w = state->w;
            for(int k=1; k<DWA_SIM_PERIOD/DWA_SIM_STEP; k++){
                dwa_forward(&dwa->hypothesis[i*j][k], &dwa->hypothesis[i*j][k-1], dwa->v[i], dwa->w[j]);
            }
        }
    }
}

void dwa_score(dwa_t *dwa, QVector<trajectory_point_2d_t> ref_traj){
    float max_score = 0;
    for(int i=0; i<DWA_WIDTH_V; i++){
        for(int j=0; j<DWA_WIDTH_W; j++){
            float score = 0;
            for(int k=0; k<DWA_SIM_SIZE; k++){
                float dx = dwa->hypothesis[i*j][k].x - ref_traj[k].x;
                float dy = dwa->hypothesis[i*j][k].y - ref_traj[k].y;
                score += (dx*dx + dy*dy);
            }
            score = 1.0f/score;
            if(score > max_score){
                max_score = score;
                dwa->v_idx = i;
                dwa->w_idx = j;
            }
        }
    }
}
