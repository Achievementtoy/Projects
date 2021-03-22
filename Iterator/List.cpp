/********************************************************************************************
**	Project: External Iterator
**  Programmer: Garrett Cook
**  Course:		cs2420
**	Section:	601
**	Assignment: 6
**	Data:		October 2, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/







#include "List.h"
using namespace std;
// amount in the list
int List::size()
{
	return amount;

}
//default
List::List()
{
	head = nullptr;
	
}
// deletes the node
List::~List()
{
	while (head != nullptr) {

		Node * next = head->next;
		delete head;
		head = next;


	}
}


void List::push_front(const int& value)
{
	Node* newnode = new Node;
	newnode->data = value;
	newnode->next = head;

	head = newnode;


}
// pushes node to the back, reviewed past project for help as well as some on stack overflow
void List::push_back(const int& value)
{
	Node * newnode1 = new Node;
	newnode1->data = value;
	newnode1->next = nullptr;

	if (head == nullptr) {
		head = newnode1;
	}
	else {
		Node* newnode2 = head;

		while (newnode2->next != nullptr)
			newnode2 = newnode2->next;


		newnode2->next = newnode1;
	}







}
// beginnning of list
Iterator List::begin()
{
	return Iterator(head);
}
// return the default constructor which is nullptr
Iterator List::end()
{
	return Iterator();
}

void List::PrintList()
{
	Node* print = head;
	while (print != nullptr) {

		cout << print->data << " ";
		print = print->next;
	}
	cout << endl;
}
// required some help, looked online for some assistance and managed to simplify this using double pointers
void List::remove(const int& value)
{
	// got help from online on double pointers
	Node** before = &head;

	while (*before)

		if ((*before)->data == value) {
			Node* node1 = (*before)->next;
			delete *before;
			*before = node1;
		}
		else
			before = &(*before)->next;

}
