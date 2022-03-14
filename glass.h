#ifndef GLASS_H
#define GLASS_H
#define emptyCell       QColor(150,150,150)

#include <QWidget>
#include <QPainter>
#include "figure.h"
#include <QKeyEvent>
#include <QMessageBox>
class Glass : public QWidget
{
    Q_OBJECT
    static const uint W = 20;
    uint timerInterval;
    Q_PROPERTY(uint rows READ rows WRITE setRows)
    uint m_rows;
    Q_PROPERTY(uint columns READ columns WRITE setColumns)
    uint m_columns;
    bool gameOn;
    uint score;
    QVector<QVector <QColor>> m_glassArray;
    Figure *cur; //текущая (падающая) фигурка
    Figure *next; //образец следующей фигурки
    int idTimer;
public:
    explicit Glass(QWidget *parent = nullptr);
    ~Glass();
    void glassInit();
    void glassClear();
    void paintEvent(QPaintEvent*event);
    void acceptColors(int i, int j);
    void keyPressEvent(QKeyEvent*event);
    void timerEvent(QTimerEvent*event);
uint rows() const
{
    return m_rows;
}

uint columns() const
{
    return m_columns;
}

signals:
void signalChangePattern(Figure* next);
public slots:
void setRows(uint rows)
{
    m_rows = rows;
}
void setColumns(uint columns)
{
    m_columns = columns;
}
void slotNewGame() {
    gameOn =1;
    this->glassClear();
    cur->setX(m_columns/2);
    idTimer=this->startTimer(300);
    this->setFocus();
    emit signalChangePattern(next);
    this->repaint();
}
};


#endif // GLASS_H
