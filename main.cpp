#include "mainwindow.h"
#include "settings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings::S();
    a.setWindowIcon(QIcon(Settings::get("path_to_image")));
    Browser w;
    w.show();

    return a.exec();
}
