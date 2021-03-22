#ifndef __ITERATOR__
#define __ITERATOR__
#include "Node.h"

class Iterator
{

public:
	Iterator(Node* start = nullptr);
	int operator*();
	Iterator operator++();
	bool operator!=(const Iterator& other);
private:
	Node* current;


};

#endif