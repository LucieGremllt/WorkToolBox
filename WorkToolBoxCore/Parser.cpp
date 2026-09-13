#include "Parser.h"
#include <cctype>

std::vector<Token> parseExpr(const std::string& expr) {
	std::vector<Token> elements;
	std::string element;

	char character;
	for (int i = 0; i < expr.length(); i++) {
		character = expr.at(i);
		if (i == 0) {
			element.push_back(character);
		}
		else {
			if (getType(element.back()) == getType(character)) {
				element.push_back(character);
			}
			else {
				elements.push_back(getToken(element));
				element = character;
			}
		}
	}
	elements.push_back(getToken(element));
	return elements;
}


