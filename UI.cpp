#include "UI.h"
#include <string>
#include <algorithm>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage dogs in repository." << endl;
	cout << "2 - Manage adoption list." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "Possible commands:  " << endl;
	cout << "\t 1 - Add a dog." << endl;
	cout << "\t 2 - Display all dogs." << endl;
	cout << "\t 3 - Update the info of a dog" << endl;
	cout << "\t 4 - Delete a dog from repository." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printDoggieListMenu()
{
	cout << endl;
	cout << "Possible commands:  " << endl;
	cout << "\t 1 - See all doggies." << endl;
	cout << "\t 2 - See adoption list" << endl;
	cout << "\t 3 - See all doggies of a given breed, having an age less than a given number" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printMenuForAdoptionList()
{
	cout << endl;
	cout << "       Commands:     " << endl;
	cout << "\t 1 - Next doggie " << endl;
	cout << "\t 2 - Previous doggie " << endl;
	cout << "\t 3 - Adopt current doggie" << endl;
	cout << "\t 0 - Back" << endl;
}

void UI::addDoggieToRepo()
{
	cout << "Enter the name of the canine: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed of the canine: ";
	std::string breed;
	getline(cin, breed);
	int age = 0;
	cout << "Enter it's age: ";
	cin >> age;
	cin.ignore();
	cout << "Input the link containing it's photograph: ";
	std::string picture;
	getline(cin, picture);

	int res = this->ctrl->addDoggieToRepository(name, breed, age, picture);
	if(res == 1)
		cout << "Successfully added informations :)" << endl;
	return;

}

void UI::deleteADoggie()
{
	cout << "Enter the name of the canine: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed of the canine: ";
	std::string breed;
	getline(cin, breed);

	this->ctrl->deleteADoggieFromRepo(name, breed);
}

void UI::seeAllDoggiesInRepo()
{
	vector<Doggie>* doggies = this->ctrl->getRepo()->getDoggies();
	if (doggies->size() == 0)
	{
		cout << "There are no doggies in the repository :(" << endl;
		return;
	}
	for (Doggie dog : *doggies)
	{
		cout << dog.getName() << " - " << dog.getBreed() << " - " << dog.getAge() << endl;
	}
}


void UI::update()
{
	cout << endl;
	cout << "\t1 - Update the name" << endl;
	cout << "\t2 - Update the breed" << endl;
	cout << "\t3 - Update the age" << endl;
	cout << "\t0 - Get back." << endl;
	cout << endl;
	int command{ 0 };
	cout << "Input the command: ";
	cin >> command;
	cin.ignore();
	switch (command)
	{
	case 0:
		return;
	case 1:
	{
		cout << "Enter the doggie's name: ";
		std::string name;
		getline(cin, name);
		cout << "Enter the doggie's breed: ";
		std::string breed;
		getline(cin, breed);
		cout << "Enter the doggie's new name: ";
		std::string newname;
		getline(cin, newname);
		Doggie d = this->ctrl->getRepo()->findDoggieByNameAndBreed(name, breed);
		if (d.getBreed() == "" && d.getName() == "")
		{
			cout << "There is no doggy with the given data in the repository!" << endl;
			break;
		}
		int res = this->ctrl->updateTheName(newname,name, breed);
		if(res == 1)
			cout << "Updated successfully!" << endl;
		return;
	}
	case 2:
	{
		cout << "Enter the doggie's name: ";
		std::string name;
		getline(cin, name);
		cout << "Enter the doggie's breed: ";
		std::string breed;
		getline(cin, breed);
		cout << "Enter the doggie's new breed: ";
		std::string newbreed;
		getline(cin, newbreed);
		Doggie d = this->ctrl->getRepo()->findDoggieByNameAndBreed(name, breed);
		if (d.getBreed() == "" && d.getName() == "")
		{
			cout << "There is no doggy with the given data in the repository!" << endl;
			break;
		}
		int res = this->ctrl->updateTheBreed(name, breed, newbreed);
		if(res == 1)
			cout << "Updated successfully!" << endl;
		return;

	}
	case 3:
	{
		cout << "Enter the doggie's name: ";
		std::string name;
		getline(cin, name);
		cout << "Enter the doggie's breed: ";
		std::string breed;
		getline(cin, breed);
		cout << "Enter the doggie's age: ";
		int age;
		cin >> age;
		cin.ignore();
		Doggie d = this->ctrl->getRepo()->findDoggieByNameAndBreed(name, breed);
		if (d.getBreed() == "" && d.getName() == "")
		{
			cout << "There is no doggy with the given data in the repository!" << endl;
			break;
		}
		int res = this->ctrl->updateTheAge(name, breed, age);
		if(res == 1)
			cout << "Updated successfully!" << endl;
		return;
	}
	}
}

void UI::seeAdoptionList()
{
	
	vector<Doggie>* adoptionList = this->ctrl->getDoggieList()->getDoggies();
	if (adoptionList->size() == 0)
	{
		cout << "There are no doggies in the adoption list yet" << endl;
		return;
	}
	for (Doggie dog : *adoptionList)
	{
		cout << dog.getName() << " - " << dog.getBreed() << " - " << dog.getAge() << endl;
	}
}


void UI::userOptions(vector<Doggie> doggies)
{
	int current = 0;
	while (true)
	{
		system("cls");
		cout << "      Choose from the following commands     " << endl;
		cout << "\t 1 - Adopt the current dog" << endl;
		cout << "\t 2 - See next dog" << endl;
		cout << "\t 0 - Exit" << endl;
		cout << endl << endl;
		cout << doggies[current].getName() << " - " << doggies[current].getBreed() << " - " << doggies[current].getAge() << endl;
		doggies[current].showPhoto();
		int command = 0;
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command < 0 || command > 2)
		{
			cout << "Invalid input!" << endl;
			break;
		}
		if (command == 0)
			break;
		if(command == 1)
		{
			Doggie dog = doggies[current];
			this->ctrl->addDoggieToDoggieList(dog);
			cout << "This doggie was added to the adoption list" << endl;
			system("cls");
			cout << "Want to check out the rest of the dogs?  (1/0)" << endl;
			int forward = -1;
			cin >> forward;
			cin.ignore();
			if (forward == 1)
				current++;
			else
				break;
		}
		if(command == 2)
		{
			if (current == doggies.size() - 1)
				current = 0;
			else
				current++;
		}

	}
}

void UI::dogsOfASpecificBreed()
{
	vector<Doggie>* doggies = this->ctrl->getRepo()->getDoggies();
	if (doggies->size() == 0)
	{
		cout << "There are no doggies to adopts right now" << endl;
		return;
	}
	vector<Doggie> specific;
	int size = 0;
	cout << "Enter the doggie's breed: ";
	std::string breed;
	getline(cin, breed);
	cout << " Enter the age: ";
	int age;
	cin >> age;
	cin.ignore();
	if (age <0 || age > 100)
	{
		cout << "Age is not int! Invalid input!" << endl;
		return;
	}
	auto it = copy_if(doggies->begin(), doggies->end(), back_inserter(specific), [age,breed](Doggie d) {return ((d.getAge() <= age) && (d.getBreed() == breed)); });
	if (specific.size() == 0)
	{
		cout << "No dogs with this breed registered" << endl;
		return;
	}
	this->userOptions(specific);

	
}

void UI::seeAllDogs()
{
	vector<Doggie>* doggies = this->ctrl->getRepo()->getDoggies();
	if (doggies->size() == 0)
	{
		cout << "There are no doggies to adopts right now" << endl;
		return;
	}
	this->userOptions(*doggies);
}

UI::UI(Controller * c)
{
	ctrl = c;
}

void UI::run()
{
	printDoggieListMenu();
	printMenuForAdoptionList();
	printRepositoryMenu();
	while (true)
	{
		system("cls");
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		if (command == 1)
		{
			while (true)
			{
				system("cls");
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
				{
					this->addDoggieToRepo();
					system("pause");
					break;
				}
				case 2:
				{
					this->seeAllDoggiesInRepo();
					system("pause");
					break;
				}
				case 3:
				{
					this->update();
					system("pause");
					break;
				}
				case 4:
				{
					this->deleteADoggie();
					system("pause");
					break;
				}
				}
			}
		}
		if (command == 2)
		{
			while (true)
			{
				system("cls");
				UI::printDoggieListMenu();
				int commandList{ 0 };
				cout << "Input the command: ";
				cin >> commandList;
				cin.ignore();
				if (commandList == 0)
					break;
				switch (commandList)
				{
				case 1:
				{
					cout << "ii de lucru aci";
					this->seeAllDogs();
					system("pause");
					break;
				}
				case 2:
				{
					this->seeAdoptionList();
					system("pause");
					break;
				}
				case 3:
				{
					this->dogsOfASpecificBreed();
					system("pause");
					break;
				}
				}
			}
		}
	}
}