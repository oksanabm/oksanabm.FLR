#-------------------------------------------------
#
# Project created by QtCreator 2014-06-04T01:21:38
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
    DEFINES += HAVE_QT5
    contains(QT_CONFIG, dynamicgl) {
        win32-g++* {
            QMAKE_LIBS += -lopengl32
        } else {
            QMAKE_LIBS += opengl32.lib
        }
        DEFINES += USE_FORCE_GL
    } else {
        contains(QT_CONFIG, opengles.) | contains(QT_CONFIG, angle) {
            error("This program requires Qt to be configured with -opengl desktop (recommended) or -opengl dynamic")
        }
    }
}

TARGET = method
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        ourClass.cpp \
        cscene2dn.cpp

HEADERS  += mainwindow.h \
        ourClass.h \
        cscene2dn.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc
