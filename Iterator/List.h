#ifndef __LIST__
#define __LIST__
#include "Node.h"
#include "Iterator.h"

class List
{
public:

	List();
	~List();
	void push_front(const int& value);
	void push_back(const int& value);
	Iterator begin();
	Iterator end();
	void PrintList();
	void remove(const int& value);
	int size();
	

private:
	
	Node* head;
	int amount = 0;
};

#endif