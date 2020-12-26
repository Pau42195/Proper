QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calt.cpp \
    cdefpro.cpp \
    clincsv.cpp \
    cmodpre.cpp \
    cpar.cpp \
    cpreg.cpp \
    cpro.cpp \
    cproind.cpp \
    creq.cpp \
    dbmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    tools.cpp

HEADERS += \
    calt.h \
    cdefpro.h \
    clincsv.h \
    cmodpre.h \
    cpar.h \
    cpreg.h \
    cpro.h \
    cproind.h \
    creq.h \
    dbmanager.h \
    mainwindow.h \
    tools.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Proper_ca_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Documentacio.txt
