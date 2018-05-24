#include "UI.h"
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include "Tests.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"

using namespace std;

void testOperator()
{
	DynamicVector<int> v{ 5 };
	v = v + 3;
	v.add(2);
	v.add(4);
	v = 6 + v;
	assert(v.getSize() == 4);
	assert(v[0] == 3);
	assert(v[2] == 4);
}

int main()
{
	system("color 09");
	//testOperator();
	try{
		cout << " How would you like to store your adoption list?(CSV/HTML)";
		std::string store;
		getline(cin, store);
		FileRepository* r = nullptr;
		FileRepository* adoption = nullptr;
		if (store == "csv") {
			r = new CSVRepository("dogslist.txt");
			adoption = new CSVRepository("adoptionlist.txt");
		}
		else
			if (store == "html")
			{
				adoption = new HTMLRepository("HTMLRepository.html");
				r = new CSVRepository("dogslist.txt");
			}
		Controller* ctrl = new Controller(r, adoption, DogValidator{} );
		UI* ui = new UI(ctrl);
		ui->run();
	}
	catch (RepoExceptions& exp) {
		std::cout << exp.what() << std::endl;
	}

	//Tests::testAll();

	Repository repo();

	
	return 0;
}