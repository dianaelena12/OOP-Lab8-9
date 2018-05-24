#include "HTMLRepository.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <shellapi.h>

void HTMLRepository::repoWriteFile()
{
	std::ofstream out(source);
	if (!out.is_open())
		throw RepoExceptions("Cannot open file: " + source);
	out << "<!DOCTYPE html> \n <html> \n \t<head> \n \t\t <title>HTMLRepository</title> \n";
	out << "\t</head> \n \t<body> \n \t\t<table border=\"1\"> \n \t\t<tr>\n";
	out << "\t\t\t<td>Name</td> \n \t\t\t<td>Breed</td> \n \t\t\t <td>Age</td>\n ";
	out << "\t\t\t<td>Link to photo</td> \n";
	std::vector<Doggie>* d = this->getDoggies();
	for (auto dog : *d)
	{
		out << "\t\t<tr>\n";
		out << "\t\t\t<td>" << dog.getName() << "</td>\n";
		out << "\t\t\t<td>" <<dog.getBreed() << "</td>\n";
		out << "\t\t\t<td>" << dog.getAge() << "</td>\n";
		out << "\t\t\t<td>" << dog.getPicture() << "</td>\n";
		out << "\t\t</tr>\n";
	}
	out << "\t\t</table>\n";
	out << "\t</body>\n";
	out << "</html>\n";
	out.close();

}

void HTMLRepository::display()
{
	std::string aux = "\"" + this->source + "\"";
	ShellExecuteA(NULL, NULL, "C:\Program Files (x86)\Google\Chrome\Application\\chrome", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}