#include "nextfigure.h"

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
    fig = nullptr;


}

void NextFigure::paintEvent(QPaintEvent*event) {
    if (fig != nullptr) {
            QPainter painter(this);
    uint y = 0.0;
    for (uint i=0; i<3; i++) {
        QRect rect(5.0, y*20, 20-1, 20-1);
        QBrush brush(fig->getColor(i));
        painter.fillRect(rect, brush);
        y+=1;
    }
    }
}
