QT += core
QT -= gui

CONFIG += c++11

TARGET = server_Qt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bcm2835_stub.cpp \
    pin.cpp \
    pwm.cpp \
    serial.cpp \
    spi.cpp

HEADERS += \
    bcm2835.h \
    pin.h \
    pwm.h \
    serial.h \
    spi.h
