#include "Validator.h"

DogException::DogException(std::vector<std::string> _errors)
{
}

std::vector<std::string> DogException::getErrors() const
{
	return this->errors;
}

void DogValidator::validate(const Doggie & d)
{
	vector<string> errors;
	if (d.getName().size() < 2)
		errors.push_back("The name has to be at least 2 characters!");
	if (!isupper(d.getName()[0]))
		errors.push_back("The name must start with a capital letter!");
	if (d.getAge() < 0)
		errors.push_back("The age can't be less than 0");
	if (errors.size() > 0)
		throw DogException(errors);
}
