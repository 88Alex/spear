#include "parser.hpp"
#include <stack>

int type = 0; //0 = normal structure; 1 = substructure

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
	else if(expression.at(0) == '#')
	{
		//label it
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
			catch(ParseError e)
			{
				continue;
			}
		}
		throw ParseError("Failed to match one of valid expressions.");
	}
	else if(expression.substr(0,5).lower == "maybe")
	{
		string rule = expression.substr(6);
		// it's supposed to have a space after the "maybe"
		// index 6 will be after the space
		try
		{
			evalExpr(rule, text, index);
		}
		catch(ParseError e)
		{
			// ignore it on purpose
		}
	}
	else
	{
		type = 1;
		// list all rules
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
	struct SpearStructure structure;
	expr_count = rule.getExpressions().size();
	for(int i = 0; i < expr_count; i++)
	{
		
		SpearStructure new_structure = evalExpr(
			rule.getExpressions().at(i), text, index);
		//add it to the main structure
	}
}

SpearStructure Parser::parse(string text)
{
	return parse(text, baseRule);
}
