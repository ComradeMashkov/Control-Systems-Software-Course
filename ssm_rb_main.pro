QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    IPO/grav_acc.cpp \
    IPO/ipo.cpp \
    IPO/main_engine.cpp \
    IPO/runge-kutte.cpp \
    IPO/utils.cpp \
    SPO/kepler.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    IPO/grav_acc.h \
    IPO/ipo.h \
    IPO/main_engine.h \
    IPO/utils.h \
    SPO/kepler.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
