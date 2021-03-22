#include "Node.h"

Node::Node(int value, Node* leftchild, Node* rightchild)
{
	{
		this->value = value;
		left = left;
		right = right;
		height = 0;

	}
}



bool Node::IsLeaf()
{
	if (left == nullptr and right == nullptr)
		return true;
	else
		return false;

}









void Node::UpdateHeight()
{
	int leftheight;
	int rightheight;
	int maxheight;
	if (IsLeaf())
		height = 0;
	else {

		leftheight = (left == nullptr) ? -1 : left->height;
		rightheight = (right == nullptr) ? -1 : right->height;
		maxheight = (leftheight >= rightheight) ? leftheight : rightheight;


		height = maxheight + 1;
	}



}

int Node::BalanceFactor()
{
	int leftheight = (left == nullptr) ? -1 : left->height;
	int rightheight = (right == nullptr) ? -1 : right->height;
	return leftheight - rightheight;
}

