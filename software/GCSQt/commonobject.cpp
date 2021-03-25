#include "commonobject.h"

CommonObject::CommonObject()
{

}

void CommonObject::setStatusBar(QStatusBar *status_bar){
    this->status_bar = status_bar;
}

void CommonObject::setCustomPlot(QVector<QCustomPlot*> custom_plot){
    this->custom_plot = custom_plot;
}

void CommonObject::setDrawingArea(QGridLayout *drawing_area){
    this->drawing_area = drawing_area;
}

QStatusBar *CommonObject::getStatusBar(){
    return status_bar;
}

QVector<QCustomPlot*> CommonObject::getCustomPlot(){
    return custom_plot;
}

QGridLayout *CommonObject::getDrawingArea(){
    return drawing_area;
}
