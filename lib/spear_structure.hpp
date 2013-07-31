#ifndef SPEAR_STRUCTURE_HPP
#define SPEAR_STRUCTURE_HPP 1

#define MAX_ELEMENTS 64 //why would you want more than 64 child elements???
//might lower to 32 or even 24
//A dynamically-expanding array wouldn't be worth the effort

struct SpearElement
{
	string name;
	string value;
}

struct SpearStructure
{
	union Element
	{
		SpearElement se;
		SpearStructure ss;
	} elements[MAX_ELEMENTS];
}

#endif //SPEAR_STRUCTURE_HPP
