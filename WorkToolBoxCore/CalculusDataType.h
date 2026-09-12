#pragma once

enum CalculusDataType {
	plus,
	minus,
	divide,
	mult,
	power,

	num
};

CalculusDataType getType(char c);