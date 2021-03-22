#include <cassert>
#include "Iterator.h"
// the start of the iterator
Iterator::Iterator(Node* start)
{
	current = start;
}
//returns the data
int Iterator::operator*()
{
	return current->data;
}
// increments the loop up 1
Iterator Iterator::operator++()
{
	Iterator original(current);
	current = current->next;
	return original;

}

bool Iterator::operator!=(const Iterator& other)
{
	return current != other.current;
}
