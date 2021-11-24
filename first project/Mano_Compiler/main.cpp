#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //MainWindow.setFixedSize(width(), height());
    w.show();
    return a.exec();
}
