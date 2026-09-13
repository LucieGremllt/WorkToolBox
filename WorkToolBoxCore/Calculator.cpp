#include "Calculator.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

Calculator::Calculator() {
	actualResult = NULL;
}
double Calculator::add(double nb1, double nb2) {
	actualResult = nb1 + nb2;
	return actualResult;
}
double Calculator::substract(double nb1, double nb2) {
	actualResult = nb1 - nb2;
	return actualResult;
}
double Calculator::multiply(double nb1, double nb2) {
	actualResult = nb1 * nb2;
	return actualResult;
}
double Calculator::divide(double nb1, double nb2) {
	assert(nb2 >= 0);
	actualResult = nb1 / nb2;
	return actualResult;
}
double Calculator::power(double nb, double expo) {
	assert(expo > 0);
	actualResult = pow(nb, expo);
	return actualResult;
}
double Calculator::getPrevious(int index) {
	assert(index >= 0);
	return previousResults[index];
}
double Calculator::getActual() {
	return actualResult;
}
void Calculator::memorize() {
	if (previousResults.size() == maxMemorized) {
		previousResults.erase(previousResults.begin());
	}
	previousResults.push_back(actualResult);
}
std::string Calculator::calculate(const std::string& expression) {
	std::vector<Token> ParsedExpr = parseExpr(expression);
	ParsedExpr = analyze(ParsedExpr);

	double result=0;
	int index;
	if (ParsedExpr.size() == 1)
		result = std::stod(ParsedExpr[0].str);
	while (ParsedExpr.size() > 1) {
		std::vector<int> e = uselessParenthesis(ParsedExpr);
		while (e.size() > 1) {
			ParsedExpr.erase(ParsedExpr.begin() + e[1]);
			ParsedExpr.erase(ParsedExpr.begin() + e[0]);
			e = uselessParenthesis(ParsedExpr);
		}
		index = getFirstToken(ParsedExpr);
		if (index > 0) {
			switch (ParsedExpr[index].type) {
			case plus:
				result = add(std::stod(ParsedExpr[index - 1].str), std::stod(ParsedExpr[index + 1].str));
				break;
			case minus:
				result = substract(std::stod(ParsedExpr[index - 1].str), std::stod(ParsedExpr[index + 1].str));
				break;
			case mult:
				result = multiply(std::stod(ParsedExpr[index - 1].str), std::stod(ParsedExpr[index + 1].str));
				break;
			case CalculusDataType::divide:
				result = divide(std::stod(ParsedExpr[index - 1].str), std::stod(ParsedExpr[index + 1].str));
				break;
			case CalculusDataType::power:
				result = power(std::stod(ParsedExpr[index - 1].str), std::stod(ParsedExpr[index + 1].str));
				break;
			}
			ParsedExpr[index - 1] = getToken(std::to_string(result));
			ParsedExpr.erase(ParsedExpr.begin() + index);
			ParsedExpr.erase(ParsedExpr.begin() + index);
		}
	}
	return ParsedExpr[0].str;
}

std::vector<Token> analyze(std::vector<Token>& expr) {
	int LevelCounter = 0;
	for (int i = 0; i < expr.size(); i++) {
		switch (expr[i].type) {
		case lparenthesis:
			expr[i].level = 10 + LevelCounter;
			LevelCounter += 10;
			break;
		case rparenthesis:
			expr[i].level = LevelCounter;
			LevelCounter -= 10;
			break;
		case plus:
			expr[i].level = 1 + LevelCounter;
			break;
		case minus:
			expr[i].level = 1 + LevelCounter;
			break;
		case mult:
			expr[i].level = 2 + LevelCounter;
			break;
		case divide:
			expr[i].level = 2 + LevelCounter;
			break;
		case power:
			expr[i].level = 3 + LevelCounter;
			break;
		default:
			expr[i].level = 0;
			break;
		}
	}
	return expr;
}

int getFirstToken(const std::vector<Token> expr) {
	int first = -1;
	for (int i = 0; i < static_cast<int>(expr.size()); i++) {
		if (expr[i].level > 0 && (first == -1 || expr[i].level > expr[first].level) && expr[i].type!=lparenthesis && expr[i].type != rparenthesis) {
			first = i;
		}
	}
	return first;
}

std::vector<int> uselessParenthesis(const std::vector<Token> expr) {
	std::vector<int> index;
	for (int i = 0; i < expr.size() - 1; i++) {
		if (expr[i].type == lparenthesis && expr[i + 1].type == rparenthesis) {
			index.push_back(i);
			index.push_back(i + 1);
			return index;
		}
		if (expr[i].type == lparenthesis && expr[i + 2].type == rparenthesis) {
			index.push_back(i);
			index.push_back(i + 2);
			return index;
		}
	}
	index.push_back(-1);
	return index;
}