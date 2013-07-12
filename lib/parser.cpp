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

stack<int> callstack;

int evalExpr(string expression, string text) //ret 1=error
{
	if(expression.at(0) == '%')
	{
		string strlit = text.substr(index,
			expression.len() - 1);
		//add to structure
	}
	else if(expressions.at(0) == '$')
	{
		//try to match regex
	}
	else if(expressions.at(0) == '|')
	{
		string[] options = expression.substr(index + 2).split();
		// for each in options: call evalExpr(options[i])
		// if 1 go on to next- if all done throw error
	}
	else
	{
		// if doesn't exist
		callStack.push(i);
		//call parse() with substring i as parameter
	}
}

void Parser::parse(string text, Rule rule)
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
	int index = 0;
	for(int i = 0; i < rule.getExpressions().size(); i++)
	{
		evalExpr(rule.getExpressions.at(i), text.substr(index));
	}
}
