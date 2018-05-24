/*#include "Tests.h"
#include <assert.h>
#include "DynamicVector.h"
#include "DoggieList.h"
#include "Doggo.h"
#include "Repository.h"
#include "Controller.h"
#include <iostream>

void Tests::testDoggo()
{
	Doggie d1{ "Ralf", "Saint Bernand", 3, "https://cdn.shopify.com/s/files/1/1133/5028/files/st-bernard-dog-alps.jpg?v=1488930943" };
	assert(d1.getAge() == 3);
	assert(d1.getBreed() == "Saint Bernand");
	assert(d1.getName() == "Ralf");
	assert(d1.getPicture() == "https://cdn.shopify.com/s/files/1/1133/5028/files/st-bernard-dog-alps.jpg?v=1488930943");
	d1.showPhoto();
}

void Tests::testDynamicVector()
{
	DynamicVector<int> v1{ 2 };
	v1.add(10);
	v1.add(12);
	assert(v1.getSize() == 2);
	assert(v1[1] == 12);
	v1.add(34);
	assert(v1.getSize() == 3);

	DynamicVector<int> v2 = v1;
	assert(v2.getSize() == 3);

	DynamicVector<int> v3;
	v3 = v1;
	assert(v3[0] == 10);

}

void Tests::testRepository()
{
	Repository repo{};
	Doggie d1{ "Ralf", "Saint Bernand", 3, "https://cdn.shopify.com/s/files/1/1133/5028/files/st-bernard-dog-alps.jpg?v=1488930943" };
	repo.addDoggie(d1);
	Doggie res = repo.findDoggieByNameAndBreed("Ralf", "Saint Bernand");
	assert(res.getName() == d1.getName());
	assert(res.getBreed() == d1.getBreed());
	res = repo.findDoggieByNameAndBreed("Ralf", "");
	assert(res.getBreed() == "");

	DynamicVector<Doggie> doggies = repo.getDoggies();
	assert(doggies.getSize() == 1);

	repo.deleteDoggie("Ralf", "Saint Bernand");

	Doggie d2{ "Bobby", "Saint Bernand", 3, "https://cdn.shopify.com/s/files/1/1133/5028/files/st-bernard-dog-alps.jpg?v=1488930943" };
	repo.addDoggie(d2);
	repo.updateName("Bobster", "Bobby", "Saint Bernand");
	assert(d2.getName() == "Bobby");
	repo.updateBreed("Bobster", "Saint Bernand", "Saint");
	assert(d2.getBreed() != "Saint");
	repo.updateAge("Bobster", "Saint", 6);
	assert(d2.getAge() != 6);
	Doggie d3{ "", "", 0, "" };
	repo.addDoggie(d3);
	doggies = repo.getDoggies();
	repo.deleteDoggie("", "");
	
	assert(doggies.getSize() == 2);

}


void Tests::testController()
{
	Repository repo{};
	Controller ctrl{ repo };
	ctrl.addDoggieToRepository("Roscoe", "German Shepherd", 5, "https://www.pets4homes.co.uk/images/breeds/10/large/bad52e221a0911e32e548dc12d72366f.jpg");
	Doggie d{ "Roscoe", "German Shepherd", 5, "https://www.pets4homes.co.uk/images/breeds/10/large/bad52e221a0911e32e548dc12d72366f.jpg" };
	ctrl.addDoggieToDoggieList(d);

	assert(ctrl.getRepo().getDoggies().getSize() == 1);
	DoggieList list = ctrl.getDoggieList();
	assert(list.isEmpty() == false);

	Doggie d2{ "bob", "corgi", 1, "dskjfbdcbakh" };
	ctrl.addDoggieToRepository("bob", "corgi", 1, "dskjfbdcbakh");
	ctrl.updateTheAge("bob", "corgi", 2);
	assert(ctrl.getRepo().getDoggies().getSize() == 2);
	ctrl.updateTheBreed("bob", "corgi", "Corgi");
	ctrl.updateTheName("Bob", "bob", "Corgi");
	ctrl.deleteADoggieFromRepo("Bob", "Corgi");
	assert(ctrl.getRepo().getDoggies().getSize() == 1);
}

void Tests::testDoggieList()
{
	DoggieList list{};
	Doggie d2{ "Roscoe", "German Shepherd", 5, "https://www.pets4homes.co.uk/images/breeds/10/large/bad52e221a0911e32e548dc12d72366f.jpg" };
	Doggie d1{ "Ralf", "Saint Bernand", 3, "https://cdn.shopify.com/s/files/1/1133/5028/files/st-bernard-dog-alps.jpg?v=1488930943" };
	list.add(d1);
	list.add(d2);
	assert(list.isEmpty() == false);
}


void Tests::testAll()
{
	testDoggo();
	testDynamicVector();
	testRepository();
	testController();
	testDoggieList();
}
*/