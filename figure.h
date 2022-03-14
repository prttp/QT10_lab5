#ifndef FIGURE_H
#define FIGURE_H
#include <QVector>
#include <QPainter>
enum direction {DOWN, UP};
class Figure
{
    QVector <QColor> m_fig;
    uint m_x;
    uint m_y;
    uint m_W;
public:
    Figure();
    void makeRandomColors();
    void rotateColors(direction x);
    uint getX() {return m_x;};
    uint getYUp() {return m_y;};
    uint getYBot() {return m_y+2;};
    void setX(uint x) {m_x=x;};
    void setY(uint y) {m_y=y;};
    void paintFigure(QPainter&painter);
    QColor getColor(uint i) {if (i<3) {return m_fig[i];}};

                            };

#endif // FIGURE_H
