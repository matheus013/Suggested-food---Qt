QT += core sql
QT -= gui

CONFIG += c++11

TARGET = TopTen-IA
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    geneticsuggestion.cpp \
    model.cpp \
    bd/connection.cpp \
    bd/daobject.cpp \
    bd/tablemanagement.cpp \
    geneticpreferences.cpp \
    food.cpp \
    mathutil.cpp

HEADERS += \
    geneticsuggestion.h \
    model.h \
    bd/connection.h \
    bd/daobject.h \
    bd/tablemanagement.h \
    geneticpreferences.h \
    food.h \
    mathutil.h
