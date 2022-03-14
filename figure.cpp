#include "figure.h"

Figure::Figure()
{

this->makeRandomColors();
m_x=0;
m_y=0;

}

void Figure::makeRandomColors() {
    QColor rC(255, 0, 0);
    QColor yC(255, 255, 0);
    QColor gC(0, 128, 0);
    QColor colors[3] = {rC, yC, gC};
    m_fig.clear();
    for (uint i = 0; i<3; i++){
        int r = rand()%3;
        m_fig.append(colors[r]);

        }
}
void Figure::rotateColors(direction x) {
    if (x == DOWN) {
        QColor buff = m_fig.takeLast();
        m_fig.prepend(buff);
    } else if (x == UP) {
        QColor buff = m_fig.takeFirst();
        m_fig.append(buff);
    }
}
void Figure::paintFigure(QPainter& painter) {
    uint y = m_y;
    for (uint i=0; i<3; i++) {
        QRect rect(m_x*20, y*20, 20-1, 20-1);
        QBrush brush(m_fig[i]);
        painter.fillRect(rect, brush);
        y+=1;
    }
}
