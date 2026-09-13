#include "lexer.h"

Token getToken(std::string p) {
	Token token;
	token.str = p;
	token.type = getType(p.at(0));
	token.level = 0;
	return token;
}