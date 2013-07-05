#include "parser.hpp"

void Parser::operator>>(string rule)
{
	rules.append(rule);
}
