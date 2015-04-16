#include <iostream>
#include <string>
#include "user.h"
#include "LinkedUser.h"
#include "helping_methods.h"

using namespace std;

Node::Node()
{
	player = user();
	next = nullptr;
}

Node::Node(user temp)
{
	player = temp;
	next = nullptr;
}

user* Node::getUser()
{
	return &player;
}

void Node::setUser(user temp)
{
	player = temp;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* temp)
{
	next = temp;
}

LinkedUser::LinkedUser()
{
	head = new Node();
	current = head;
	tail = head;
}

LinkedUser::LinkedUser(user temp)
{
	head = new Node(temp);
	current = head;
	tail = head;
}

/*
void eliminateFirst(LinkedUser* head)
{
	LinkedUser* ite = head;
	head = ite->next;
	cerr << "Head in method is " << head->getUser().getName();
	//delete ite;
}*/

Node* LinkedUser::getHead()
{
	return head;
}

Node* LinkedUser::getTail()
{
	return tail;
}

Node* LinkedUser::getCurrent()
{
	return current;
}

void LinkedUser::nextCurrent()
{
	current = current->next;
}

void LinkedUser::displayList()
{
	Node* ite = head->next;
	bool first = true;

	while (ite != head)
	{
		if (first)
		{
			cout << head->getUser()->getName() << endl;
			first = false;
			continue;
		}

		cout << ite->getUser()->getName() << endl;
		ite = ite->next;
	}
	
	ite = nullptr;
	delete ite;
}

void LinkedUser::addUser(user added)
{
	Node* ite = head;
	
	while (ite->next != nullptr)
	{
		ite = ite->next;
	}

	ite->next = new Node(added);
	
	tail = ite->next;

	ite = ite->next->next;
	
	delete ite;
}

bool LinkedUser::removeUser(Node* remove)
{
	if (remove == head)
	{
		head = head->next;
		nextCurrent();
		delete remove;
		createCyclicList();
		return true;
	}
	
	Node* ite = head->next;
    
	if (ite == remove)
	{
		head->next = remove->next;
		nextCurrent();
		delete remove;
		return true;
	}

	while (ite != head)
	{
		if (ite->next == remove)
		{
			ite->next = remove->next;

			if (remove == tail)
			{
				tail = ite;
			}

			nextCurrent();
			delete remove;
			
			return true;
		}

		ite = ite->next;
	}

	cerr << "Error: User wasn't found" << endl;
	return false;
}

void LinkedUser::createCyclicList()
{
	tail->next = head;
}


user* LinkedUser::obtainUser(string name)
{
	if (head != nullptr && head->getUser()->getName() == name)
	{
		return head->getUser();
	}
	
	Node* ite = head->next;

	while (ite != nullptr)
	{
		if (ite->getUser()->getName() == name)
			return ite->getUser();

		if (ite == head)
		{
			cerr << "User wasn't found" << endl;
			return nullptr;
		}

		ite = ite->next;
	}

	cerr << "User wasn't found" << endl;
	return nullptr;
}

