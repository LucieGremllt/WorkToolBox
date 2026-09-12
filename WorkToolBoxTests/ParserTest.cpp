#include "ParserTest.h"
#include "Parser.h"
#include <string>
#include <vector>
#include <cassert>


void ParserTest() {
	std::string expr = "17+21*41";
	std::vector<std::string> testexpr;
	testexpr.push_back("17");
	testexpr.push_back("+");
	testexpr.push_back("21");
	testexpr.push_back("*");
	testexpr.push_back("41");
	assert(testexpr == parseExpr(expr));
}