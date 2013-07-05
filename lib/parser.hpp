#ifndef PARSER_H
#define PARSER_H

class Parser
{
	private:
		vector<string> rules;
	public:
		void operator>>(string rule);
		SpearStructure parse(string filename);
}

#endif //PARSER_H
