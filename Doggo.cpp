#include "Doggo.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>


Doggie::Doggie(): name(""), breed(""), age(0), picture("") {}

Doggie::Doggie(const std::string& name, const std::string& breed, const int& age, const std::string& picture)
{
	this->name = name;
	this->breed = breed;
	this->age = age;
	this->picture = picture;
}

void Doggie::setName(const std::string& name)
{
	this->name = name;
}

void Doggie::setBreed(const std::string& breed)
{
	this->breed = breed;
}

void Doggie::setAge(int age)
{
	this->age = age;
}

void Doggie::showPhoto()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPicture().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::string Doggie::toString()
{
	std::stringstream s;
	s << this->name << " " << this->breed << " " << this->age << " " << this->picture<<std::endl;
	return std::string(s.str());

}

std::istream & operator>>(std::istream & is, Doggie & d)
{
	string line;
	getline(is, line);
	stringstream ss{ line };
	string tolken;
	vector<string> aux;
	while (getline(ss, tolken, ','))
	{
		aux.push_back(tolken);
	}
	if (aux.size() == 4)
	{
		d.name = aux[0];
		d.breed = aux[1];
		d.age = std::stoi(aux[2]);
		d.picture = aux[3];
	}
	return is;
}

std::ostream & operator<<(std::ostream & os, const Doggie & d)
{
	os << d.getName() << "," << d.getBreed() << "," << d.getAge() << "," << d.getPicture() << endl;
	return os;
}
