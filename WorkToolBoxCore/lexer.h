#pragma once
#include "CalculusDataType.h"
#include <vector>
#include <string>

typedef struct {
	CalculusDataType type;
	std::string str;
	int level;
} Token;

Token getToken(std::string p);

