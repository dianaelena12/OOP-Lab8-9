#include "Repository.h"
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

Repository::Repository()
{
	doggies = new vector<Doggie>();
}

Repository::Repository(const Repository & r)
{
	doggies = new vector<Doggie>();
	for (auto& it : *(r.doggies))
	{
		doggies->push_back(it);
	}
}

void Repository::addDoggie(const Doggie& d)
{
	Doggie dog = findDoggieByNameAndBreed(d.getName(), d.getBreed());
	if (dog.getName() != "" || dog.getBreed() != "")
		throw DuplicateDogException();
	this->doggies->push_back(d);
}

void Repository::deleteDoggie(const std::string& name, const std::string& breed)
{
	Doggie d = findDoggieByNameAndBreed(name, breed);
	if (d.getName() == "" && d.getBreed() == "")
		return;
	auto it = this->doggies->begin();
	for (Doggie dog : *doggies)
	{
		if (dog.getName() == d.getName() && dog.getBreed() == d.getBreed())
		{
			this->doggies->erase(it);
			return;
		}
		it++;
	}
}



Doggie Repository::findDoggieByNameAndBreed(const std::string& name, const std::string& breed)
{
	auto it = std::find_if(this->doggies->begin(), this->doggies->end(), [&name, &breed](const Doggie& d) {return d.getBreed() == breed && d.getName() == name; });
	if (it == this->doggies->end())
		return Doggie{};
	return *it;
	}

/*void Repository::readFromFile()
{
	ifstream file(this->fileName);
	if (!file.is_open())
		cout << "problem at opening the file";
	Doggie d;
	while (file >> d)
		this->doggies.push_back(d);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->fileName);
	if (!file.is_open())
		cout << "problem at opening the file";

	for (auto d : this->doggies)
	{
		file << d;
	}
	file.close();
}*/

void Repository::updateName(const std::string& newName,const std::string& name, const std::string& breed)
{
	for (Doggie d :*doggies)
	{
		if (d.getName() == name && d.getBreed() == breed)
		{
			d.setName(newName);
		}
	}
	throw RepoExceptions("The dog's name you tried to update does not exist!");
}
void Repository::updateBreed(const std::string& name, const std::string& breed, const std::string& newBreed)
{
	for (Doggie d : *doggies)
	{
		if (d.getName() == name && d.getBreed() == breed)
		{
			d.setBreed(newBreed);
		}
	}
	throw RepoExceptions("The dog's breed you tried to update does not exist");
}
void Repository::updateAge(const std::string& name, const std::string& breed, int age)
{
	for (Doggie d : *doggies)
	{
		if (d.getName() == name && d.getBreed() == breed)
		{
			d.setAge(age);
		}
	}
	throw RepoExceptions("The dog's age you tried to update does not exist");
}