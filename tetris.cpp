#include "tetris.h"
#include "ui_tetris.h"

tetris::tetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tetris)
{
    ui->setupUi(this);
    ui->cPanel->glassInit();

 }

tetris::~tetris()
{
    delete ui;
}

void tetris::on_controlsAction_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Движение фигуры: влево/вправо \nИзменение цвета: вверх/вниз \nУронить фигуру: Пробел");
    msgBox.exec();
}

