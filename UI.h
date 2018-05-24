#pragma once
#include "Controller.h"
#include <vector>
using namespace std;

class UI
{
private:
	Controller* ctrl;

public:
	UI(Controller* c);

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printDoggieListMenu();
	static void printMenuForAdoptionList();

	void addDoggieToRepo();
	void deleteADoggie();
	void seeAllDoggiesInRepo();
	void update();
	void seeAdoptionList();
	void seeAllDogs();
	void userOptions(vector<Doggie> doggies);
	void dogsOfASpecificBreed();
};
