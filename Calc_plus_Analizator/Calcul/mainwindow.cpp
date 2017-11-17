#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <iostream>
#include <QMessageBox>
#include <unistd.h>
using namespace std;
QString S="";
FLAGS   F(false,true,false,true,false,true,0,true);
vector<FLAGS> STACK;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button1_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="1";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button2_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="2";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button3_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="3";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button4_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="4";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button5_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="5";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button6_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="6";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button7_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="7";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button8_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="8";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button9_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="9";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Button0_clicked()
{
    if(F.Cou==true)
    {
        STACK.push_back(F);
        F.Ls=false;
        F.otr=false;
        F.Poi=true;
        F.Rs=true;
        F.Zn=true;
        S+="0";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Point_clicked()
{
    if(F.Poi==true && F.Poi_k==true)
    {
        STACK.push_back(F);
        F.Poi_k=false;
        F.Cou=true;
        F.Ls=false;
        F.Rs=false;
        F.otr=false;
        F.Zn=false;
        F.Poi=false;
        S+=".";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_LScob_clicked()
{
    if(F.Ls==true)
    {
        STACK.push_back(F);
        F.Cou=true;
        F.Rs=false;
        F.Ls=true;
        F.otr=true;
        F.Poi_k=true;
        F.Poi=false;
        F.scob++;
        F.Zn=false;
        S+="(";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_RScob_clicked()
{
    if(F.Rs==true && F.scob>0)
    {
        STACK.push_back(F);
        F.Cou=false;
        F.Rs=true;
        F.Ls=false;
        F.otr=false;
        F.Poi_k=true;
        F.Poi=false;
        F.scob--;
        F.Zn=true;
        S+=")";
        ui->label->setText("");
        ui->Pole->setText(S);
    }

}

void MainWindow::on_Erace_clicked()
{
    if(STACK.size()!=0)
    {
        F=STACK.back();
        STACK.pop_back();
        S.chop(1);
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Reset_clicked()
{
        F.Cou=true;
        F.Rs=false;
        F.Ls=true;
        F.otr=true;
        F.Poi_k=true;
        F.Poi=false;
        F.scob=0;
        F.Zn=false;
        STACK.clear();
        S="";
        ui->label->setText("");
        ui->Pole->setText(S);
}

void MainWindow::on_Mul_clicked()
{
    if(F.Zn==true)
    {
        STACK.push_back(F);
        F.Cou=true;
        F.Rs=false;
        F.Ls=true;
        F.otr=false;
        F.Poi_k=true;
        F.Poi=false;
        F.Zn=false;
        S+="*";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Del_clicked()
{
    if(F.Zn==true)
    {
        STACK.push_back(F);
        F.Cou=true;
        F.Rs=false;
        F.Ls=true;
        F.otr=false;
        F.Poi_k=true;
        F.Poi=false;
        F.Zn=false;
        S+="/";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Add_clicked()
{
    if(F.Zn==true)
    {
        STACK.push_back(F);
        F.Cou=true;
        F.Rs=false;
        F.otr=false;
        F.Ls=true;
        F.Poi_k=true;
        F.Poi=false;
        F.Zn=false;
        S+="+";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Sub_clicked()
{
    if(F.Zn==true || F.otr==true)
    {
        STACK.push_back(F);
        F.Cou=true;
        F.Rs=false;
        F.Ls=true;
        F.otr=false;
        F.Poi_k=true;
        F.Poi=false;
        F.Zn=false;
        S+="-";
        ui->label->setText("");
        ui->Pole->setText(S);
    }
}

void MainWindow::on_Equel_clicked()
{
        ui->label->setText(S+="=");
        string str="";
        str = std::string(S.toLocal8Bit().data());
        S=calcul(str);
        if(F.scob==0)
        {
            if(S=="Error")
            {
                QMessageBox::warning(this,"Ошибка!","Деление на нуль!");
                S="";
                ui->label->setText(S+="");
                ui->Pole->setText(S);
                F.Cou=true;
                F.Rs=false;
                F.Ls=true;
                F.otr=true;
                F.Poi_k=true;
                F.Poi=false;
                F.scob=0;
                F.Zn=false;
                STACK.clear();
            }
            else
            {
                ui->Pole->setText(S);
                F.Cou=false;
                F.Rs=false;
                F.Ls=false;
                F.otr=false;
                F.Poi_k=true;
                F.Poi=false;
                F.scob=0;
                F.Zn=true;
                STACK.clear();
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка!","Неверно расставлены скобки!");
            S="";
            ui->label->setText(S+="");
            ui->Pole->setText(S);
            F.Cou=true;
            F.Rs=false;
            F.Ls=true;
            F.otr=true;
            F.Poi_k=true;
            F.Poi=false;
            F.scob=0;
            F.Zn=false;
            STACK.clear();
        }
}
