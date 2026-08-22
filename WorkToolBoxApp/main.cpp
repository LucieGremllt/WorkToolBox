#include "WorkToolBoxApp.h"
#include "Window.h"
#include <QtWidgets/QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Window window;
    window.show();

    return app.exec();
}
