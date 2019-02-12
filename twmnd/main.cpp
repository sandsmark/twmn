#include <QApplication>
#include <QTextCodec>
#include <QtGlobal>
#include <QLocale>
#include <QLibraryInfo>
#include <QTranslator>
#include "widget.h"
#include "xcb/xcb.h"
#include "dbusinterface.h"
#include <iostream>


#ifndef VERSION
#define VERSION "1.2"
#endif

int main(int argc, char *argv[])
{
    std::cout << "Starting twmnd version " << VERSION << std::endl;
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(true);
    QApplication::setApplicationName("twmn");
    QPalette p = a.palette();
    p.setBrush(QPalette::Link, QBrush(QColor("black")));
    a.setPalette(p);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    const char* wname = "twmn";
    if (argc > 1) {
      wname = argv[1];
    }
    DBusInterface dbus(&a);
    Widget w(wname);
    w.connectToDBus(dbus);
    return a.exec();
}
