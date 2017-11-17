#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include <QFileDialog>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <QMainWindow>
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow2 *ui;
};

struct PackHead {
    unsigned long t1;
    unsigned long t2;
    unsigned int caplen;
    unsigned int len;
};

#endif // MAINWINDOW2_H
