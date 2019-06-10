QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    proto_out/addressbook.pb.cc

RESOURCES += qml.qrc

#add google protobuf src
#you can bulid .proto like:
#    protoc.exe path has been set environment
#    D:\QtProject\qmlStudy\Protobuf\proto_data> protoc .\addressbook.proto --cpp_out=..\proto_out
# proto is 3.8.0
## buld err
LIBS += -L./lib -Ilibprotobuf
LIBS += -L./lib -Ilibprotobuf-lite
LIBS += -L./lib -Ilibprotocompiler


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    proto_data/addressbook.proto

HEADERS += \
    proto_out/addressbook.pb.h

