/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "cscene2dn.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_13;
    Cscene2dn *widget;
    QLabel *label_14;
    QFrame *frame;
    QRadioButton *radioButton_12;
    QRadioButton *radioButton_13;
    QSpinBox *spinBox_7;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QLabel *label_25;
    QLabel *label_12;
    QSpinBox *spinBox_6;
    QFrame *frame_2;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_54;
    QRadioButton *radioButton_55;
    QRadioButton *radioButton_61;
    QRadioButton *radioButton_57;
    QRadioButton *radioButton_58;
    QRadioButton *radioButton_56;
    QRadioButton *radioButton_60;
    QRadioButton *radioButton_59;
    QRadioButton *radioButton_64;
    QRadioButton *radioButton_62;
    QRadioButton *radioButton_63;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QFrame *frame_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_7;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QLabel *label_17;
    QLabel *label_21;
    QLabel *label_22;
    QGroupBox *groupBox_9;
    QSpinBox *spinBox_2;
    QLabel *label_20;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_23;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_7;
    QLabel *label_64;
    QLabel *label_60;
    QLabel *label_62;
    QLabel *label_61;
    QLabel *label_63;
    QLabel *label_59;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_8;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_15;
    QGroupBox *groupBox_10;
    QGroupBox *groupBox_11;
    QSpinBox *spinBox_3;
    QLabel *label_24;
    QLabel *label_26;
    QWidget *tab_2;
    Cscene2dn *widget_2;
    QPushButton *pushButton_4;
    QLabel *label_31;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_2;
    QLabel *label_29;
    QLabel *label_30;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QSpinBox *spinBox_10;
    QLabel *label_27;
    QLabel *label_10;
    QSpinBox *spinBox_11;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QGroupBox *groupBox_12;
    QLabel *label_58;
    QLabel *label_53;
    QLabel *label_55;
    QLabel *label_57;
    QLabel *label_54;
    QLabel *label_56;
    QLabel *label_28;
    QLabel *label_32;
    QSpinBox *spinBox_4;
    QWidget *tab_3;
    QGroupBox *groupBox_6;
    QTextBrowser *textBrowser_2;
    QGroupBox *groupBox_7;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(900, 600);
        MainWindow->setMouseTracking(false);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 911, 700));
        tabWidget->setAutoFillBackground(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 420, 161, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        label_13->setFont(font);
        widget = new Cscene2dn(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(390, 120, 481, 351));
        widget->setAutoFillBackground(false);
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 440, 211, 41));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(230, 400, 111, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        radioButton_12 = new QRadioButton(frame);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));
        radioButton_12->setGeometry(QRect(20, 0, 91, 18));
        radioButton_13 = new QRadioButton(frame);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));
        radioButton_13->setGeometry(QRect(0, 20, 111, 18));
        spinBox_7 = new QSpinBox(tab);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setGeometry(QRect(280, 450, 61, 22));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 361, 341));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setMouseTracking(false);
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(340, 180, 16, 17));
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(220, 180, 111, 16));
        label_25->setFont(font);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 180, 111, 16));
        label_12->setFont(font);
        spinBox_6 = new QSpinBox(groupBox);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setGeometry(QRect(150, 180, 46, 22));
        spinBox_6->setFont(font);
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(150, 90, 201, 81));
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        radioButton_10 = new QRadioButton(frame_2);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        radioButton_10->setGeometry(QRect(10, 0, 31, 18));
        radioButton_11 = new QRadioButton(frame_2);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        radioButton_11->setGeometry(QRect(40, 0, 31, 18));
        radioButton_5 = new QRadioButton(frame_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(70, 0, 31, 18));
        radioButton_5->setFont(font);
        radioButton_6 = new QRadioButton(frame_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(100, 0, 31, 18));
        radioButton_6->setFont(font);
        radioButton_54 = new QRadioButton(frame_2);
        radioButton_54->setObjectName(QStringLiteral("radioButton_54"));
        radioButton_54->setGeometry(QRect(130, 0, 31, 18));
        radioButton_55 = new QRadioButton(frame_2);
        radioButton_55->setObjectName(QStringLiteral("radioButton_55"));
        radioButton_55->setGeometry(QRect(160, 0, 31, 18));
        radioButton_61 = new QRadioButton(frame_2);
        radioButton_61->setObjectName(QStringLiteral("radioButton_61"));
        radioButton_61->setGeometry(QRect(160, 30, 31, 18));
        radioButton_57 = new QRadioButton(frame_2);
        radioButton_57->setObjectName(QStringLiteral("radioButton_57"));
        radioButton_57->setGeometry(QRect(40, 30, 31, 18));
        radioButton_58 = new QRadioButton(frame_2);
        radioButton_58->setObjectName(QStringLiteral("radioButton_58"));
        radioButton_58->setGeometry(QRect(70, 30, 31, 18));
        radioButton_56 = new QRadioButton(frame_2);
        radioButton_56->setObjectName(QStringLiteral("radioButton_56"));
        radioButton_56->setGeometry(QRect(10, 30, 31, 18));
        radioButton_60 = new QRadioButton(frame_2);
        radioButton_60->setObjectName(QStringLiteral("radioButton_60"));
        radioButton_60->setGeometry(QRect(130, 30, 31, 18));
        radioButton_59 = new QRadioButton(frame_2);
        radioButton_59->setObjectName(QStringLiteral("radioButton_59"));
        radioButton_59->setGeometry(QRect(100, 30, 31, 18));
        radioButton_64 = new QRadioButton(frame_2);
        radioButton_64->setObjectName(QStringLiteral("radioButton_64"));
        radioButton_64->setGeometry(QRect(160, 60, 31, 18));
        radioButton_62 = new QRadioButton(frame_2);
        radioButton_62->setObjectName(QStringLiteral("radioButton_62"));
        radioButton_62->setGeometry(QRect(100, 60, 31, 18));
        radioButton_63 = new QRadioButton(frame_2);
        radioButton_63->setObjectName(QStringLiteral("radioButton_63"));
        radioButton_63->setGeometry(QRect(130, 60, 31, 18));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 81, 31));
        label_3->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 131, 16));
        label_2->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 131, 20));
        label->setFont(font);
        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(240, 50, 111, 31));
        frame_3->setFont(font);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        radioButton = new QRadioButton(frame_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 31, 18));
        radioButton->setCheckable(true);
        radioButton->setChecked(false);
        radioButton->setAutoRepeat(false);
        radioButton->setAutoExclusive(true);
        radioButton_2 = new QRadioButton(frame_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(true);
        radioButton_2->setGeometry(QRect(40, 10, 31, 18));
        radioButton_7 = new QRadioButton(frame_3);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setEnabled(true);
        radioButton_7->setGeometry(QRect(70, 10, 31, 18));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(280, 20, 61, 22));
        spinBox->setFont(font);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 310, 161, 23));
        pushButton_3->setFont(font);
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(100, 110, 51, 31));
        label_17->setFont(font);
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(100, 80, 51, 31));
        label_21->setFont(font);
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(100, 140, 51, 31));
        label_22->setFont(font);
        groupBox_9 = new QGroupBox(groupBox);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 210, 341, 91));
        QFont font2;
        font2.setPointSize(8);
        groupBox_9->setFont(font2);
        spinBox_2 = new QSpinBox(groupBox_9);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(100, 40, 42, 22));
        label_20 = new QLabel(groupBox_9);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(170, 60, 91, 20));
        label_20->setFont(font);
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(170, 30, 91, 20));
        label_19->setFont(font);
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox_9);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(270, 60, 51, 22));
        doubleSpinBox_3->setFont(font);
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_9);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(270, 30, 51, 22));
        doubleSpinBox_2->setFont(font);
        label_23 = new QLabel(groupBox_9);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 40, 81, 20));
        label_23->setFont(font);
        groupBox_9->raise();
        checkBox->raise();
        label_25->raise();
        label_12->raise();
        spinBox_6->raise();
        frame_2->raise();
        label_3->raise();
        label_2->raise();
        label->raise();
        frame_3->raise();
        spinBox->raise();
        pushButton_3->raise();
        label_17->raise();
        label_21->raise();
        label_22->raise();
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 540, 121, 23));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 500, 261, 31));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(380, 100, 501, 381));
        groupBox_4->setFont(font1);
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(60, 360, 261, 23));
        label_64 = new QLabel(tab);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(710, 530, 31, 21));
        label_64->setFont(font1);
        label_60 = new QLabel(tab);
        label_60->setObjectName(QStringLiteral("label_60"));
        label_60->setGeometry(QRect(590, 530, 101, 16));
        QFont font3;
        font3.setPointSize(9);
        label_60->setFont(font3);
        label_62 = new QLabel(tab);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setGeometry(QRect(410, 530, 21, 21));
        label_62->setFont(font1);
        label_61 = new QLabel(tab);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(430, 530, 111, 16));
        label_61->setFont(font3);
        label_63 = new QLabel(tab);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setGeometry(QRect(750, 530, 101, 16));
        label_63->setFont(font3);
        label_59 = new QLabel(tab);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(560, 530, 21, 21));
        label_59->setFont(font1);
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(310, 540, 61, 23));
        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(380, 10, 501, 81));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox_8->setFont(font4);
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 30, 231, 31));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/B.png")));
        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 10, 201, 71));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/A.png")));
        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 30, 251, 31));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resources/C.png")));
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 30, 251, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/resources/D.png")));
        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 10, 251, 61));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/resources/E.png")));
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(160, 10, 251, 61));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/resources/H.png")));
        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 20, 241, 41));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/resources/G.png")));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(160, 20, 241, 51));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/resources/F.png")));
        groupBox_10 = new QGroupBox(tab);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(380, 490, 501, 81));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        groupBox_10->setFont(font5);
        groupBox_11 = new QGroupBox(tab);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 390, 361, 101));
        spinBox_3 = new QSpinBox(tab);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(170, 540, 42, 22));
        label_24 = new QLabel(tab);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(150, 540, 21, 20));
        label_24->setFont(font);
        label_26 = new QLabel(tab);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(220, 540, 51, 20));
        label_26->setFont(font);
        tabWidget->addTab(tab, QString());
        widget->raise();
        groupBox_11->raise();
        groupBox_10->raise();
        groupBox_8->raise();
        groupBox_4->raise();
        groupBox->raise();
        label_13->raise();
        label_14->raise();
        frame->raise();
        spinBox_7->raise();
        pushButton_2->raise();
        pushButton->raise();
        pushButton_7->raise();
        label_64->raise();
        label_60->raise();
        label_62->raise();
        label_61->raise();
        label_63->raise();
        label_59->raise();
        pushButton_5->raise();
        spinBox_3->raise();
        label_24->raise();
        label_26->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        widget_2 = new Cscene2dn(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setEnabled(true);
        widget_2->setGeometry(QRect(370, 40, 501, 421));
        widget_2->setAutoFillBackground(false);
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 310, 261, 31));
        label_31 = new QLabel(tab_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(20, 360, 191, 16));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(240, 360, 91, 20));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 321, 281));
        groupBox_3->setFont(font1);
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 160, 211, 101));
        groupBox_2->setFont(font1);
        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(20, 30, 131, 16));
        label_29->setFont(font);
        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(20, 60, 151, 16));
        label_30->setFont(font);
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(180, 30, 16, 17));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(180, 60, 16, 17));
        spinBox_10 = new QSpinBox(groupBox_3);
        spinBox_10->setObjectName(QStringLiteral("spinBox_10"));
        spinBox_10->setGeometry(QRect(250, 30, 51, 22));
        spinBox_10->setFont(font);
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(20, 110, 161, 16));
        label_27->setFont(font);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 30, 121, 16));
        label_10->setFont(font);
        spinBox_11 = new QSpinBox(groupBox_3);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));
        spinBox_11->setGeometry(QRect(250, 70, 51, 22));
        spinBox_11->setFont(font);
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 70, 151, 16));
        label_18->setFont(font);
        doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(200, 110, 101, 22));
        doubleSpinBox->setFont(font);
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(360, 20, 521, 451));
        groupBox_5->setFont(font1);
        pushButton_8 = new QPushButton(tab_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(50, 430, 131, 23));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(50, 530, 271, 31));
        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(240, 480, 81, 23));
        pushButton_10 = new QPushButton(tab_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(50, 480, 181, 23));
        groupBox_12 = new QGroupBox(tab_2);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setGeometry(QRect(360, 480, 521, 81));
        groupBox_12->setFont(font5);
        label_58 = new QLabel(groupBox_12);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(380, 30, 101, 16));
        label_58->setFont(font3);
        label_53 = new QLabel(groupBox_12);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(40, 30, 21, 21));
        label_53->setFont(font1);
        label_55 = new QLabel(groupBox_12);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(60, 30, 111, 16));
        label_55->setFont(font3);
        label_57 = new QLabel(groupBox_12);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(340, 30, 31, 21));
        label_57->setFont(font1);
        label_54 = new QLabel(groupBox_12);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(220, 30, 101, 16));
        label_54->setFont(font3);
        label_56 = new QLabel(groupBox_12);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(190, 30, 21, 21));
        label_56->setFont(font1);
        label_28 = new QLabel(tab_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(190, 430, 21, 21));
        label_28->setFont(font);
        label_32 = new QLabel(tab_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(260, 430, 51, 21));
        label_32->setFont(font);
        spinBox_4 = new QSpinBox(tab_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(210, 430, 42, 22));
        tabWidget->addTab(tab_2, QString());
        groupBox_12->raise();
        groupBox_5->raise();
        groupBox_3->raise();
        widget_2->raise();
        pushButton_4->raise();
        label_31->raise();
        lineEdit->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        pushButton_6->raise();
        pushButton_10->raise();
        label_28->raise();
        label_32->raise();
        spinBox_4->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(30, 20, 411, 541));
        groupBox_6->setFont(font1);
        textBrowser_2 = new QTextBrowser(groupBox_6);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 20, 391, 511));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(480, 20, 381, 341));
        QFont font6;
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        groupBox_7->setFont(font6);
        textBrowser = new QTextBrowser(groupBox_7);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 20, 361, 311));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        label_13->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275\320\276\321\201\321\202\320\270", 0));
        label_14->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275\320\276\321\201\321\202\320\270", 0));
        radioButton_12->setText(QApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\321\213\320\265", 0));
        radioButton_13->setText(QApplication::translate("MainWindow", "\320\242\321\200\320\260\320\277\320\265\321\206\320\270\320\265\320\262\320\270\320\264\320\275\321\213\320\265", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\217 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        checkBox->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\273\321\217\321\202\321\214 \320\262\321\213\320\261\320\276\321\200\320\272\321\203", 0));
        label_12->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \321\210\321\203\320\274\320\260 (\320\262 %)", 0));
        radioButton_10->setText(QApplication::translate("MainWindow", "\320\220", 0));
        radioButton_11->setText(QApplication::translate("MainWindow", "B", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "C", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "D", 0));
        radioButton_54->setText(QApplication::translate("MainWindow", "E", 0));
        radioButton_55->setText(QApplication::translate("MainWindow", "F", 0));
        radioButton_61->setText(QApplication::translate("MainWindow", "L", 0));
        radioButton_57->setText(QApplication::translate("MainWindow", "H", 0));
        radioButton_58->setText(QApplication::translate("MainWindow", "I", 0));
        radioButton_56->setText(QApplication::translate("MainWindow", "G", 0));
        radioButton_60->setText(QApplication::translate("MainWindow", "K", 0));
        radioButton_59->setText(QApplication::translate("MainWindow", "J", 0));
        radioButton_64->setText(QApplication::translate("MainWindow", "O", 0));
        radioButton_62->setText(QApplication::translate("MainWindow", "M", 0));
        radioButton_63->setText(QApplication::translate("MainWindow", "N", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \320\277\321\200\320\260\320\262\320\270\320\273", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\204\320\260\320\272\321\202\320\276\321\200\320\276\320\262", 0));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\275\320\260\320\261\320\273\321\216\320\264\320\265\320\275\320\270\320\271", 0));
        radioButton->setText(QApplication::translate("MainWindow", "1", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "2", 0));
        radioButton_7->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        label_17->setText(QApplication::translate("MainWindow", "\320\264\320\273\321\217 2 \321\204:", 0));
        label_21->setText(QApplication::translate("MainWindow", "\320\264\320\273\321\217 1 \321\204:", 0));
        label_22->setText(QApplication::translate("MainWindow", "\320\264\320\273\321\217 3 \321\204:", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\262\320\260\321\200\321\214\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\204\320\260\320\272\321\202\320\276\321\200\320\260:", 0));
        label_20->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260", 0));
        label_19->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260", 0));
        label_23->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\204\320\260\320\272\321\202\320\276\321\200\320\260", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \321\201\320\265\321\207\320\265\320\275\320\270\321\217", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\270\321\201\320\270\320\274\320\276\321\201\321\202\321\214 \321\203(\321\205)", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\321\216", 0));
        label_64->setText(QApplication::translate("MainWindow", "MSE:", 0));
        label_60->setText(QString());
        label_62->setText(QApplication::translate("MainWindow", "R:", 0));
        label_61->setText(QString());
        label_63->setText(QString());
        label_59->setText(QApplication::translate("MainWindow", "CV:", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \320\277\321\200\320\260\320\262\320\270\320\273:", 0));
        label_6->setText(QString());
        label_5->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_16->setText(QString());
        label_11->setText(QString());
        label_15->setText(QString());
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\265\320\262", 0));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275\320\276\321\201\321\202\320\270", 0));
        label_24->setText(QApplication::translate("MainWindow", "\320\277\320\276", 0));
        label_26->setText(QApplication::translate("MainWindow", "\321\204\320\260\320\272\321\202\320\276\321\200\321\203", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\270", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\321\216", 0));
        label_31->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260 (\320\274\320\273\321\201\320\265\320\272)", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264\321\213 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270", 0));
        label_29->setText(QApplication::translate("MainWindow", "Fuzzy c-means clustering", 0));
        label_30->setText(QApplication::translate("MainWindow", "Gustafson-Kessel clustering", 0));
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        label_27->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\260 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260", 0));
        label_10->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\276\320\262", 0));
        label_18->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\275\320\265\321\207\320\265\321\202\320\272\320\276\321\201\321\202\320\270 (w)", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\263\321\200\320\265\321\201\321\201\320\270\320\276\320\275\320\275\320\260\321\217 \320\267\320\260\320\262\320\270\321\201\320\270\320\274\320\276\321\201\321\202\321\214 \320\262 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\265 \320\277\321\200\320\270\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \321\201\320\265\321\207\320\265\320\275\320\270\321\217", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \321\206\320\265\320\275\321\202\321\200\320\276\320\262 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\276\320\262", 0));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\265\320\262", 0));
        label_58->setText(QString());
        label_53->setText(QApplication::translate("MainWindow", "R:", 0));
        label_55->setText(QString());
        label_57->setText(QApplication::translate("MainWindow", "MSE:", 0));
        label_54->setText(QString());
        label_56->setText(QApplication::translate("MainWindow", "CV:", 0));
        label_28->setText(QApplication::translate("MainWindow", "\320\277\320\276", 0));
        label_32->setText(QApplication::translate("MainWindow", "\321\204\320\260\320\272\321\202\320\276\321\200\321\203", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\232\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\321\217", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\271", 0));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  1. <span style=\" font-weight:400;\">\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\216 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \321\201\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202"
                        "\321\214 \320\275\320\260\320\261\320\273\321\216\320\264\320\265\320\275\320\270\321\217. \320\237\321\200\320\270 \320\267\320\260\320\277\321\203\321\201\320\272\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\276\321\202\320\272\321\200\321\213\320\262\320\260\320\265\321\202\321\201\321\217 \320\277\320\265\321\200\320\262\320\260\321\217 \320\262\320\272\320\273\320\260\320\264\320\272\320\260 &quot;</span>\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\270&quot;<span style=\" font-weight:400;\">. \320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 \320\264\320\276\320\273\320\266\320\265\320\275 \320\262\321\213\320\261\321\200\320\260\321\202\321\214:</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p"
                        ">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-   \320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\275\320\260\320\261\320\273\321\216\320\264\320\265\320\275\320\270\320\271<span style=\" font-weight:400;\"> (\320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274 500);</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\204\320\260\320\272\321\202\320\276\321\200\320\276\320\262<span style=\" font-weight:400;\"> \320\262 \320\274\320\276\320\264\320\265\320\273\320\270 1, 2 \320\270\320\273\320\270 3;</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \320\236\320\261\320\275\320"
                        "\276\320\262\320\273\321\217\321\202\321\214 \320\262\321\213\320\261\320\276\321\200\320\272\321\203 <span style=\" font-weight:400;\">- \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\204\320\273\320\260\320\263 \320\276 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 \320\275\320\276\320\262\320\276\320\263\320\276 \320\275\320\260\320\261\320\276\321\200\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\277\320\276 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\201\320\270\321\201\321\202\320\265\320\274\320\265 \320\277\321\200\320\260\320\262\320\270\320\273;</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-   \320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\262\320\260\321\200\321\214\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321"
                        "\204\320\260\320\272\321\202\320\276\321\200\320\260;</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      <span style=\" font-weight:400;\">\320\237\320\276\321\201\320\273\320\265 \321\215\321\202\320\276\320\263\320\276 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 &quot;</span>\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265<span style=\" font-weight:400;\">&quot; \320\277\321\200\320\276\320\270\321\201\321\205\320\276\320\264\320\270\321\202 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   2. <span style=\" font-weight:400;\">\320\225\321\201\320\273\320\270 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 \321\203\321\201\321\202\320\260\320\275\320\260\320\262\320\273\320\270\320\262\320\260\320\265\321\202 &quot;\320\263\320\260\320\273\320\276\321\207\320\272\321\203&quot; \320\262 \320\277\320\276\320\273\320\265 &quot;</span>\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270<span style=\" font-weight:400;\">&quot;, \321\202\320\276 \320\265\320\263\320\276 &quot;\320\277\320\265\321\200\320\265\320\261\321\200\320\260\321\201\321\213\320\262\320\260\320\265\321\202&quot; \320\262\320"
                        "\276 \320\262\321\202\320\276\321\200\321\203\321\216 \320\262\320\272\320\273\320\260\320\264\320\272\321\203 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 &quot;</span>\320\232\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\321\217<span style=\" font-weight:400;\">&quot;. \320\224\320\273\321\217 \320\277\321\200\320\276\321\206\320\265\320\264\321\203\321\200\321\213 \320\265\321\207\320\265\321\202\320\272\320\276\320\271 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\216 \321\202\320\260\320\272\320\266\320\265 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320"
                        "\265\321\202\321\200\321\213:</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-    \320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\276\320\262 <span style=\" font-weight:400;\">(\320\274\320\270\320\275\320\270\320\274\321\203\320\274 2);</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-    \320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\275\320\265\321\207\320\265\321\202\320\272\320\276\321\201\321\202\320\270<span style=\" font-weight:400;\"> (\320\266\320\265\320\273\320\260\321\202\320\265\320\273\321\214\320\275\320\276 w=2):</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px;\">-    \320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\260 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260<span style=\" font-weight:400;\">;</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271 <span style=\" font-weight:400;\">(\321\202\320\260\320\272 \320\272\320\260\320\272 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213 \321\200\320\260\321\201\321\201\321\207\320\270\321\202\320\260\320\275\321\213 \320\275\320\260 \320\275\320\265\320\261\320\276\320\273\321\214\321\210\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320"
                        "\276 \320\275\320\260\320\261\320\273\321\216\320\264\320\265\320\275\320\270\320\271, \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 1000);</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-   <span style=\" font-weight:400;\">\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\274\320\265\321\202\320\276\320\264 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270 \320\270\320\267 \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\275\321\213\321\205 \320\264\320\262\321\203\321\205:</span> fuzzy c-means <span style=\" font-weight:400;\">\320\270\320\273\320\270"
                        "</span> \320\223\321\203\321\201\321\202\320\260\321\204\321\201\320\276\320\275\320\260-\320\232\320\265\321\201\321\201\320\265\320\273\321\217<span style=\" font-weight:400;\">.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    2.1. <span style=\" font-weight:400;\">\320\237\320\276\321\201\320\273\320\265 \320\275\320\260\320\266\320\260\321\202\320\270\321\217 \320\272\320\275\320\276\320\277\320\272\320\270 &quot;</span>\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\321\216<span style=\" font-weight:400;\">&quot; \320\267\320\260\320\277\321\203\321\201\320\272\320\260\320\265\321\202\321\201\321\217 \321"
                        "\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216\321\211\320\270\320\271 \320\274\320\276\320\264\321\203\320\273\321\214 \320\270 \320\262 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\265 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\262\321\200\320\265\320\274\321\217 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260 \320\262 \321\201\320\265\320\272\321\203\320\275\320\264\320\260\321\205. </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> </p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    2.2. <span style=\" font-weight:400;\">\320\237\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270"
                        "\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 &quot;</span>\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \320\244\320\237<span style=\" font-weight:400;\">&quot; \320\262 \320\277\321\200\320\260\320\262\320\276\320\271 \321\207\320\260\321\201\321\202\320\270 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\321\213\320\262\321\216\321\202\321\201\321\217 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\275\321\213\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275\320\276\321\201\321\202\320\270.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\">  2.3. <span style=\" font-weight:400;\">\320\225\321\201\320\273\320\270 \320\263\320\260\320\273\320\276\321\207\320\272\320\260 &quot;</span>\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270<span style=\" font-weight:400;\">&quot; \320\275\320\265 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\260, \321\202\320\276 \320\277\321\200\320\276\320\270\321\201\321\205\320\276\320\264\320\270\321\202 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\321\205 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\321\213\321\205 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275"
                        "\320\276\321\201\321\202\320\270.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    3. <span style=\" font-weight:400;\">\320\242\321\200\320\265\321\202\321\214\321\217 \320\262\320\272\320\273\320\260\320\264\320\272\320\260 &quot;</span>\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217<span style=\" font-weight:400;\">&quot; \321\203 \320\222\320\260\321\201 \320\276\321\202\320\272\321\200\321\213\321\202\320\260 \321\201\320\265\320\271\321\207\320\260\321\201 =).</span></p></body></html>", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Fuzzy logic regression 2.1</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-weight:400;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt; font-weight:400;\">June 2016</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragrap"
                        "h-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt; font-weight:400;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">  \320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\320\276\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\320\265\321\202 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \321\200\320\265\320\263\321\200\320\265\321\201\321\201\320\270\320\276\320\275\320\275\320\276\320\271 \320\267\320\260\320\262\320\270\321\201\320\270\320\274\320\276\321\201\321\202\320\270 \320\275\320\260 \320\276\321\201\320\275\320\276\320\262\320\265 \320\275\320\265\321\207\320\265\321\202\320\272\320\270"
                        "\321\205 \320\277\321\200\320\260\320\262\320\270\320\273 </span>\320\242\320\260\320\272\320\260\320\263\320\270-\320\241\321\203\320\263\320\265\320\275\320\276<span style=\" font-weight:400;\"> \321\201 \320\270\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265\320\274 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \320\277\321\200\320\270\320\275\320\260\320\264\320\273\320\265\320\266\320\275\320\276\321\201\321\202\320\270. </span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">     \320\222\320\276\320\267\320\274\320\276\320\266\320\275\320\276 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\320\265 \320\275"
                        "\320\265\321\207\320\265\321\202\320\272\320\276\320\271 \320\272\320\273\320\260\321\201\321\202\320\265\321\200\320\270\320\267\320\260\321\206\320\270\320\270 \320\264\320\260\320\275\320\275\321\213\321\205 \320\275\320\260 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\274 \321\215\321\202\320\260\320\277\320\265 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217 \320\276\320\264\320\275\320\276\320\274\320\265\321\200\320\275\321\213\321\205 \320\270 \320\274\320\275\320\276\320\263\320\276\320\274\320\265\321\200\320\275\321\213\321\205 \320\274\320\276\320\264\320\265\320\273\320\265\320\271 \320\274\320\265\321\202\320\276\320\264\320\260\320\274\320\270 </span>fuzzy c-means<span style=\" font-weight:400;\"> \320\270 </span>\320\223\321\203\321\201\321\202\320\260\321\204\321\201\320\276\320\275\320\260-\320\232\320\265\321\201\321\201\320\265\320\273\321\217<span style=\" font-weight:400;\">. </span></p>\n"
"<p align=\"justify\" style=\"-qt-paragrap"
                        "h-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">      \320\232\320\260\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\276\320\264\320\265\320\273\320\270 \320\276\321\206\320\265\320\275\320\270\320\262\320\260\320\265\321\202\321\201\321\217 \320\264\320\262\321\203\320\274\321\217 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217\320\274\320\270 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\260: cross-validation \320\270 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\264\320\265\321\202\320\265\321\200\320\274\320\270\320\275\320\260\321\206\320\270\320\270. \320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214"
                        "\320\275\320\276 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\201\321\200\320\265\320\264\320\275\320\265\320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\270\321\207\320\275\320\276\320\271 \320\276\321\210\320\270\320\261\320\272\320\270 MSE.</span></p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">Oksana Bebisheva</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">e-mail: oksanabm@mail.ru</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
