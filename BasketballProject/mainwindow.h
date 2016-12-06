#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>

#include "error\error_base.h"
#include "fisics\aspace.h"
#include "objects\parallelepiped\paral.h"
#include "line\line2d.h"
#include "objects\sphere\sphere.h"
#include "drawing\z-buffer\z-buffer.h"
#include "camera\camera.h"
#include "objects\torus\torus.h"
#include "objects\composite\composite.h"
#include "fisics/ball/ball.h"
#include "drawing/z-buffer_detachment/z-buffer_detachment.h"
#include "line/line.h"
//#include "fisics/apixel.h"
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
    camera cam;
    Z_buffer* buf;
    Z_buffer_Detachment* det;
    paral *par;
    picture _wall, _wall2, _floor, _shield;
    composite comp;
    ball *_ball;
    QPixmap map;

    void redraw();

private slots:
    void basket_draw();
    void message(const char*);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_actionRotate_triggered();

    void on_actionRotate2_triggered();

    void on_actionIncline_up_triggered();

    void on_actionIncline_down_triggered();

    void on_actionScale_plus_triggered();

    void on_actionScale_minus_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
