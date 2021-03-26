#include "dwa_utils.h"

QScatterDataArray to_scatter_data_array(dwa_t *dwa){
    QScatterDataArray data_array;
    for (int i=0; i<DWA_SIM_SIZE; i++){
        data_array << QVector3D(dwa->hypothesis[dwa->v_idx*dwa->w_idx][i].x, dwa->hypothesis[dwa->v_idx*dwa->w_idx][i].y, 0.0f);
    }
    return data_array;
}
