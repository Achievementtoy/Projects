#include <iostream>
#pragma once
#include "Observer.h"

class Node {

public:
	Node(int value = 0, Node* leftchild = nullptr, Node* rightchild = nullptr);
	~Node() = default;
	int value;
	Node* left;
	Node* right;
	bool IsLeaf();
	void UpdateHeight();
	int height;
	int BalanceFactor();
	Observer observer;



};