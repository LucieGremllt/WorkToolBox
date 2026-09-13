#include "lexerTest.h"
#include "lexer.h"
#include <cassert>

void lexerTest() {
	Token test = getToken("227");
	assert(test.str == "227");
	assert(test.type == num);
	assert(test.level == 0);
}

void CalculusDataTypeTest() {
	char c1 = '+';
	char c2 = '-';
	char c3 = '/';
	char c4 = '*';
	char c5 = '^';
	char c6 = '8';
	assert(getType(c1) == plus);
	assert(getType(c2) == minus);
	assert(getType(c3) == divide);
	assert(getType(c4) == mult);
	assert(getType(c5) == power);
	assert(getType(c6) == num);
}