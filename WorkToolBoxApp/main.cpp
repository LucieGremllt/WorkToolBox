#include "WorkToolBoxApp.h"
#include "Window.h"
#include <QtWidgets/QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Window window;
    QWidget window;
    window.setGeometry(0,0,1400, 600);

    QPushButton button("Calculator", &window);
    button.setText("Calculator");
    button.setToolTip("A tooltip");
    button.setGeometry(10, 10, 200, 40);
    window.show();

    return app.exec();
}
