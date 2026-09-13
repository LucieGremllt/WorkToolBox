#include "lexer.h"

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
	case '(':
		type = lparenthesis;
		break;
	case ')':
		type = rparenthesis;
		break;
	default:
		type = num;
		break;
	}
	return type;
}

Token getToken(std::string p) {
	Token token;
	token.str = p;
	token.type = getType(p.at(0));
	token.level = 0;
	return token;
}