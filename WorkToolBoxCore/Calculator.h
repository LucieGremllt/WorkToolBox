#pragma once
#include <vector>
#include <string>

/**
*	@brief Calculator class the execute all the basic calculus of a calculator and memorize some of the previous results.
*	Memorize the actual result to use it in the next calculus
*/

class Calculator {
private:
	const static int maxMemorized = 10;
	std::vector<double> previousResults;
	double actualResult;
public:
	Calculator();
	int getsizePrevious();
	double add(double nb1, double nb2);
	double substract(double nb1, double nb2);
	double multiply(double nb1, double nb2);
	double divide(double nb1, double nb2);
	double power(double nb, unsigned int expo);
	double getPrevious(int index);
	double getActual();
	void memorize();

	double evaluate(const std::string& expression);
};