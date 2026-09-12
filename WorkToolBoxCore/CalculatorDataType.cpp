#include "CalculusDataType.h"
#include <cctype>

CalculusDataType getType(char c) {
	CalculusDataType type;
	switch (c) {
	case '+':
		type = plus;
		break;
	case '-':
		type = minus;
		break;
	case '*':
		type = mult;
		break;
	case '/':
		type = divide;
		break;
	case '^':
		type = power;
		break;
	default:
		type = num;
		break;
	}
	return type;
}