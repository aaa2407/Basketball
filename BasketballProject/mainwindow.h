#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "error\error_base.h"
#include "drawing\drawing_frame\drawingframe.h"
#include "fisics\aspace.h"
#include "objects\parallelepiped\paral.h"
using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGraphicsScene *scene;
    drawingFrame *draw;
    paral _paral;
    void keyPressEvent(QKeyEvent *event);

    aspace space;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
