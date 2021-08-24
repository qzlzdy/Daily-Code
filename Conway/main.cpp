#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w(200, 200, 4, Window::RULE124_3_3, 0.1);
    w.show();
    return a.exec();
}
