#pragma once
#include <string>
#include "Node.h"


class AVLTree
{

public:
	AVLTree();
	~AVLTree();
	void Insert(int data);
	void Print();
	void PreOrderTraversal();
	Node* GetRoot();
	



private: 
	Node* InsertHelper(Node* cursor, int data);
	void PrintHelper(std::string& offset, Node* cursor);
	void PreorderHelper(Node* cursor);
	void RecursiveDestructor(Node* cursor);
	Node* Rebalance(Node* cursor);
	Node* RR(Node* cursor);
	Node* RL(Node* cursor);
	Node* LL(Node* cursor);
	Node* LR(Node* cursor);
	Node* root;









};

