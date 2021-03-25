#ifndef COMMONOBJECT_H
#define COMMONOBJECT_H

#include <QCustomPlot/qcustomplot.h>

class CommonObject
{
public:
    CommonObject();
    QStatusBar *status_bar;
    QGridLayout *drawing_area;
    QVector<QCustomPlot*> custom_plot;

    void setStatusBar(QStatusBar *status_bar);
    void setCustomPlot(QVector<QCustomPlot*> custom_plot);
    void setDrawingArea(QGridLayout *drawing_area);

    QStatusBar *getStatusBar();
    QVector<QCustomPlot*> getCustomPlot();
    QGridLayout *getDrawingArea();
};

#endif // COMMONOBJECT_H
