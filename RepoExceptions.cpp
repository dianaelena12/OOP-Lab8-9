#include "RepoExceptions.h"

FileException::FileException(const std::string & msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepoExceptions::RepoExceptions()
{
}

RepoExceptions::RepoExceptions(const std::string & msg)
{
}

const char * RepoExceptions::what()
{
	return this->message.c_str();
}

const char * DuplicateDogException::what()
{
	return "There is another dog with the same name and breed!\n";
}
