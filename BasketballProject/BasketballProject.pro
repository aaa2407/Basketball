#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T22:50:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BasketballProject
TEMPLATE = app

QMAKE_LFLAGS += -fopenmp

SOURCES += main.cpp\
        mainwindow.cpp \
    array/array.cpp \
    matrix/matrix.cpp \
    real_matrix/real_matrix.cpp \
    point/point.cpp \
    plane/plane.cpp \
    geom_operations/operations.cpp \
    drawing/z-buffer/z-buffer.cpp \
    polygon/polygon.cpp \
    camera/camera.cpp \
    fisics/apoint.cpp \
    fisics/aspace.cpp \
    fisics/traject.cpp \
    fisics/apolygon.cpp \
    objects/parallelepiped/paral.cpp \
    mutable_array/marray.cpp \
    rgb/rgb.cpp \
    picture/picture.cpp \
    line/line2d.cpp \
    objects/sphere/sphere.cpp \
    objects/torus/torus.cpp \
    objects/composite/composite.cpp \
    objects/object_base/object.cpp \
    fisics/ball/ball.cpp \
    drawing/z-buffer_detachment/z-buffer_detachment.cpp \
    line/line.cpp

HEADERS  += mainwindow.h \
    array/_array.h \
    array/array.h \
    array/array_base.h \
    array/error_array.h \
    array/error_array_base.h \
    error/error_base.h \
    matrix/_matrix.h \
    matrix/error_matrix.h \
    matrix/error_matrix_base.h \
    matrix/matrix.h \
    matrix/matrix_base.h \
    real_matrix/error_rmatrix.h \
    real_matrix/error_rmatrix_base.h \
    real_matrix/real_matrix.h \
    transform_matrix/transform_matrix.h \
    transform_matrix/transform_matrix_base.h \
    point/point.h \
    plane/base_plane.h \
    plane/error_plane.h \
    plane/error_plane_base.h \
    plane/plane.h \
    geom_operations/operations.h \
    drawing/z-buffer/z-buffer.h \
    drawing/z-buffer/error_z-buffer_base.h \
    drawing/z-buffer/error_z-buffer.h \
    mutable_array/marray.h \
    mutable_array/error_marray.h \
    mutable_array/error_marray_base.h \
    polygon/polygon.h \
    polygon/error_polygon.h \
    polygon/error_polygon_base.h \
    camera/base_camera.h \
    camera/camera.h \
    drawing/drawing3D/drawing3d_base.h \
    fisics/apoint.h \
    fisics/aspace.h \
    fisics/error_traject.h \
    fisics/error_traject_base.h \
    fisics/traject.h \
    fisics/apolygon.h \
    objects/parallelepiped/paral.h \
    mutable_array/error_marray_base.h \
    mutable_array/error_marray.h \
    mutable_array/marray.h \
    mutable_array/_marray.h \
    rgb/rgb.h \
    picture/picture.h \
    error/warning_base.h \
    geom_operations/warning_operations.h \
    line/line2d.h \
    line/error_line2d_base.h \
    line/error_line2d.h \
    objects/sphere/sphere.h \
    objects/object_base/object.h \
    objects/object_base/oblect_base.h \
    drawing/drawing_object.h \
    objects/torus/torus.h \
    objects/composite/composite.h \
    fisics/ball/ball.h \
    drawing/z-buffer_detachment/z-buffer_detachment.h \
    drawing/z-buffer/pixel.h \
    drawing/z-buffer_base/z_buffer_base.h \
    line/line.h \
    fisics/ball/error_ball_base.h \
    fisics/ball/error_ball.h

FORMS    += mainwindow.ui
