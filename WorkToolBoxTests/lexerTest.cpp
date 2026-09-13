#include "lexerTest.h"
#include "lexer.h"
#include "CalculusDatatype.h"
#include <cassert>

void lexerTest() {
	Token test = getToken("227");
	assert(test.str == "227");
	assert(test.type == num);
	assert(test.level == 0);
}