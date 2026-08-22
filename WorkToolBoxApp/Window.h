#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>


class QPushButton;
class CalculatorWindow;

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget* parent = nullptr);

private slots:
    void openCalculator();

private:
    QPushButton* button;
    CalculatorWindow* calculatorWindow = nullptr;
};

#endif