QT += core gui
QT += network
QT += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Disable deprecated APIs before Qt 6.0.0
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    dashboard.cpp \
    datadisplay1.cpp \
    datadisplaywindow.cpp \
    datadisplaywindow1.cpp \
    deletedata.cpp \
    inward.cpp \
    inward_data_option.cpp \
    main.cpp \
    mainwindow.cpp \
    outward.cpp \
    outward_data_option.cpp \
    reportgen.cpp \
    update.cpp

HEADERS += \
    dashboard.h \
    datadisplay1.h \
    datadisplaywindow.h \
    datadisplaywindow1.h \
    deletedata.h \
    inward.h \
    inward_data_option.h \
    mainwindow.h \
    outward.h \
    outward_data_option.h \
    reportgen.h \
    update.h

FORMS += \
    dashboard.ui \
    datadisplay1.ui \
    datadisplaywindow.ui \
    datadisplaywindow1.ui \
    deletedata.ui \
    inward.ui \
    inward_data_option.ui \
    mainwindow.ui \
    outward.ui \
    outward_data_option.ui \
    reportgen.ui \
    update.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libs/build-SKQtFirebase-Desktop_Qt_6_7_0_MSVC2019_64bit-Release/SKQtFirebase/release/ -lSKQtFirebase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libs/build-SKQtFirebase-Desktop_Qt_6_7_0_MSVC2019_64bit-Release/SKQtFirebase/debug/ -lSKQtFirebase

INCLUDEPATH += $$PWD/../../Libs/SKQtFirebase-main/SKQtFirebase
DEPENDPATH += $$PWD/../../Libs/SKQtFirebase-main/SKQtFirebase
