#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T22:50:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BasketballProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    array/array.cpp \
    matrix/matrix.cpp \
    real_matrix/real_matrix.cpp \
    point/point.cpp \
    plane/plane.cpp \
    geom_operations/operations.cpp \
    drawing/z-buffer/z-buffer.cpp \
    mutable_array/marray.cpp \
    polygon/polygon.cpp \
    camera/camera.cpp \
    drawing/drawing3D_base/drawing3d_base.cpp \
    drawing/drawing_frame/drawingframe.cpp \
    fisics/apoint.cpp \
    fisics/aspace.cpp \
    fisics/traject.cpp \
    fisics/apolygon.cpp

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
    mutable_array/_marray.h \
    mutable_array/error_marray.h \
    mutable_array/error_marray_base.h \
    polygon/polygon.h \
    polygon/error_polygon.h \
    polygon/error_polygon_base.h \
    camera/base_camera.h \
    camera/camera.h \
    drawing/drawing3D/drawing3d_base.h \
    drawing/drawing3D_base/drawing3d_base.h \
    drawing/drawing_frame/drawingframe.h \
    fisics/apoint.h \
    fisics/aspace.h \
    fisics/error_traject.h \
    fisics/error_traject_base.h \
    fisics/traject.h \
    fisics/apolygon.h

FORMS    += mainwindow.ui
