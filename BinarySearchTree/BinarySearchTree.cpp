#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
#include <string>
#include "Observer.h"
#include "RecursionCounter.h"
using namespace std;
// default
BinarySearchTree::BinarySearchTree()
{
	root = nullptr;

}
//destructor
BinarySearchTree::~BinarySearchTree()
{
	RecursiveDestructor(root);

}
// was failing one test so I made a destructor recursive helper to see if it would fix it
void BinarySearchTree::RecursiveDestructor(Node* cursor)
{
	if (cursor == nullptr) {
		return;
	}
	RecursiveDestructor(cursor->rightchild);
	RecursiveDestructor(cursor->leftchild);
	delete cursor;
}
void BinarySearchTree::Insert(int data)
{
	root = InsertHelper(root, data);
}
// inserts a new node into the tree whether it be a leaf or parent or child
Node* BinarySearchTree::InsertHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;
	//base case
	if (cursor == nullptr) {
		return new Node(data, nullptr, nullptr);
	}
	if (data <= cursor->data) {
		cursor->leftchild = InsertHelper(cursor->leftchild, data);
	}
	else {
		cursor->rightchild = InsertHelper(cursor->rightchild, data);
	}
	cursor->UpdateHeight();
	return cursor;
}

Node* BinarySearchTree::Search(int data)
{
	return SearchHelper(root, data);
}
// user gives the program the data, this finds it and returns it if it is there
Node* BinarySearchTree::SearchHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;

	if (cursor == nullptr)
		return nullptr;

	else if (cursor->data == data)
		return cursor;
	else if (cursor->data < data)
		//had these backwards
		return SearchHelper(cursor->rightchild, data);
	else if (cursor->data > data)
		return SearchHelper(cursor->leftchild, data);

	return cursor;
}

void BinarySearchTree::InorderTraversal()
{
	InorderHelper(root);
	cout << endl;

}
//the recursion for going through the list
void BinarySearchTree::InorderHelper(Node* cursor)
{
	RecursionCounter neededForUnitTest;

	if (cursor == nullptr)
		return;
	InorderHelper(cursor->leftchild);
	cout << cursor->data << ", ";
	InorderHelper(cursor->rightchild);

}

int BinarySearchTree::Size()
{
	return SizeHelper(root);
}
// returns the size of the tree
int BinarySearchTree::SizeHelper(Node* cursor)
{
	RecursionCounter neededForUnitTest;
	if (cursor == nullptr)
		return 0;
	else {

		int left = SizeHelper(cursor->leftchild);
		int right = SizeHelper(cursor->rightchild);
		return left + right + 1;


	}
}

void BinarySearchTree::Remove(int data)
{
	root = RemoveHelper(root, data);
}
// removes one of the nodes to the tree
Node* BinarySearchTree::RemoveHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest; // unit test

	if (cursor == nullptr)
		return nullptr;
	else if (data < cursor->data)
		cursor->leftchild = RemoveHelper(cursor->leftchild, data);
	else if (data > cursor->data)
		cursor->rightchild = RemoveHelper(cursor->rightchild, data);
	else if (cursor->data == data)
	{
		if (cursor->IsLeaf()) {
			delete cursor;
			cursor = nullptr;
			return nullptr;
		}

		else if (cursor->rightchild == nullptr) {
			Node* tmp = cursor;
			cursor = cursor->leftchild;
			delete tmp;
		}
		else if (cursor->leftchild == nullptr) {
			Node* tmp = cursor;
			cursor = cursor->rightchild;
			delete tmp;
		}
		else {
			//Node* successor = cursor->rightchild;
			//while (successor->leftChild != nullptr)
			//successor = successor->leftChild;
			//followed this that we did in class to create this part
			Node* tmp = cursor->rightchild;
			
			while (tmp->leftchild != nullptr) {
				tmp = tmp->leftchild;
			}
			cursor->data = tmp->data;

			cursor->rightchild = RemoveHelper(cursor->rightchild, tmp->data);



		}


	}
	cursor->UpdateHeight();
	return cursor;
}




void BinarySearchTree::Print()
{
	string offset = "";
	PrintHelper(offset, root);
}
// Dana helped me with this, was getting some problems with it
void BinarySearchTree::PrintHelper(std::string& offset, Node* cursor)
{
	RecursionCounter neededForUnitTest;
	//base case
	if (cursor == nullptr)
	{
		cout << offset << "[Empty]" << endl;

	}
	else if (cursor->IsLeaf())
		cout << offset << cursor->data << " (" << cursor->height << ") [leaf]" << endl;
	else {
		cout << offset << cursor->data << " (" << cursor->height << ") " << endl;
		string tmp = offset + "   ";
		PrintHelper(tmp, cursor->leftchild);

		PrintHelper(tmp, cursor->rightchild);
	}

}

