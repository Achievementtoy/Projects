// File/Project Prolog
// Name: Garrett Cook
// CS 2420 Section 003
// Project: HashMap
// Date: 10/10/2019
//
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
// 
// I also state that the Standard Template Library is NOT used in this project
// ---------------------------------------------------------------------------



#include <string>
#include "HashMap.h"
#include "Node.h"





// parameterized constructor
Iterator::Iterator(int index, Node** hashArray, int sizeOfArray)
{
	this->sizeOfArray = sizeOfArray;
	this->hashArray = hashArray;
	int start;
	for (start = 0; start < sizeOfArray; ++start)
	{
		if (hashArray[start] != nullptr) {
			current = hashArray[start];
			this->index = start;
			return;
		}
	}
	current = nullptr;
	this->index = sizeOfArray;
}

Iterator::Iterator()
{
	hashArray = nullptr;
	current = nullptr;
	index = 0;
	sizeOfArray = 0;

}

string Iterator::operator*()
{
	return current->key;
}
// Dana helped me with this, went about this function in a different way. Iterates through the list
void Iterator::operator++()
{
	if (current != nullptr and current->next != nullptr) {
		current = current->next;
		
	}
	else if (index < sizeOfArray - 1) {

		do {
			++index;



		} while ((index < sizeOfArray) and (hashArray[index] == nullptr));
		current = hashArray[index];
	}
	else {
		current = nullptr;
	}
	
}

bool Iterator::operator!=(Iterator& other)
{
	return current != other.current;
}
// checks to make sure it is an item
bool Iterator::is_item()
{
	return current != nullptr;
}
