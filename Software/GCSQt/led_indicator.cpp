#include "led_indicator.h"
#include <QPainter>

Led_indicator::Led_indicator(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(20, 20);
    lit = false;
    ledOnColor=Qt::green;
    ledOffColor=Qt::red;
    ledOnPattern = Qt::SolidPattern;
    ledOffPattern = Qt::SolidPattern;
    ledSize=10;
}

void Led_indicator::paintEvent(QPaintEvent *) {
  QPainter p(this);
  lit ?  p.setBrush(QBrush(ledOnColor, ledOnPattern)) : p.setBrush(QBrush(ledOffColor, ledOffPattern));
  p.drawEllipse(0,0,ledSize,ledSize);
}

void Led_indicator::switchLed_indicator() {
  lit = ! lit;
  repaint();
}
void Led_indicator::setState(bool state)
{
    lit = state;
    repaint();
}
void Led_indicator::toggle()
{
    lit = ! lit;
    repaint();
}

void Led_indicator::setOnColor(QColor onColor)
{
    ledOnColor=onColor;
    repaint();
}
void Led_indicator::setOffColor(QColor offColor)
{
    ledOffColor=offColor;
    repaint();
}
void Led_indicator::setOnPattern(Qt::BrushStyle onPattern)
{
    ledOnPattern=onPattern;
    repaint();
}
void Led_indicator::setOffPattern(Qt::BrushStyle offPattern)
{
    ledOffPattern=offPattern;
    repaint();
}
void Led_indicator::setLedSize(int size)
{
    ledSize=size;
    setFixedSize(size+10, size+10);
    repaint();
}
