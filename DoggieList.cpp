#include "DoggieList.h"

DoggieList::DoggieList()
{
	this->current = 0;
}

void DoggieList::add(const Doggie& dog)
{
	this->doggies.push_back(dog);
}

bool DoggieList::isEmpty()
{
	return this->doggies.size() == 0;
}