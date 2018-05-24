#include "CSVRepository.h"
#include <fstream>
#include <stdlib.h>

void CSVRepository::repoReadFile()
{
	std::ifstream in(source);
	if (!in.is_open())
		throw RepoExceptions("Cannot open file: " + source);
	Doggie d;
	while (in >> d)
	{
		this->addDoggie(d);
	}
	in.close();
}

void CSVRepository::repoWriteFile()
{
	std::ofstream out(source);
	std::vector<Doggie>* d = this->getDoggies();
	for (auto it : *d)
		out << it ;
	out.close();
}

CSVRepository::CSVRepository(const std::string & source) : FileRepository(source)
{
	this->repoReadFile();
}

CSVRepository::~CSVRepository()
{
	this->repoWriteFile();
}

void CSVRepository::display()
{
	std::string s = "notepad \"" + source + "\"";
	system(s.c_str());
}