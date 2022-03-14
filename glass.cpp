#include "glass.h"
#include <QDebug>
Glass::Glass(QWidget *parent) : QWidget(parent)
{
    gameOn = 0;
    score = 0;

}
Glass::~Glass() {
  delete cur;
  delete next;
}

void Glass::glassInit() {
    m_glassArray.resize(m_rows);
    for (uint i=0; i<m_rows;i++)
    {
        m_glassArray[i].resize(m_columns);
    };
     QSize s(W*m_columns, W*m_rows);
     this->setFixedSize(s);
     this->glassClear();
}

void Glass::glassClear() {
    for (uint i=0; i<m_rows;i++)
    {
        m_glassArray[i].fill(emptyCell);
    };
    cur = new Figure();
    next = new Figure();

}

void Glass::paintEvent(QPaintEvent*event)
{

QPainter painter(this);
double x = 0.0;
double y = 0.0;
for (uint i_c=0; i_c<m_columns;i_c++) {
    for (uint i_r=0; i_r<m_rows; i_r++) {
        QRect rect(x, y, W-1, W-1);
        //qDebug()<<rect;
        QBrush brush(m_glassArray[i_r][i_c]);
        painter.fillRect(rect, brush);
        y+=W;
    }
    x+=W;
    y=0.0;

}
if (gameOn) {cur->paintFigure(painter);};
}
void Glass::acceptColors(int x, int y) {
    m_glassArray[y][x]=cur->getColor(2);
    m_glassArray[y-1][x]=cur->getColor(1);
    m_glassArray[y-2][x]=cur->getColor(0);
    std::swap(cur,next);
    cur->setX(m_columns/2);
    cur->setY(0);
    next->setX(0);
    next->setY(0);
    next->makeRandomColors();
    emit signalChangePattern(next);
}
void Glass::keyPressEvent(QKeyEvent*event) {
    if (gameOn) {
        switch(event->key()){
        case Qt::Key_Left:
        if ((cur->getX()) && ((m_glassArray[cur->getYUp()][cur->getX()-1] == emptyCell) && (m_glassArray[cur->getYUp()+1][cur->getX()-1] == emptyCell) && (m_glassArray[cur->getYBot()][cur->getX()-1] == emptyCell))) {cur->setX(cur->getX()-1);}
        break;
        case Qt::Key_Right:
        if ((cur->getX()<(m_columns-1)) && ((m_glassArray[cur->getYUp()][cur->getX()+1] == emptyCell) && (m_glassArray[cur->getYUp()+1][cur->getX()+1] == emptyCell) && (m_glassArray[cur->getYBot()][cur->getX()+1] == emptyCell))) {cur->setX(cur->getX()+1);}
        break;
        case Qt::Key_Down:
        cur->rotateColors(DOWN);
        break;
        case Qt::Key_Up:
        cur->rotateColors(UP);
        break;
        case Qt::Key_Space:
           while ((m_glassArray[cur->getYBot()+1][cur->getX()] ==emptyCell) && (cur->getYBot()<(m_rows-1))) {
                cur->setY(cur->getYUp()+1);
                if (cur->getYBot() == (m_rows-1)) {break;}
            }

        break;
        default:
        QWidget::keyPressEvent(event);
        }} else{
        QWidget::keyPressEvent(event);

        }
    this->repaint();
        }
void Glass::timerEvent(QTimerEvent*event) {
    this->repaint();
    uint y = cur->getYBot();

    if (m_glassArray[cur->getYBot()][cur->getX()] != emptyCell) {
        killTimer(idTimer);
        QMessageBox msgBox;
        msgBox.setText("Игра окончена");
        msgBox.exec();
        gameOn = 0;
    }
    if (y==(m_rows-1)) {this->acceptColors(cur->getX(), cur->getYBot());} else if (m_glassArray[y+1][cur->getX()] != emptyCell)
    {this->acceptColors(cur->getX(), cur->getYBot());};
    cur->setY(cur->getYUp()+1);

}
//void Glass::signalChangePattern(Figure* next) {

//}


