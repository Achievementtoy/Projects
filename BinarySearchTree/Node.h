#include <iostream>
#pragma once
#include "Observer.h"

class Node{

public:
	Node(int data = 0, Node* left = nullptr, Node* right = nullptr);
	~Node() = default;
	int data;
	Node* leftchild;
	Node* rightchild;
	bool IsLeaf();
	void UpdateHeight();
	int height;
private:
	Observer neededForUnitTest;








};