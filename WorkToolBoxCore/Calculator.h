#pragma once
#include <vector>
#include <string>
#include "Parser.h"

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
	double power(double nb, double expo);
	double getPrevious(int index);
	double getActual();
	void memorize();

	std::string calculate(const std::string& expression);
};

/*
* Calculate the level of each token by following the pemdas rule
*/
std::vector<Token> analyze(std::vector<Token>& expr);

/*
* Get the index of the Token that needs to be calculate first (higher level), if there is no operator, it returns -1
*/
int getFirstToken(const std::vector<Token> expr);


/*
* analyze an expression to find if parenthesis are empty or useless (a unique number between them).
* @return a vector with the index of both parenthesis of this is the case, or a vector with only -1
*/
std::vector<int> uselessParenthesis(const std::vector<Token> expr);