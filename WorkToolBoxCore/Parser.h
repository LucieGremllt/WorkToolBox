#pragma once
#include "lexer.h"
#include <vector>
#include <string>

std::vector<Token> parseExpr(const std::string& expr);

