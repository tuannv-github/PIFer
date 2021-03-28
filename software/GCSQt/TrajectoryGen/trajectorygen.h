#ifndef TRAJECTORYGEN_H
#define TRAJECTORYGEN_H

#include <math.h>
#include <QVector>

typedef struct{
    float x;
    float y;
}trajectory_point_2d_t;

QVector<trajectory_point_2d_t> lemniscate_2d(float cx, float cy, float a,  int size);
QVector<trajectory_point_2d_t> circle_2d(float cx, float cy, float r,  int size);

#endif // TRAJECTORYGEN_H
