#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"jobschedule.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayJobs();
    void FCFS();               //先来先服务算法
    void SJF();                //短进程优先算法
    void HRRN();               //高响应比优先算法


private slots:
    void on_addJobBtn_clicked();

    void on_FCFSBtn_clicked();

    void on_addRandBtn_clicked();

    void on_SJFBtn_clicked();

    void on_HRRNBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
