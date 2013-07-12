#include "parser.hpp"
#include <stack>

void Rule::operator>>(string expression)
{
	expressions.append(expression);
	//XXX We might change this, depending on how friendly the C++ API is
}

void Parser::addRule(Rule r)
{
	rules.append(r);
	//XXX Again, we might change this...
}

void Parser::parse(string text)
{
	//This is where all the fun is...
	/* Planning it all out...
	Create stack - Done
	For each expression in baseRule: - Done
		starts with $?
			parse regex - failed? throw error
			add to current structure
		starts with %?
			parse string litera - failed? throw error
			add to current structure
		labeled?
			add name to current structure
		sub-rule?
			push current str index to stack
			recurse evaluating subrule
			on finish return to super-rule
		OR expression?
			go over each option
			try to parse - failed?
				throw error if last element
				go to next element
			go on
		MAYBE expression?
			if doesn't match ignore
		COUNT expression?
			try to parse proper number of times
			failed? throw error		
	*/
	stack<int> callStack;
	for(int i = 0; i < baseRule.getExpressions().size(); i++)
	{
		if(baseRule.getExpressions().at(i).at(0) == '%')
		{
			//Parse as string literal
		}
		else if(baseRule.getExpressions().at(i).at(0) == '$')
		{
			//Parse as regex
		}
		else if(baserule.getExpressions().at(i).at(0) == '(')
		{
			//Parse as OR expression
		}
		else
		{
			callStack.push(i);
			//call parse() with substring i as parameter
		}
	}
}
