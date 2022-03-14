#include "tetris.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tetris w;
    w.show();

    return a.exec();
}
