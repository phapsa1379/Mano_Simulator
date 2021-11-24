#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QHash>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString hexToBin(QString hexnum);
    int hexToDec(QString hexnum);
    QString decToHex(int decnum);










private slots:




    void on_actionReset_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_me_triggered();

    void on_actionSave_2_triggered();

    void on_actionCompile_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
