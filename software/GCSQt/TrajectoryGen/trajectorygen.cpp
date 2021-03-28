#include "trajectorygen.h"

QVector<trajectory_point_2d_t> lemniscate_2d(float cx, float cy, float a,  int size){
    QVector<trajectory_point_2d_t> trajectory;
    float step = 2*M_PI/size;
    for(int i=0; i<size; i++){
        trajectory_point_2d_t point;
        float t = i*step;
        point.x = cx + a*cos(t)/(1+sin(t)*sin(t));
        point.y = cy + a*sin(t)*cos(t)/(1+sin(t)*sin(t));
        trajectory.append(point);
    }
    return trajectory;
}


QVector<trajectory_point_2d_t> circle_2d(float cx, float cy, float r,  int size){
    QVector<trajectory_point_2d_t> trajectory;
    float step = 2*M_PI/size;
    for(int i=0; i<size; i++){
        trajectory_point_2d_t point;
        float t = i*step;
        point.x = cx + r*cos(t);
        point.y = cy + r*sin(t);
        trajectory.append(point);
    }
    return trajectory;
}
