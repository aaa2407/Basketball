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
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionReset;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGraphicsView *gv;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(754, 502);
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
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("images/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon6);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon7);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon8);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gv = new QGraphicsView(centralWidget);
        gv->setObjectName(QStringLiteral("gv"));
        gv->setGeometry(QRect(1, 1, 711, 471));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(822, 11, 16, 16));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        statusBar->setFont(font);
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionStart);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionReset);
        mainToolBar->addAction(actionRotate2);
        mainToolBar->addAction(actionRotate);
        mainToolBar->addAction(actionIncline_up);
        mainToolBar->addAction(actionIncline_down);
        mainToolBar->addAction(actionScale_plus);
        mainToolBar->addAction(actionScale_minus);
        mainToolBar->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Rotate around counter-clockwise</p><p>Key: D</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionRotate->setShortcut(QApplication::translate("MainWindow", "D", 0));
        actionRotate2->setText(QApplication::translate("MainWindow", "Rotat", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Rotate around clockwise</p><p>Key: A</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionRotate2->setShortcut(QApplication::translate("MainWindow", "A", 0));
        actionIncline_up->setText(QApplication::translate("MainWindow", "incline_up", 0));
#ifndef QT_NO_TOOLTIP
        actionIncline_up->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Increase of incline of the camera</p><p>Key: W</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionIncline_up->setShortcut(QApplication::translate("MainWindow", "W", 0));
        actionIncline_down->setText(QApplication::translate("MainWindow", "incline_down", 0));
#ifndef QT_NO_TOOLTIP
        actionIncline_down->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Increase of incline of the camera</p><p>Key: S</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionIncline_down->setShortcut(QApplication::translate("MainWindow", "S", 0));
        actionScale_plus->setText(QApplication::translate("MainWindow", "scale_plus", 0));
#ifndef QT_NO_TOOLTIP
        actionScale_plus->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Increase</p><p>Key: +</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionScale_plus->setShortcut(QApplication::translate("MainWindow", "+", 0));
        actionScale_minus->setText(QApplication::translate("MainWindow", "scale_minus", 0));
#ifndef QT_NO_TOOLTIP
        actionScale_minus->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Decrease</p><p>Key: -</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionScale_minus->setShortcut(QApplication::translate("MainWindow", "-", 0));
        actionStart->setText(QApplication::translate("MainWindow", "start", 0));
#ifndef QT_NO_TOOLTIP
        actionStart->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>StartBack</p><p>Key: Enter</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "stop", 0));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Stop</p><p>Key: Enter</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionReset->setText(QApplication::translate("MainWindow", "reset", 0));
#ifndef QT_NO_TOOLTIP
        actionReset->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Reset</p><p>Key: C</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionHelp->setText(QApplication::translate("MainWindow", "help", 0));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("MainWindow", "Help", 0));
#endif // QT_NO_TOOLTIP
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
