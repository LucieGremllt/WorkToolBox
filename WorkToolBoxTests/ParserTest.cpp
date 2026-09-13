#include "ParserTest.h"
#include "Parser.h"
#include "lexer.h"
#include <string>
#include <vector>
#include <cassert>


void ParserTest() {
	std::string expr = "1.7+21*41";
	std::vector<Token> testexpr = parseExpr(expr);
	assert(testexpr.size() == 5);
	assert(testexpr[0].str == "1.7");
	assert(testexpr[1].str == "+");
	assert(testexpr[2].str == "21");
	assert(testexpr[3].str == "*");
	assert(testexpr[4].str == "41");
}