#include "window.h"
#include "CalculatorWindow.h"

#include <QPushButton>

Window::Window(QWidget* parent)
    : QWidget(parent)
{
    setGeometry(0, 0, 1200, 600);

    button = new QPushButton("Calculator", this);
    button->setGeometry(10, 10, 100, 30);

    connect(button, &QPushButton::clicked, this, &Window::openCalculator);
}

void Window::openCalculator()
{
    if (calculatorWindow == nullptr)
        calculatorWindow = new CalculatorWindow(this);

    calculatorWindow->show();
    calculatorWindow->raise();
    calculatorWindow->activateWindow();
}