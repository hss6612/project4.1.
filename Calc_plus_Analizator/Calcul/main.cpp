#include "mainwindow.h"
#include "mainwindow2.h"
#include "mainwindowgeneral.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowGeneral Calc;
    Calc.show();

    return a.exec();
}
