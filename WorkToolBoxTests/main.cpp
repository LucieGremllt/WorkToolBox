#include "CalculatorTests.h"
#include "CalculusDataTypeTest.h"
#include "ParserTest.h"
#include "lexerTest.h"

int main() {
	CalculatorTests();
	CalculusDataTypeTest();
	lexerTest();
	ParserTest();
	return 1;
}