#include "trajectory_utils.h"

QScatterDataArray to_scatter_data_array(QVector<trajectory_point_2d_t> trajectory){
    QScatterDataArray data_array;
    for (trajectory_point_2d_t point : trajectory){
        data_array << QVector3D(point.x, point.y, 0.0f);
    }
    return data_array;
}
