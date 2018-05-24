#pragma once
#include "Doggo.h"
#include "DynamicVector.h"
#include <vector>
#include "RepoExceptions.h"

using namespace std;

class Repository
{
private:
	vector<Doggie>* doggies;

public:

	Repository();
	Repository(const Repository& r);
	void addDoggie(const Doggie& d);
	void deleteDoggie(const std::string& name, const std::string& breed);
	void updateName(const std::string& newName,const std::string& name, const std::string& breed);
	void updateBreed(const std::string& name, const std::string& breed, const std::string& newBreed);
	void updateAge(const std::string& name, const std::string& breed, int age);

	Doggie findDoggieByNameAndBreed(const std::string& name, const std::string& breed);
	vector<Doggie>* getDoggies() const { return doggies; }


};