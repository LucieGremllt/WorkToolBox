#pragma once
#include <vector>
#include <string>

enum CalculusDataType {
	plus,
	minus,
	divide,
	mult,
	power,
	lparenthesis,
	rparenthesis,

	num
};

CalculusDataType getType(char c);

struct Token {
	CalculusDataType type = num;
	std::string str;
	int level = 0;
};

Token getToken(std::string p);

