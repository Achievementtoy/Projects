/********************************************************************************************
**	Project: Binary Search Tree
**  Programmer: Garrett Cook
**  Course:		cs2420
**	Section:	601
**	Assignment: 8
**	Data:		October 30, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/







#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"
#include "RecursionCounter.h"
#include "Observer.h"


using namespace std;

int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main()
{
	// creates the array
	int data[] = { 21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7 };
	

	BinarySearchTree tree;
	for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		tree.Insert(data[i]);
	}

	tree.InorderTraversal();
	tree.Print();
	//removes these numbers
	tree.Remove(21);
	tree.Remove(9); 
	tree.Remove(4);
	tree.Remove(18);
	tree.Remove(15);
	tree.Remove(7);

	cout << endl << endl;

	tree.Print();

	cout << endl << endl;
	//traverses after the remove
	tree.InorderTraversal();





}

