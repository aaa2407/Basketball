#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "error\error_base.h"
#include "drawing\drawing_frame\drawingframe.h"
#include "drawing\drawing_shading\drawing_shading.h"
#include "fisics\aspace.h"
#include "objects\parallelepiped\paral.h"
#include "line\line2d.h"
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
    drawingShading *draw;
    paral _paral;
    picture _picture, _floor;
    aspace space;

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
