QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    globals.cpp \
    level/chunk.cpp \
    level/entity.cpp \
    level/layer.cpp \
    level/level.cpp \
    main.cpp \
    resources.cpp \
    widgets/canvas.cpp \
    widgets/window.cpp

HEADERS += \
    globals.h \
    level/chunk.h \
    level/entity.h \
    level/layer.h \
    level/level.h \
    macros.h \
    resources.h \
    widgets/canvas.h \
    widgets/window.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Load SFML-2.5.1 lib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML-2.5.1/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML-2.5.1/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
else:unix: LIBS += -L$$PWD/SFML-2.5.1/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/SFML-2.5.1/include
DEPENDPATH += $$PWD/SFML-2.5.1/include

RESOURCES += \
    res.qrc
