#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"

class NextFigure : public QWidget
{
    Q_OBJECT
    Figure* fig;
public:
    explicit NextFigure(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*event);
signals:

public slots:
    void slotChangePattern(Figure *pfig) {fig = pfig; this->repaint();};

};

#endif // NEXTFIGURE_H
