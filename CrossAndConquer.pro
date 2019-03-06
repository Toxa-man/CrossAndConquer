TEMPLATE = subdirs
SUBDIRS = client/src/client.pro \
            server/src/Server.pro \
            server_manager/src/ServerManager.pro
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
