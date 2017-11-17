#include "mainwindowgeneral.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindowgeneral.h"
#include <QMessageBox>
MainWindowGeneral::MainWindowGeneral(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGeneral)
{
    ui->setupUi(this);
}

MainWindowGeneral::~MainWindowGeneral()
{
    delete ui;
}

void MainWindowGeneral::on_actionExit_triggered()
{
    exit(0);
}
void MainWindowGeneral::on_actionStart_Calculator_triggered()
{
    MainWindow *F= new MainWindow;
    F->show();
    //this->setEnabled(false);
}
void MainWindowGeneral::on_actionWorking_with_Pcap_file_triggered()
{
     MainWindow2 *F2 = new MainWindow2;
     F2->show();
     //this->setEnabled(false);
}

void  MainWindowGeneral::on_action_triggered()
{
    QMessageBox::information(this,"Справка","\t1)Калькулятор вычисляет операции +-*/ и скобки.\n\t2)Анализатор открывает файлы *.cap и отображает пакеты и их свойства\n\tПрограммы запускаются из главного меню или через кнопки вызова на главном экране");
}

void MainWindowGeneral::on_pushButton_clicked()
{
    on_actionStart_Calculator_triggered();
}

void MainWindowGeneral::on_pushButton_2_clicked()
{
    on_actionWorking_with_Pcap_file_triggered();
}
