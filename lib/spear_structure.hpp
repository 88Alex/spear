#ifndef SPEAR_STRUCTURE_HPP
#define SPEAR_STRUCTURE_HPP 1

#define MAX_ELEMENTS 64 //why would you want more than 64 child elements???
//might lower to 32 or even 24

struct SpearStructure
{
	int type; //0 for text, 1 if it contains a substructure
	char* name;
	union Element
	{
		char* text;
		struct SpearStructure* child;
	} elements[MAX_ELEMENTS];
}

#endif //SPEAR_STRUCTURE_HPP
