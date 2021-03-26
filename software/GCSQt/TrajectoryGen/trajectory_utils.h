#ifndef TRAJECTORY_UTILS_H
#define TRAJECTORY_UTILS_H

#include <QtDataVisualization>

#include "trajectorygen.h"

using namespace QtDataVisualization;

QScatterDataArray to_scatter_data_array(QVector<trajectory_point_2d_t> trajectory);

#endif // UTILS_H
