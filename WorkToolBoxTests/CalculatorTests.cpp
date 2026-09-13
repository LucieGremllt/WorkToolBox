#include "CalculatorTests.h"
#include "Calculator.h"
#include <cassert>
#include <iostream>

void CalculatorTests() {
	//new calculator
	Calculator calculator;
	//Verifying basics calculus methods and memorization
	assert(calculator.add(2,3) == 5);
	assert(calculator.substract(2, 3) == -1);
	assert(calculator.multiply(2, 3) == 6);
	assert(calculator.divide(2, 3) == 2.0/3.0);
	assert(calculator.power(2, 3) == 8);

	//Resolving an expression
	std::string expr = "(2^2+3)*2.5";
	assert(calculator.calculate(expr) == "17.500000");
}

