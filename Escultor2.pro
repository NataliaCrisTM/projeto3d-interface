QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    prewindow.cpp \
    cutbox.cpp \
    putbox.cpp \
    cutellipsoid.cpp \
    putellipsoid.cpp \
    cutsphere.cpp \
    putsphere.cpp \
    figurageometrica.cpp \
    cutvoxel.cpp \
    putvoxel.cpp \
    voxel.cpp \
    sculptor.cpp \
    fundo.cpp \


HEADERS += \
    Acao.h \
mainwindow.h \
prewindow.h \
cutbox.h \
putbox.h \
cutellipsoid.h \
putellipsoid.h \
cutsphere.h \
putsphere.h \
figurageometrica.h \
cutvoxel.h \
putvoxel.h \
voxel.h \
sculptor.h \
fundo.h \

FORMS += \
    mainwindow.ui \
    prewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
