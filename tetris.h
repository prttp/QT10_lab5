#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>

namespace Ui {
class tetris;
}

class tetris : public QMainWindow
{
    Q_OBJECT

public:
    explicit tetris(QWidget *parent = nullptr);
    ~tetris();

private slots:
    void on_controlsAction_triggered();

private:
    Ui::tetris *ui;
};

#endif // TETRIS_H
