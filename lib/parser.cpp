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

int evalExpr(string expression, string text, int index)
{
	if(expression.at(0) == '%')
	{
		string strlit = text.substr(index,
			expression.len() - 1);
		if(strlit != expression.substr(1))
			throw ParseError("Failed to match string literal "
			+ expression.substr(1));
	}
	else if(expression.at(0) == '$')
	{
		//try to match regex
	}
	else if(expression.at(0) == '|')
	{
		string[] options = expression.substr(2).split();
		//TODO: syntax for FOR loop here
		{
			try
			{
				evalExpr(options[i], text, index);
				return;
			}
			catch(Parse Error e)
			{
				continue;
			}
		}
		throw ParseError("Failed to match one of valid expressions.");
	}
	else if(expression.substr(0,5).lower == "maybe")
	{
		string rule = expression.substr(6);
	}
	else
	{
		//call Parser::parse
	}
}

void Parser::parse(string text, Rule rule)
{
	//This is where all the fun is...
	/* Planning it all out...
	Create stack - Done
	For each expression in baseRule: - Done
		starts with $?
			parse regex - failed? throw error - Done
			add to current structure
		starts with %?
			parse string literal - failed? throw error
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
	size = rule.getExpressions().size();
	for(int i = 0; i < size; i++)
	{
		evalExpr(rule.getExpressions.at(i), text.substr(index));
	}
}

void Parser::parse(string text)
{
	parse(text, baseRule);
}
