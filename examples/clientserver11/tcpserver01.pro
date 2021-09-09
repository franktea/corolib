QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        tcpconfig.cpp \
        tcpconfigfile.cpp \
        tcpserver01.cpp \
        tcpservermain01.cpp \
        ../common-qt/crc.cpp \
        ../common-qt/protocolmessage.cpp \
        ../common-qt/tcpserver.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        ../common-qt/connectioninfo.h \
        tcpconfig.h \
        tcpconfigfile.h \
        connectioninfo.h \
        tcpserver01.h \
        ../common-qt/crc.h \
        ../common-qt/protocolmessage.h \
        ../common-qt/tcpserver.h

INCLUDEPATH += \
    ../common-qt \

