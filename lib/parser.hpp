#ifndef PARSER_H
#define PARSER_H

#include <vector>

class Rule
{
	private:
		vector<string> expressions;
	public:
		vector<string> getExpressions() { return expressions; }
		void operator>>(string rule);
}

class Parser
{
	private:
		vector<Rule> rules;
		Rule baseRule;
	public:
		void addRule(Rule r);
		void setBaseRule(Rule r) { baseRule = r; }
		SpearStructure parse(string text);
		SpearStructure parsefile(string filename);
}

#endif //PARSER_H
