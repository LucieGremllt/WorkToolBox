#pragma once

#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QWidget>
#include "Calculator.h"

class QPushButton;
class QLineEdit;

class CalculatorWindow : public QWidget
{
	Q_OBJECT
public:
	explicit CalculatorWindow(QWidget* parent = 0);
	void equalButtonClicked();
private:
	int countResults;
	QLineEdit* MainDisplay;
	QLineEdit* ResultDisplay;
	QPushButton* button0;
	QPushButton* button1;
	QPushButton* button2;
	QPushButton* button3;
	QPushButton* button4;
	QPushButton* button5;
	QPushButton* button6;
	QPushButton* button7;
	QPushButton* button8;
	QPushButton* button9;
	QPushButton* buttonDot;
	QPushButton* buttonEqual;
	QPushButton* buttonPlus;
	QPushButton* buttonMinus;
	QPushButton* buttonDiv;
	QPushButton* buttonMult;
	QPushButton* buttonReturn;
	QPushButton* ParenthesisL;
	QPushButton* ParenthesisR;
	QPushButton* ViewResults;
	Calculator calculator;
};

#endif

