#include "CalculatorTests.h"
#include "Calculator.h"
#include <cassert>

void CalculatorTests() {
	//new calculator
	Calculator calculator;
	//Verifying basics calculus methods and memorization
	assert(calculator.add(2,3) == 5);
	calculator.memorize();
	assert(calculator.substract(2, 3) == -1);
	calculator.memorize();
	assert(calculator.multiply(2, 3) == 6);
	calculator.memorize();
	assert(calculator.divide(2, 3) == 2.0/3.0);
	calculator.memorize();
	assert(calculator.power(2, 3) == 8);
	calculator.memorize();
	assert(calculator.getActual() == 8);
	//completing the vertor to reach the max capacity
	calculator.add(2, 3);
	calculator.memorize();
	calculator.substract(2, 3);
	calculator.memorize();
	calculator.multiply(2, 3);
	calculator.memorize();
	calculator.divide(2, 3);
	calculator.memorize();
	calculator.power(2, 3);
	calculator.memorize();
	//Verifying that the first to be memorized is also the fist to be erased and that the next one takes it's place
	assert(calculator.getPrevious(0) == 5);
	calculator.add(2, 3);
	calculator.memorize();
	assert(calculator.getPrevious(0) == -1);

}

