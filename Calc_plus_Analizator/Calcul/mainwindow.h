#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_Button0_clicked();

    void on_Point_clicked();

    void on_LScob_clicked();

    void on_RScob_clicked();

    void on_Erace_clicked();

    void on_Reset_clicked();

    void on_Mul_clicked();

    void on_Del_clicked();

    void on_Add_clicked();

    void on_Sub_clicked();

    void on_Equel_clicked();

private:
    Ui::MainWindow *ui;
};

struct FLAGS
{
     bool Zn;
     bool Cou;
     bool Rs;
     bool Ls;
     bool Poi;
     bool Poi_k;
     int scob;
     bool otr;
     FLAGS(bool z,bool c,bool rs,bool ls,bool p1,bool p2,int sk,bool ot)
     {
         Zn=z; Cou=c; Rs=rs; Ls=ls; Poi=p1; Poi_k=p2; scob=sk; otr=ot;
     }
};

QString calcul(std::string s);
#endif // MAINWINDOW_H
