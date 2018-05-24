#pragma once
#include "DoggieList.h"
#include "FileRepository.h"
#include "Repository.h"
#include "Validator.h"

class Controller
{
private:
	FileRepository* repo;
	FileRepository* doggieList;
	DogValidator valid;

public:
	Controller(FileRepository* r, FileRepository* doggieList, DogValidator v) : repo{ r }, doggieList{doggieList}, valid{ v } {}
	Controller(const Controller& c);
	FileRepository* getRepo() const { return repo; }
	FileRepository* getDoggieList() const { return doggieList; }

	int addDoggieToRepository(const std::string& name, const std::string& breed, int age, const std::string& picture);
	void deleteADoggieFromRepo(const std::string& name, const std::string& breed);

	void addDoggieToDoggieList(const Doggie& dog);
	void saveAdoptionList();

	//void showTheDoggie();
	//void nextDoggieInDoggieList();

	int updateTheName(const std::string& newName ,const std::string& name, const std::string& breed);
	int updateTheBreed(const std::string& name, const std::string& breed, const std::string& newBreed);
	int updateTheAge(const std::string& name, const std::string& breed, int age);

};
