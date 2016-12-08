TEMPLATE = app

QT += qml quick widgets



SOURCES += main.cpp \
    plumbing.cpp \
    framemaker.cpp \
    ../util/helpers.cpp \
    sandbox.cpp \
    anirect.cpp \
    curve.cpp \
    frame.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    plumbing.h \
    framemaker.h \
    ../util/helpers.h \
    anirect.h \
    curve.h \
    frame.h

CONFIG += c++14
