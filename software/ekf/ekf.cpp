#include "ekf.h"

static void ekf_g(ekf_t *ekf, ekf_control_t *c);
static void ekf_dg_dstate(ekf_t *ekf, ekf_control_t *c);
static void ekf_dg_dcontrol(ekf_t *ekf, ekf_control_t *c);

static void ekf_dh_dstate(ekf_t *ekf, ekf_measurement_t *m);
static void ekf_h(ekf_t *ekf, ekf_measurement_t *m);

void ekf_init(ekf_t *ekf, ekf_params_t *params){
    ekf->params = params;

    ekf->G[0][0] = 1;
    ekf->G[0][1] = 0;
    ekf->G[0][2] = 0;
    ekf->G[1][0] = 0;
    ekf->G[1][1] = 1;
    ekf->G[1][2] = 0;
    ekf->G[2][0] = 0;
    ekf->G[2][1] = 0;
    ekf->G[2][2] = 1;

    if(params->tag_cart_x == 0){
        params->tag_polar_r = params->tag_cart_y;
        params->tag_polar_theta = params->tag_cart_y > 0 ? M_PI/2 : -M_PI/2;
    }else{
        params->tag_polar_r = atan2(params->tag_cart_y, params->tag_cart_x);
        params->tag_polar_theta = sqrt(params->tag_cart_x*params->tag_cart_x + params->tag_cart_y*params->tag_cart_y);
    }

    ekf->Q[0][0] = params->measurement_distance_stddev * params->measurement_distance_stddev;
    ekf->Q[1][1] = params->measurement_angle_stddev * params->measurement_angle_stddev;
    ekf->Q[0][1] = ekf->Q[1][0] = 0;
}

void ekf_predict(ekf_t *ekf, ekf_control_t *c){
    ekf_g(ekf,c);

    ekf_dg_dstate(ekf,c);
    ekf_dg_dcontrol(ekf, c);

    float gsgt[3][3];
    gsgt[0][0] = ekf->cov[0][0] + 2*ekf->G[0][2]*ekf->cov[0][2] + ekf->G[0][2]*ekf->G[0][2]*ekf->cov[2][2];
    gsgt[1][1] = ekf->cov[1][1] + 2*ekf->G[1][2]*ekf->cov[1][2] + ekf->G[1][2]*ekf->G[1][2]*ekf->cov[2][2];
    gsgt[2][2] = ekf->cov[2][2];
    gsgt[0][1] = gsgt[1][0] = ekf->cov[0][1] + ekf->G[0][2]*ekf->cov[1][2] + ekf->G[1][2]*ekf->cov[0][2] + ekf->G[0][2]*ekf->G[1][2]*ekf->cov[2][2];
    gsgt[0][2] = gsgt[2][0] = ekf->cov[0][2] + ekf->G[0][2]*ekf->cov[2][2];
    gsgt[1][2] = gsgt[2][1] = ekf->cov[1][2] + ekf->G[1][2]*ekf->cov[2][2];

    float ll = ekf->params->control_motion_factor*c->l;
    float rr = ekf->params->control_motion_factor*c->r;
    float lr = ekf->params->control_turn_factor*(c->l-c->r);
    float A = ll*ll + lr*lr;
    float B = rr*rr + lr*lr;

    float vsvt[3][3];
    vsvt[0][0] = ekf->V[0][0]*ekf->V[0][0]*A*A + ekf->V[0][1]*ekf->V[0][1]*B*B;
    vsvt[1][1] = ekf->V[1][0]*ekf->V[1][0]*A*A + ekf->V[1][1]*ekf->V[1][1]*B*B;
    vsvt[2][2] = ekf->V[2][0]*ekf->V[2][0]*A*A + ekf->V[2][1]*ekf->V[2][1]*B*B;
    vsvt[0][1] = vsvt[1][0] = ekf->V[0][0]*ekf->V[1][0]*A*A + ekf->V[0][1]*ekf->V[1][1]*B*B;
    vsvt[0][2] = vsvt[2][0] = ekf->V[0][0]*ekf->V[2][0]*A*A + ekf->V[0][1]*ekf->V[2][1]*B*B;
    vsvt[1][2] = vsvt[2][1] = ekf->V[1][0]*ekf->V[2][0]*A*A + ekf->V[2][1]*ekf->V[1][1]*B*B;

    ekf->cov[0][0] = gsgt[0][0] + vsvt[0][0];
    ekf->cov[1][1] = gsgt[1][1] + vsvt[1][1];
    ekf->cov[2][2] = gsgt[2][2] + vsvt[2][2];
    ekf->cov[0][1] = ekf->cov[1][0] = gsgt[0][1] + vsvt[0][1];
    ekf->cov[0][2] = ekf->cov[2][0] = gsgt[0][2] + vsvt[0][2];
    ekf->cov[1][2] = ekf->cov[2][1] = gsgt[1][2] + vsvt[1][2];
}

#include <stdio.h>

void ekf_correct(ekf_t *ekf, ekf_measurement_t *m){

    ekf_dh_dstate(ekf, m);

    float sigma_ht[3][2];
    sigma_ht[0][0] = ekf->cov[0][0]*ekf->H[0][0] + ekf->cov[0][1]*ekf->H[0][1] + ekf->cov[0][2]*ekf->H[0][2];
    sigma_ht[0][1] = ekf->cov[0][0]*ekf->H[1][0] + ekf->cov[0][1]*ekf->H[1][1] + ekf->cov[0][2]*ekf->H[1][2];
    sigma_ht[1][0] = ekf->cov[1][0]*ekf->H[0][0] + ekf->cov[1][1]*ekf->H[0][1] + ekf->cov[1][2]*ekf->H[0][2];
    sigma_ht[1][1] = ekf->cov[1][0]*ekf->H[1][0] + ekf->cov[1][1]*ekf->H[1][1] + ekf->cov[1][2]*ekf->H[1][2];
    sigma_ht[2][0] = ekf->cov[2][0]*ekf->H[0][0] + ekf->cov[2][1]*ekf->H[0][1] + ekf->cov[2][2]*ekf->H[0][2];
    sigma_ht[2][1] = ekf->cov[2][0]*ekf->H[1][0] + ekf->cov[2][1]*ekf->H[1][1] + ekf->cov[2][2]*ekf->H[1][2];

    float h_sigma_ht[2][2];
    h_sigma_ht[0][0] = ekf->H[0][0]*sigma_ht[0][0] + ekf->H[0][1]*sigma_ht[1][0] + ekf->H[0][2]*sigma_ht[2][0];
    h_sigma_ht[1][1] = ekf->H[1][0]*sigma_ht[0][1] + ekf->H[1][1]*sigma_ht[1][1] + ekf->H[1][2]*sigma_ht[2][1];

    h_sigma_ht[0][1] = ekf->H[0][0]*sigma_ht[0][1] + ekf->H[0][1]*sigma_ht[1][1] + ekf->H[0][2]*sigma_ht[2][1];
    h_sigma_ht[1][0] = ekf->H[1][0]*sigma_ht[0][0] + ekf->H[1][1]*sigma_ht[1][0] + ekf->H[1][2]*sigma_ht[2][0];

    float D[2][2];
    D[0][0] = h_sigma_ht[0][0] + ekf->Q[0][0];
    D[0][1] = h_sigma_ht[0][1] + ekf->Q[0][1];
    D[1][0] = h_sigma_ht[1][0] + ekf->Q[1][0];
    D[1][1] = h_sigma_ht[1][1] + ekf->Q[1][1];
    printf("D: %f %f %f %f\r\n", D[0][0], D[0][1], D[1][0], D[1][1]);

    float detD_inv = 1.0f/(D[0][0]*D[1][1] - D[1][0]*D[1][1]);
    printf("detD_inv: %f\r\n", detD_inv);
    
    float D_inv[2][2];
    D_inv[0][0] = D[1][1]*detD_inv;
    D_inv[1][1] = D[0][0]*detD_inv;
    D_inv[0][1] = -D[0][1]*detD_inv;
    D_inv[1][0] = -D[1][0]*detD_inv;
    printf("D: %f %f %f %f\r\n", D_inv[0][0], D_inv[0][1], D_inv[1][0], D_inv[1][1]);

    float K[3][2];
    K[0][0] = sigma_ht[0][0]*D_inv[0][0] + sigma_ht[0][1]*D_inv[1][0];
    K[0][1] = sigma_ht[0][0]*D_inv[0][1] + sigma_ht[0][1]*D_inv[1][1];
    K[1][0] = sigma_ht[1][0]*D_inv[0][0] + sigma_ht[1][1]*D_inv[1][0];
    K[1][1] = sigma_ht[1][0]*D_inv[0][1] + sigma_ht[1][1]*D_inv[1][1];
    K[2][0] = sigma_ht[2][0]*D_inv[0][0] + sigma_ht[2][1]*D_inv[1][0];
    K[2][1] = sigma_ht[2][0]*D_inv[0][1] + sigma_ht[2][1]*D_inv[1][1];
    printf("K: %f %f %f %f %f %f\r\n", K[0][0], K[0][1], K[1][0], K[1][1], K[2][0], K[2][1]);

    ekf_h(ekf, m);
    float innovation[2];
    innovation[0] = m->range - ekf->h[0];
    innovation[1] = m->yaw - ekf->h[1];
    printf("yaw: %f %f\r\n", m->yaw, ekf->h[1]);
    innovation[1] = fmod(innovation[1] + M_PI, 2*M_PI) - M_PI;
    printf("innovation: %f %f\r\n", innovation[0], innovation[1]);

    ekf->x += K[0][0]*innovation[0] + K[0][1]*innovation[1];
    ekf->y += K[1][0]*innovation[0] + K[1][1]*innovation[1];
    ekf->theta += K[2][0]*innovation[0] + K[2][1]*innovation[1];

    float T[3][3];
    T[0][0] = K[0][0]*ekf->H[0][0] + K[0][1]*ekf->H[1][0];
    T[0][1] = K[0][0]*ekf->H[0][1] + K[0][1]*ekf->H[1][1];
    T[0][2] = K[0][0]*ekf->H[0][2] + K[0][1]*ekf->H[1][2];
    T[1][0] = K[1][0]*ekf->H[0][0] + K[1][1]*ekf->H[1][0];
    T[1][1] = K[1][0]*ekf->H[0][1] + K[1][1]*ekf->H[1][1];
    T[1][2] = K[1][0]*ekf->H[0][2] + K[1][1]*ekf->H[1][2];
    T[2][0] = K[2][0]*ekf->H[0][0] + K[2][1]*ekf->H[1][0];
    T[2][1] = K[2][0]*ekf->H[0][1] + K[2][1]*ekf->H[1][1];
    T[2][2] = K[2][0]*ekf->H[0][2] + K[2][1]*ekf->H[1][2];

    T[0][0] = 1 - T[0][0];
    T[1][1] = 1 - T[1][1]; 
    T[2][2] = 1 - T[2][2];
    T[0][1] = -T[0][1];
    T[0][2] = -T[0][2];
    T[1][0] = -T[1][0];
    T[1][2] = -T[1][2];
    T[2][0] = -T[2][0];
    T[2][1] = -T[2][1];

    ekf->cov[0][0] = T[0][0]*ekf->cov[0][0] + T[0][1]*ekf->cov[1][0] + T[0][2]*ekf->cov[2][0];
    ekf->cov[0][1] = T[0][0]*ekf->cov[0][1] + T[0][1]*ekf->cov[1][1] + T[0][2]*ekf->cov[2][1];
    ekf->cov[0][2] = T[0][0]*ekf->cov[0][2] + T[0][1]*ekf->cov[1][2] + T[0][2]*ekf->cov[2][2];
    ekf->cov[1][0] = T[1][0]*ekf->cov[0][0] + T[1][1]*ekf->cov[1][0] + T[1][2]*ekf->cov[2][0];
    ekf->cov[1][1] = T[1][0]*ekf->cov[0][1] + T[1][1]*ekf->cov[1][1] + T[1][2]*ekf->cov[2][1];
    ekf->cov[1][2] = T[1][0]*ekf->cov[0][2] + T[1][1]*ekf->cov[1][2] + T[1][2]*ekf->cov[2][2];
    ekf->cov[2][0] = T[2][0]*ekf->cov[0][0] + T[2][1]*ekf->cov[1][0] + T[2][2]*ekf->cov[2][0];
    ekf->cov[2][1] = T[2][0]*ekf->cov[0][1] + T[2][1]*ekf->cov[1][1] + T[2][2]*ekf->cov[2][1];
    ekf->cov[2][2] = T[2][0]*ekf->cov[0][2] + T[2][1]*ekf->cov[1][2] + T[2][2]*ekf->cov[2][2];
}

void ekf_g(ekf_t *ekf, ekf_control_t *c){
    if (c->r != c->l){
        float alpha = (c->r - c->l) / ekf->params->robot_width;
        float rad = c->l/alpha;
        ekf->x += (rad + ekf->params->robot_width/2.0f)*(sin(ekf->theta+alpha) - sin(ekf->theta));
        ekf->y += (rad + ekf->params->robot_width/2.0f)*(-cos(ekf->theta+alpha) + cos(ekf->theta));
        ekf->theta = fmod(ekf->theta + alpha + M_PI, 2*M_PI) - M_PI;
    }
    else{
        ekf->x += c->l * cos(ekf->theta);
        ekf->y += c->l * sin(ekf->theta);
    }
}

void ekf_dg_dstate(ekf_t *ekf, ekf_control_t *c){
    if (c->r != c->l){
        float alpha = (c->r-c->l)/ekf->params->robot_width;
        float theta_ = ekf->theta + alpha;
        float rpw2 = c->l/alpha + ekf->params->robot_width/2.0;
        
        ekf->G[0][2] = rpw2*(cos(theta_) - cos(ekf->theta));
        ekf->G[1][2] = rpw2*(sin(theta_) - sin(ekf->theta));
    }
    else{
        ekf->G[0][2] = -c->l*sin(ekf->theta);
        ekf->G[1][2] =  c->l*cos(ekf->theta);
    }
    printf("G: %f %f %f %f %f %f\r\n", ekf->G[0][0], ekf->G[0][1], ekf->G[1][0], ekf->G[1][1], ekf->G[2][0], ekf->G[2][1]);
}

void ekf_dg_dcontrol(ekf_t *ekf, ekf_control_t *c){
    float w = ekf->params->robot_width;
    if (fabsf(c->r > c->l) > 0.00001){
        float rml = c->r - c->l;
        float rml2 = rml * rml;
        float theta_ = ekf->theta + rml/w;
        float rpl = c->r + c->l;
        
        printf("-->: %f %f %f %f\r\n", rml, rml2, theta_, rpl);

        ekf->V[0][0] = w*c->r*(sin(theta_)-sin(ekf->theta))/rml2 - rpl*cos(theta_)/(2*rml);
        ekf->V[1][0] = w*c->r*(-cos(theta_)+cos(ekf->theta))/rml2 - rpl*sin(theta_)/(2*rml);
        ekf->V[2][0] = -1.0f/w;

        ekf->V[0][1] = (-w*c->l)/rml2*(sin(theta_)-sin(ekf->theta)) + rpl/(2*rml)*cos(theta_);
        ekf->V[1][1] = (-w*c->l)/rml2*(-cos(theta_)+cos(ekf->theta)) + rpl/(2*rml)*sin(theta_);
        ekf->V[2][1] = 1.0f/w;
    }
    else{
        ekf->V[0][0] = 0.5f*(cos(ekf->theta) + c->l/w*sin(ekf->theta));
        ekf->V[1][0] = 0.5f*(sin(ekf->theta) - c->l/w*cos(ekf->theta));
        ekf->V[2][0] = -1.0f/w;

        ekf->V[0][1] = 0.5f*(-c->l/w*sin(ekf->theta) + cos(ekf->theta));
        ekf->V[1][1] = 0.5f*(c->l/w*cos(ekf->theta) + sin(ekf->theta));
        ekf->V[2][1] = 1.0f/w;
    }
    printf("V: %f %f %f %f %f %f\r\n", ekf->V[0][0], ekf->V[0][1], ekf->V[1][0], ekf->V[1][1], ekf->V[2][0], ekf->V[2][1]);
}

void ekf_h(ekf_t *ekf, ekf_measurement_t *m){
    float dx = m->rx - (ekf->x + ekf->params->tag_polar_r* cos(ekf->theta + ekf->params->tag_polar_theta));
    float dy = m->ry - (ekf->y + ekf->params->tag_polar_r * sin(ekf->theta + ekf->params->tag_polar_theta));
    
    ekf->h[0] = sqrt(dx * dx + dy * dy);
    ekf->h[1] = ekf->theta;
}

void ekf_dh_dstate(ekf_t *ekf, ekf_measurement_t *m){
    float dx = m->rx - (ekf->x + ekf->params->tag_polar_r* cos(ekf->theta + ekf->params->tag_polar_theta));
    float dy = m->ry - (ekf->y + ekf->params->tag_polar_r * sin(ekf->theta + ekf->params->tag_polar_theta));
    float r = sqrt(dx * dx + dy * dy);

    ekf->H[0][0] = -dx / r;
    ekf->H[0][1] = -dy / r;
    ekf->H[0][2] = (dx * sin(ekf->theta + ekf->params->tag_polar_theta) - dy * cos(ekf->theta + ekf->params->tag_polar_theta)) * ekf->params->tag_polar_r / r;
    ekf->H[1][0] = ekf->H[1][1] = 0;
    ekf->H[1][2] = 1;
}
