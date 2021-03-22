#pragma once
#include <string>
#include "Node.h"


class BinarySearchTree
{

public:
	BinarySearchTree();
	//post order traversal
	~BinarySearchTree();
	void Insert(int data);
	void Print();
	Node* Search(int data);
	void InorderTraversal();
	int Size();
	void Remove(int data);
	


private:
	Node* root;
	Node* InsertHelper(Node* cursor, int data);
	void PrintHelper(std::string& offset, Node* cursor);
	Node* SearchHelper(Node* cursor, int data);
	void InorderHelper(Node* cursor);
	int SizeHelper(Node* cursor);
	Node* RemoveHelper(Node* cursor, int data);
	void RecursiveDestructor(Node* cursor);









};

