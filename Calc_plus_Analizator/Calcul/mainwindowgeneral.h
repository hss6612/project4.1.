#ifndef MAINWINDOWGENERAL_H
#define MAINWINDOWGENERAL_H

#include <QMainWindow>

namespace Ui {
class MainWindowGeneral;
}

class MainWindowGeneral : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowGeneral(QWidget *parent = 0);
    ~MainWindowGeneral();
public slots:
    void on_actionExit_triggered();
    void on_actionStart_Calculator_triggered();
    void on_action_triggered();
    void on_actionWorking_with_Pcap_file_triggered();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindowGeneral *ui;
};

#endif // MAINWINDOWGENERAL_H
