/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_2;
    QAction *actionQuit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAbout_me;
    QAction *actionCompile;
    QAction *actionNext_Step_2;
    QAction *actionReset;
    QAction *actionHelp;
    QAction *actionRun;
    QWidget *centralwidget;
    QLabel *label;
    QTextEdit *ted_code;
    QLabel *lbl_display;
    QLabel *label_3;
    QLabel *lbl_PC;
    QLabel *label_5;
    QLabel *lbl_AC;
    QLabel *label_7;
    QLabel *lbl_IR;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *lbl_I;
    QLabel *label_13;
    QLabel *lbl_FGO;
    QLabel *label_15;
    QLabel *lbl_OUTR;
    QLabel *lbl_DR;
    QLabel *lbl_FGI;
    QLabel *lbl_OPCODE;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *lbl_E;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *lbl_AR;
    QLabel *lbl_SC;
    QLabel *lbl_INPR;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *lbl_IEN;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *lbl_TR;
    QLabel *label_16;
    QLabel *lbl_MAR;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *lbl_var;
    QLabel *lbl_SIGN;
    QLabel *label_19;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QMenu *menuCompile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 800));
        MainWindow->setMaximumSize(QSize(1200, 800));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-save-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_2->setIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-close-window-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-copy-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon2);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-paste-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon3);
        actionAbout_me = new QAction(MainWindow);
        actionAbout_me->setObjectName(QString::fromUtf8("actionAbout_me"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-administrator-male-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_me->setIcon(icon4);
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-code-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompile->setIcon(icon5);
        actionNext_Step_2 = new QAction(MainWindow);
        actionNext_Step_2->setObjectName(QString::fromUtf8("actionNext_Step_2"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-forward-button-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext_Step_2->setIcon(icon6);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-reset-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon7);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/iconss/icons8-help-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon8);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/icons/images/icons/icons8-next-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 211, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:red;\n"
""));
        ted_code = new QTextEdit(centralwidget);
        ted_code->setObjectName(QString::fromUtf8("ted_code"));
        ted_code->setGeometry(QRect(10, 50, 321, 701));
        ted_code->setFont(font);
        ted_code->setStyleSheet(QString::fromUtf8("color:blue;\n"
"background:#FFE00D;\n"
"border:3px solid #FFBC00;\n"
"border-top-right-radius: 30px;"));
        lbl_display = new QLabel(centralwidget);
        lbl_display->setObjectName(QString::fromUtf8("lbl_display"));
        lbl_display->setGeometry(QRect(340, 80, 361, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_display->setFont(font1);
        lbl_display->setStyleSheet(QString::fromUtf8("background:#5A4EFF;\n"
"color:white;\n"
"border:2px solid #0D00C7;\n"
"border-radius:10px;"));
        lbl_display->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 170, 101, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_3->setAlignment(Qt::AlignCenter);
        lbl_PC = new QLabel(centralwidget);
        lbl_PC->setObjectName(QString::fromUtf8("lbl_PC"));
        lbl_PC->setGeometry(QRect(350, 200, 101, 31));
        lbl_PC->setFont(font);
        lbl_PC->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_PC->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 170, 101, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_5->setAlignment(Qt::AlignCenter);
        lbl_AC = new QLabel(centralwidget);
        lbl_AC->setObjectName(QString::fromUtf8("lbl_AC"));
        lbl_AC->setGeometry(QRect(470, 200, 101, 31));
        lbl_AC->setFont(font);
        lbl_AC->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_AC->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(590, 170, 101, 31));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_7->setAlignment(Qt::AlignCenter);
        lbl_IR = new QLabel(centralwidget);
        lbl_IR->setObjectName(QString::fromUtf8("lbl_IR"));
        lbl_IR->setGeometry(QRect(590, 200, 101, 31));
        lbl_IR->setFont(font);
        lbl_IR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_IR->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(350, 240, 101, 31));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(350, 270, 101, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(350, 310, 101, 31));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_11->setAlignment(Qt::AlignCenter);
        lbl_I = new QLabel(centralwidget);
        lbl_I->setObjectName(QString::fromUtf8("lbl_I"));
        lbl_I->setGeometry(QRect(350, 340, 101, 31));
        lbl_I->setFont(font);
        lbl_I->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_I->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(350, 390, 101, 31));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_13->setAlignment(Qt::AlignCenter);
        lbl_FGO = new QLabel(centralwidget);
        lbl_FGO->setObjectName(QString::fromUtf8("lbl_FGO"));
        lbl_FGO->setGeometry(QRect(350, 420, 101, 31));
        lbl_FGO->setFont(font);
        lbl_FGO->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_FGO->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(350, 470, 101, 31));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_15->setAlignment(Qt::AlignCenter);
        lbl_OUTR = new QLabel(centralwidget);
        lbl_OUTR->setObjectName(QString::fromUtf8("lbl_OUTR"));
        lbl_OUTR->setGeometry(QRect(350, 500, 101, 31));
        lbl_OUTR->setFont(font);
        lbl_OUTR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_OUTR->setAlignment(Qt::AlignCenter);
        lbl_DR = new QLabel(centralwidget);
        lbl_DR->setObjectName(QString::fromUtf8("lbl_DR"));
        lbl_DR->setGeometry(QRect(470, 270, 101, 31));
        lbl_DR->setFont(font);
        lbl_DR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_DR->setAlignment(Qt::AlignCenter);
        lbl_FGI = new QLabel(centralwidget);
        lbl_FGI->setObjectName(QString::fromUtf8("lbl_FGI"));
        lbl_FGI->setGeometry(QRect(470, 420, 101, 31));
        lbl_FGI->setFont(font);
        lbl_FGI->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_FGI->setAlignment(Qt::AlignCenter);
        lbl_OPCODE = new QLabel(centralwidget);
        lbl_OPCODE->setObjectName(QString::fromUtf8("lbl_OPCODE"));
        lbl_OPCODE->setGeometry(QRect(470, 500, 101, 31));
        lbl_OPCODE->setFont(font);
        lbl_OPCODE->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_OPCODE->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(470, 310, 101, 31));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(470, 240, 101, 31));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_21->setAlignment(Qt::AlignCenter);
        lbl_E = new QLabel(centralwidget);
        lbl_E->setObjectName(QString::fromUtf8("lbl_E"));
        lbl_E->setGeometry(QRect(470, 340, 101, 31));
        lbl_E->setFont(font);
        lbl_E->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_E->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(470, 470, 101, 31));
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(470, 390, 101, 31));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_24->setAlignment(Qt::AlignCenter);
        lbl_AR = new QLabel(centralwidget);
        lbl_AR->setObjectName(QString::fromUtf8("lbl_AR"));
        lbl_AR->setGeometry(QRect(590, 270, 101, 31));
        lbl_AR->setFont(font);
        lbl_AR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_AR->setAlignment(Qt::AlignCenter);
        lbl_SC = new QLabel(centralwidget);
        lbl_SC->setObjectName(QString::fromUtf8("lbl_SC"));
        lbl_SC->setGeometry(QRect(590, 420, 101, 31));
        lbl_SC->setFont(font);
        lbl_SC->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_SC->setAlignment(Qt::AlignCenter);
        lbl_INPR = new QLabel(centralwidget);
        lbl_INPR->setObjectName(QString::fromUtf8("lbl_INPR"));
        lbl_INPR->setGeometry(QRect(590, 500, 101, 31));
        lbl_INPR->setFont(font);
        lbl_INPR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_INPR->setAlignment(Qt::AlignCenter);
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(590, 310, 101, 31));
        label_28->setFont(font);
        label_28->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_28->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(590, 240, 101, 31));
        label_29->setFont(font);
        label_29->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_29->setAlignment(Qt::AlignCenter);
        lbl_IEN = new QLabel(centralwidget);
        lbl_IEN->setObjectName(QString::fromUtf8("lbl_IEN"));
        lbl_IEN->setGeometry(QRect(590, 340, 101, 31));
        lbl_IEN->setFont(font);
        lbl_IEN->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_IEN->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(590, 470, 101, 31));
        label_31->setFont(font);
        label_31->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_31->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(centralwidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(590, 390, 101, 31));
        label_32->setFont(font);
        label_32->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_32->setAlignment(Qt::AlignCenter);
        lbl_TR = new QLabel(centralwidget);
        lbl_TR->setObjectName(QString::fromUtf8("lbl_TR"));
        lbl_TR->setGeometry(QRect(350, 570, 101, 31));
        lbl_TR->setFont(font);
        lbl_TR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_TR->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(350, 540, 101, 31));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_16->setAlignment(Qt::AlignCenter);
        lbl_MAR = new QLabel(centralwidget);
        lbl_MAR->setObjectName(QString::fromUtf8("lbl_MAR"));
        lbl_MAR->setGeometry(QRect(470, 570, 101, 31));
        lbl_MAR->setFont(font);
        lbl_MAR->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_MAR->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(470, 540, 101, 31));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(590, 540, 101, 31));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_18->setAlignment(Qt::AlignCenter);
        lbl_var = new QLabel(centralwidget);
        lbl_var->setObjectName(QString::fromUtf8("lbl_var"));
        lbl_var->setGeometry(QRect(590, 570, 101, 31));
        lbl_var->setFont(font);
        lbl_var->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_var->setAlignment(Qt::AlignCenter);
        lbl_SIGN = new QLabel(centralwidget);
        lbl_SIGN->setObjectName(QString::fromUtf8("lbl_SIGN"));
        lbl_SIGN->setGeometry(QRect(350, 640, 101, 31));
        lbl_SIGN->setFont(font);
        lbl_SIGN->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#EC4F93;"));
        lbl_SIGN->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(350, 610, 101, 31));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("color:white;\n"
"background:#B74ED7;\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;"));
        label_19->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        if (tableWidget->rowCount() < 4097)
            tableWidget->setRowCount(4097);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableWidget->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        tableWidget->setItem(0, 3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(720, 60, 431, 691));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        tableWidget->setFont(font3);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableWidget->setStyleSheet(QString::fromUtf8("border:5px solid #FF007F;\n"
"border-top-right-radius: 15px;\n"
"border-top-left-radius:15px;"));
        tableWidget->setInputMethodHints(Qt::ImhNone);
        tableWidget->setFrameShape(QFrame::WinPanel);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setWordWrap(true);
        tableWidget->setRowCount(4097);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(800, 20, 281, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background:#FF007F;\n"
"color:white;\n"
"border-radius:20px 5px 20px 5px;"));
        label_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuCompile = new QMenu(menubar);
        menuCompile->setObjectName(QString::fromUtf8("menuCompile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuCompile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionReset);
        menuAbout->addAction(actionAbout_me);
        menuCompile->addAction(actionCompile);
        menuCompile->addAction(actionNext_Step_2);
        menuCompile->addAction(actionRun);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mano Simulator", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave_2->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_me->setText(QCoreApplication::translate("MainWindow", "About me", nullptr));
        actionCompile->setText(QCoreApplication::translate("MainWindow", "Compile", nullptr));
#if QT_CONFIG(shortcut)
        actionCompile->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNext_Step_2->setText(QCoreApplication::translate("MainWindow", "Next Step", nullptr));
#if QT_CONFIG(shortcut)
        actionNext_Step_2->setShortcut(QCoreApplication::translate("MainWindow", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
#if QT_CONFIG(shortcut)
        actionHelp->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
#if QT_CONFIG(shortcut)
        actionRun->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F5", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "Write your code below....", nullptr));
        lbl_display->setText(QCoreApplication::translate("MainWindow", "pasha ahmadi", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PC", nullptr));
        lbl_PC->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        lbl_AC->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "IR", nullptr));
        lbl_IR->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "DECODE", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        lbl_I->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "FGO", nullptr));
        lbl_FGO->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "OUTR", nullptr));
        lbl_OUTR->setText(QString());
        lbl_DR->setText(QString());
        lbl_FGI->setText(QString());
        lbl_OPCODE->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "DR", nullptr));
        lbl_E->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "OPCODE", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "FGI", nullptr));
        lbl_AR->setText(QString());
        lbl_SC->setText(QString());
        lbl_INPR->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "IEN", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "AR", nullptr));
        lbl_IEN->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWindow", "INPR", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "SC", nullptr));
        lbl_TR->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "TR", nullptr));
        lbl_MAR->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "M[AR]", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "PQ", nullptr));
        lbl_var->setText(QString());
        lbl_SIGN->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "SIGN", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget->item(0, 0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "       Lablel", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->item(0, 1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "      Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(0, 2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "   Instruction", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "         Hex", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        tableWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tableWidget->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        label_2->setText(QCoreApplication::translate("MainWindow", "RANDOM ACCESS MEMEORY", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuCompile->setTitle(QCoreApplication::translate("MainWindow", "Compile", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
