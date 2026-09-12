#include "Calculator.h"

#include <string>
#include <vector>
#include <cassert>

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
double Calculator::power(double nb, unsigned int expo) {
	assert(nb > 0);
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
