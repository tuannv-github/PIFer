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

QVector<trajectory_point_2d_t> ellipse_2d(float cx, float cy, float a, float b,  int size){
    QVector<trajectory_point_2d_t> trajectory;
    float step = 2*M_PI/size;
    for(int i=0; i<size; i++){
        trajectory_point_2d_t point;
        float t = i*step;
        point.x = cx + a*cos(t);
        point.y = cy + b*sin(t);
        trajectory.append(point);
    }
    return trajectory;
}

QVector<trajectory_point_2d_t> torpedor_2d(float cx, float cy, float a, int size){
    QVector<trajectory_point_2d_t> trajectory;
    float step = 4*M_PI/size;
    for(int i=0; i<size; i++){
        trajectory_point_2d_t point;
        float t = i*step;
        point.x = cx + a*(cos(t)+2*cos(t/2));
        point.y = cy + a*sin(t);
        trajectory.append(point);
    }
    return trajectory;
}

QVector<trajectory_point_2d_t> rect_2d(float cx, float cy, float a, float b,  int size){
    QVector<trajectory_point_2d_t> trajectory;
    int size_a = size*a/(a+b)/2;
    int size_b = size*b/(a+b)/2;
    float step;

    step = a/size_a;
    for(int i=0; i<size_a; i++){
        trajectory_point_2d_t point;
        point.x = cx - a/2 + i*step;
        point.y = cy - b/2;
        trajectory.append(point);
    }

    step = b/size_b;
    for(int i=0; i<size_b; i++){
        trajectory_point_2d_t point;
        point.x = cx + a/2;
        point.y = cy - b/2 + i*step;
        trajectory.append(point);
    }

    step = a/size_a;
    for(int i=0; i<size_a; i++){
        trajectory_point_2d_t point;
        point.x = cx + a/2 - i*step;
        point.y = cy + b/2;
        trajectory.append(point);
    }

    step = b/size_b;
    for(int i=0; i<size_b; i++){
        trajectory_point_2d_t point;
        point.x = cx - a/2;
        point.y = cy + b/2 - i*step;
        trajectory.append(point);
    }

    return trajectory;
}
