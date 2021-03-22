#include "AVLTree.h"
#include <string>
#include <iostream>
#include <cassert>
#include "Node.h"
using namespace std;

/********************************************************************************************
**	Project: AVLTree
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



AVLTree::AVLTree()  
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
	RecursiveDestructor(root);
	root = nullptr;
}

void AVLTree::RecursiveDestructor(Node* cursor)
{
	if (cursor == nullptr) {
		return;
	}
	RecursiveDestructor(cursor->right);
	RecursiveDestructor(cursor->left);
	delete cursor;
}

void AVLTree::Insert(int data)
{
	root = InsertHelper(root, data);
}
//Inserts and rebalances the nodes inserted
Node* AVLTree::InsertHelper(Node* cursor, int data)
{
	if (cursor == nullptr) {
		return new Node(data, nullptr, nullptr);
	}
	if (data <= cursor->value) {
		cursor->left = InsertHelper(cursor->left, data);
	}
	else {
		cursor->right = InsertHelper(cursor->right, data);
	}
	cursor->UpdateHeight();
	cursor = Rebalance(cursor);
	return cursor;
}

void AVLTree::Print()
{
	string offset = "";
	PrintHelper(offset, root);
}
//Prints the balanced avl tree
void AVLTree::PrintHelper(std::string& offset, Node* cursor)
{
	if (cursor == nullptr)
	{
		cout << offset << "[Empty]" << endl;

	}
	else if (cursor->IsLeaf())
		cout << offset << cursor->value << " (" << cursor->height << ") [leaf]" << endl;
	else {
		cout << offset << cursor->value << " (" << cursor->height << ") " << endl;
		string tmp = offset + "   ";
		PrintHelper(tmp, cursor->left);

		PrintHelper(tmp, cursor->right);
	}
}
//Traverses in pre order
void AVLTree::PreOrderTraversal()
{
	PreorderHelper(root);
	cout << endl;
}
//unit tests
Node* AVLTree::GetRoot()
{
	return root;
}

void AVLTree::PreorderHelper(Node* cursor)
{
	if (cursor == nullptr)
		return;
	cout << cursor->value << ", ";
	PreorderHelper(cursor->left);
	PreorderHelper(cursor->right);
}
// Next four functions are the rotations
Node* AVLTree::RR(Node* cursor)
{
	assert(cursor->left != nullptr);
	Node* tmp = cursor->left;
	cursor->left = tmp->right;
	tmp->right = cursor;
	cursor->UpdateHeight();
	tmp->UpdateHeight();
	return tmp;
}

Node* AVLTree::LL(Node* cursor)
{
	assert(cursor != nullptr);
	assert(cursor->right != nullptr);
	Node* tmp1 = cursor->right;
	cursor->right = tmp1->left;
	tmp1->left = cursor;
	cursor->UpdateHeight();
	tmp1->UpdateHeight();
	return tmp1;
}

Node* AVLTree::RL(Node* cursor)
{
	cursor->right = RR(cursor->right);
	return LL(cursor);

}

Node* AVLTree::LR(Node* cursor)
{
	cursor->left = LL(cursor->left);
	return RR(cursor);
}
//Dana Helped me figure this out
Node* AVLTree::Rebalance(Node* cursor)
{
	int Balancefactor = cursor->BalanceFactor();

	if (Balancefactor > -2 and Balancefactor < 2) {
		return cursor;
	}

	if (Balancefactor < -1) {
		if (cursor->right->BalanceFactor() < 0) {
			cursor = LL(cursor);
		}
		else {
			cursor = RL(cursor);
		}

	}
	if (Balancefactor > 1) {
		if (cursor->left->BalanceFactor() > 0) {
			cursor = RR(cursor);
		}
		else {
			cursor = LR(cursor);
		}
	}
	return cursor;
}
