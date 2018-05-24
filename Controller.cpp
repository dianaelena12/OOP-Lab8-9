#include "Controller.h"
#include "FileRepository.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

Controller::Controller(const Controller & c)
{
	repo = c.repo;
	valid = c.valid;
	doggieList = c.doggieList;
}

int Controller::addDoggieToRepository(const std::string& name, const std::string& breed, int age, const std::string& picture)
{
	Doggie d{ name, breed, age, picture };
	try
	{
		this->valid.validate(d);
		this->repo->addDoggie(d);
		return 1;
	}
	catch (DuplicateDogException&)
	{
		cout << "Dog allready exists!";
		return 0;
	}
}

void Controller::addDoggieToDoggieList(const Doggie& dog)
{
	this->doggieList->addDoggie(dog);
	this->saveAdoptionList();
	
}

void Controller::saveAdoptionList()
{
	if (this->doggieList == nullptr)
		return;
	this->doggieList->repoWriteFile();
}


void Controller::deleteADoggieFromRepo(const std::string& name, const std::string& breed)
{
	this->repo->deleteDoggie(name, breed);
}

int Controller::updateTheName(const std::string& newName,const std::string& name, const std::string& breed)
{
	try
	{
		this->repo->updateName(newName, name, breed);
		return 1;
	}
	catch (RepoExceptions&)
	{
		cout << "Can't update the name of an inexistent dog!";
		return 0;
	}
}

int Controller::updateTheBreed(const std::string& name, const std::string& breed, const std::string& newBreed)
{
	try {
		this->repo->updateBreed(name, breed, newBreed);
		return 1;
	}
	catch(RepoExceptions&){
		cout << "Can't update the breed of an inexistent dog!";
		return 0;
	}
	
}

int Controller::updateTheAge(const std::string& name, const std::string& breed, int age)
{
	try {
		this->repo->updateAge(name, breed, age);
		return 1;
	}
	catch(RepoExceptions&){
		cout << "Can't update the age of an inexistent dog!";
		return 0;
	}
}