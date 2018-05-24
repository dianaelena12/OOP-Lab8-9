#pragma once
#include "DynamicVector.h"
#include "Doggo.h"
#include <vector>

using namespace std;

class DoggieList
{
private:
	vector<Doggie> doggies;
	int current;

public:
	DoggieList();

	void add(const Doggie& dog);
	vector<Doggie> getDogs() const { return doggies; }
	//Doggie getCurrentDog();
	//void seeDogs();
	//void next();
	bool isEmpty();

};
