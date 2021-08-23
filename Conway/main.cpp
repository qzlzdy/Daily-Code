#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w(300, 300, 3);
    w.show();
    return a.exec();
}
