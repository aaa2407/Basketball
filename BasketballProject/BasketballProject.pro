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
    real_matrix/real_matrix.cpp

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
    transform_matrix/transform_matrix_base.h

FORMS    += mainwindow.ui
