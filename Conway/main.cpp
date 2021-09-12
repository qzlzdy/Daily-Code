#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w(200, 200, 4);
    w.show();
    return a.exec();
}
