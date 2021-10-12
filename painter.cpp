#include "display.h"
#include <QApplication>
#include <QThread>
#include <boost/thread.hpp>
#include "contactor.h"
#include <QPainter>
#include <QPainterPath>


void Display::paintEvent(Color color, double x, double y, std::size_t){
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    switch(t){
    case

    }

    QPainterPath path;
    path.addRoundedRect(QRectF(80, 120, 200, 100), 10, 10);
    QPen pen(Qt::black, 2);
    p.setPen(pen);
    p.fillPath(path, Qt::white);
    p.drawPath(path);
}

