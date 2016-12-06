/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRotate;
    QAction *actionRotate2;
    QAction *actionIncline_up;
    QAction *actionIncline_down;
    QAction *actionScale_plus;
    QAction *actionScale_minus;
    QWidget *centralWidget;
    QGraphicsView *gv;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(888, 523);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        QIcon icon;
        icon.addFile(QStringLiteral("images/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon);
        actionRotate2 = new QAction(MainWindow);
        actionRotate2->setObjectName(QStringLiteral("actionRotate2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/rotate2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate2->setIcon(icon1);
        actionIncline_up = new QAction(MainWindow);
        actionIncline_up->setObjectName(QStringLiteral("actionIncline_up"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/incline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIncline_up->setIcon(icon2);
        actionIncline_down = new QAction(MainWindow);
        actionIncline_down->setObjectName(QStringLiteral("actionIncline_down"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("images/incline2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIncline_down->setIcon(icon3);
        actionScale_plus = new QAction(MainWindow);
        actionScale_plus->setObjectName(QStringLiteral("actionScale_plus"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("images/scale2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale_plus->setIcon(icon4);
        actionScale_minus = new QAction(MainWindow);
        actionScale_minus->setObjectName(QStringLiteral("actionScale_minus"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("images/scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale_minus->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gv = new QGraphicsView(centralWidget);
        gv->setObjectName(QStringLiteral("gv"));
        gv->setGeometry(QRect(10, 10, 721, 451));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(740, 10, 93, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(750, 90, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(740, 50, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(920, 110, 91, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 888, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionRotate2);
        mainToolBar->addAction(actionRotate);
        mainToolBar->addAction(actionIncline_up);
        mainToolBar->addAction(actionIncline_down);
        mainToolBar->addAction(actionScale_plus);
        mainToolBar->addAction(actionScale_minus);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", 0));
        actionRotate->setShortcut(QApplication::translate("MainWindow", "D", 0));
        actionRotate2->setText(QApplication::translate("MainWindow", "rotate2", 0));
        actionRotate2->setShortcut(QApplication::translate("MainWindow", "A", 0));
        actionIncline_up->setText(QApplication::translate("MainWindow", "incline_up", 0));
        actionIncline_up->setShortcut(QApplication::translate("MainWindow", "W", 0));
        actionIncline_down->setText(QApplication::translate("MainWindow", "incline_down", 0));
        actionIncline_down->setShortcut(QApplication::translate("MainWindow", "S", 0));
        actionScale_plus->setText(QApplication::translate("MainWindow", "scale_plus", 0));
        actionScale_plus->setShortcut(QApplication::translate("MainWindow", "+", 0));
        actionScale_minus->setText(QApplication::translate("MainWindow", "scale_minus", 0));
        actionScale_minus->setShortcut(QApplication::translate("MainWindow", "-", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\267\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
