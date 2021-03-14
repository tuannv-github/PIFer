#ifndef Led_indicator_H
#define Led_indicator_H

#include <QWidget>

class Led_indicator: public QWidget {
    Q_OBJECT
  public:
    Led_indicator(QWidget *parent = 0);
    void setState(bool state);
    void toggle();
    void setOnColor(QColor onColor);
    void setOffColor(QColor offColor);
    void setOnPattern(Qt::BrushStyle onPattern);
    void setOffPattern(Qt::BrushStyle offPattern);
    void setLedSize(int size);

  public slots:
    void switchLed_indicator();
  protected:
    void paintEvent(QPaintEvent *);
  private:
    bool lit;
    QColor ledOnColor;
    QColor ledOffColor;
    Qt::BrushStyle ledOnPattern;
    Qt::BrushStyle ledOffPattern;
    int ledSize;
};

#endif // Led_indicator_H

