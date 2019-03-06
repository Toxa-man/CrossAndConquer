/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *xEdit;
    QLineEdit *yEdit;
    QPushButton *moveBtn;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *idEdit;
    QLabel *label_3;
    QGroupBox *groupBox;
    QRadioButton *hor;
    QRadioButton *ver;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(828, 645);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        xEdit = new QLineEdit(centralWidget);
        xEdit->setObjectName(QString::fromUtf8("xEdit"));
        xEdit->setGeometry(QRect(130, 80, 31, 21));
        yEdit = new QLineEdit(centralWidget);
        yEdit->setObjectName(QString::fromUtf8("yEdit"));
        yEdit->setGeometry(QRect(190, 80, 31, 21));
        moveBtn = new QPushButton(centralWidget);
        moveBtn->setObjectName(QString::fromUtf8("moveBtn"));
        moveBtn->setGeometry(QRect(390, 80, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 50, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 50, 47, 13));
        idEdit = new QLineEdit(centralWidget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setGeometry(QRect(60, 80, 31, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 50, 47, 13));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(250, 40, 120, 91));
        hor = new QRadioButton(groupBox);
        hor->setObjectName(QString::fromUtf8("hor"));
        hor->setGeometry(QRect(20, 30, 82, 17));
        ver = new QRadioButton(groupBox);
        ver->setObjectName(QString::fromUtf8("ver"));
        ver->setGeometry(QRect(20, 60, 82, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 828, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        moveBtn->setText(QApplication::translate("MainWindow", "move", nullptr));
        label->setText(QApplication::translate("MainWindow", "id", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y", nullptr));
        groupBox->setTitle(QString());
        hor->setText(QApplication::translate("MainWindow", "Horizontal", nullptr));
        ver->setText(QApplication::translate("MainWindow", "Vertical", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
