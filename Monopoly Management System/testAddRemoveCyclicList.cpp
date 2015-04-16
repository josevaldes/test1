
/*
#include <iostream>
#include <string>
#include "property_database.h"
#include "LinkedUser.h"
#include "user.h"
#include "menu_methods.h"

using namespace std;

int main()
{
	user listUser[] = { user("Starker"), user("Novastorm"), user("Alcaro"), user("Jedastla"),
		user("Sadevlet"), user("Kenshin"), user("Raiden"), user("Raika") };
	
	LinkedUser* list = new LinkedUser(listUser[0]);
	
	for (int i = 1; i < 8; ++i)
		list->addUser(listUser[i]);

	cerr << endl << "Head is: " << list->getHead()->getUser()->getName() << endl;

	list->nextCurrent();
	list->nextCurrent();
	list->nextCurrent();

	cerr << "Current is: " << list->getCurrent()->getUser()->getName() << endl;

	list->createCyclicList();
	list->displayList();

	list->removeUser(list->getCurrent());
	
	cerr << endl;
	list->displayList();

	//cerr << endl << "Head is: " << list->getHead()->getUser()->getName() << endl;
	
	/*property_database DB;
	user* test = list->obtainUser("Alcaro");
	test->displayBalance();
	cerr << endl;
	
	test->addCurrency(1500);
	buyPropertyToBank(*test, DB);
	
	user* test_2 = list->obtainUser("Alcaro");
	
	test_2->displayBalance();
	*/

/*
	return 0;
}*/