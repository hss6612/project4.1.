#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QDateTime>
using namespace std;

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}
MainWindow2::~MainWindow2()
{
    delete ui;
}

struct DATA
{
    int len;
    int num;
    int t1;
    int t2;
    vector<unsigned char> D;
};
vector<DATA> M(0),COPY(0);
void MainWindow2::on_pushButton_clicked()
{
    QString Name="";
    Name = QFileDialog::getOpenFileName(this,"Open File","","Pcap files (*.cap)");
    if(Name!="")
    {
        /////////////////////INICILIZATION/////////////////////////////
        fstream F;
        ui->label->setText(Name);
        F.open(Name.toLocal8Bit().data(),ios::in | ios::binary);
        int sme=24;
        F.seekg(sizeof(char),ios::end);
        int SIZE=F.tellp();
        F.seekg(sizeof(char),ios::beg);
        F.seekg(sizeof(char)*sme);
        PackHead PakH;
        M.clear();
        int i=1;
        ///////////////////////////////////////////////////////////
        while(sme<=SIZE)
        {
            DATA Image;
            F.read((char*)&PakH,sizeof(PackHead));
            sme+=16;
            Image.len=PakH.len;
            Image.num=i;
            Image.t1=PakH.t1;
            Image.t2=PakH.t2;
            int j=1;
            while(j<=PakH.len)
            {
                unsigned char p;
                F.read((char*)&p,sizeof(char));
                Image.D.push_back(p);
                j++;
            }
            M.push_back(Image);
            i++;
            sme+=PakH.len;
            F.seekg(sizeof(char)*sme);
        }
        M.pop_back();
        int length=M.size();
        ui->lcdNumber->display(length);
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit->setText("1");
        ui->lineEdit_2->setText(QString::number(length));
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->radioButton_2->setChecked(true);
        ui->label_6->setText("Status: Файл открыт | Пакеты отсортированы по номеру");
        on_pushButton_2_clicked();
        F.close();
    }
}

void MERGE(int a,int b)
{
    for(int i=a;i<=b;i++)
        COPY.push_back(M[i]);
}

bool Comp1(DATA A,DATA B)
{
    if(A.len==B.len)
        return A.num<B.num;
    return A.len<B.len;
}
bool Comp2(DATA A,DATA B)
{
    return A.num<B.num;
}

void MainWindow2::on_pushButton_2_clicked()
{
    int START=(ui->lineEdit->text()).toInt()-1;
    int END=(ui->lineEdit_2->text()).toInt()-1;
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    int checker=0;
    if(END>M.size())
    {
        END=M.size();
        ui->lineEdit_2->setText(QString::number(M.size()));
    }
    COPY.clear();
    MERGE(START,END);
    if(ui->radioButton->isChecked()==true)
    {
        sort(COPY.begin(),COPY.end(),Comp1);
        ui->label_6->setText("Status: Файл открыт | Пакеты отсортированы по размеру");
    }
    else
    {
        sort(COPY.begin(),COPY.end(),Comp2);
        ui->label_6->setText("Status: Файл открыт | Пакеты отсортированы по номеру");
    }
    double MED=0;
    int MAX=-1,MIN=-1;
    for(int i=0;i<(int)COPY.size();i++)
    {
        if(checker<=100)
        {
            QString INFO="";
            INFO+="Пакет №";
            INFO+=QString::number(COPY[i].num);
            INFO+=":\n\t{\n\t   Size = ";
            INFO+=QString::number(COPY[i].len);
            INFO+=" byte\n\t   Time1 = ";
            INFO+=(QDateTime::fromTime_t(COPY[i].t1)).toString();
            INFO+="\n\t   Time2 = ";
            INFO+=(QDateTime::fromTime_t(COPY[i].t2)).toString();
            INFO+="\n\t}";
            ui->textEdit->append(INFO);
            ui->textEdit->append("");
            /////////////////////////////////////////////
            INFO="";
            INFO+="Данные Пакета №";
            INFO+=QString::number(COPY[i].num);
            INFO+=":\n\t{";
            for(int j=0;j<COPY[i].D.size();j++)
            {
                if(j%16==0)
                    INFO+="\n\t";
                if(j%8==0 && j%16!=0)
                     INFO+="  ";
                QString Buf=QString::number(COPY[i].D[j],16);
                if(Buf.size()<2)
                    INFO+="0"+Buf;
                else
                    INFO+=Buf;
                INFO+=" ";
            }
            INFO+="\n\t}";
            ui->textEdit_2->append(INFO);
            ui->textEdit_2->append("");





         }
        checker++;
        MED+=COPY[i].len;
        if(MAX<COPY[i].len || MAX==-1)
           MAX=COPY[i].len;
        if(MIN>COPY[i].len || MIN==-1)
           MIN=COPY[i].len;

    }
    if(checker>100)
         ui->textEdit->append("Файл слишком велик.\nОтображены только 100 пакетов..");
    MED=MED/COPY.size();
    ui->lcdNumber_2->display(MED);
    ui->lcdNumber_3->display(MAX);
    ui->lcdNumber_4->display(MIN);
}
