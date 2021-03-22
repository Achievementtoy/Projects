#include "Node.h"

Node::Node(int data, Node* left, Node* right)
{
	{
		this->data = data;
		leftchild = left;
		rightchild = right;
		height = 0;

	}
}



bool Node::IsLeaf()
{
	if (leftchild == nullptr and rightchild == nullptr)
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

		leftheight = (leftchild == nullptr) ? -1 : leftchild->height;
		rightheight = (rightchild == nullptr) ? -1 : rightchild->height;
		maxheight = (leftheight >= rightheight) ? leftheight : rightheight;


		height = maxheight + 1;
	}
		
	

}

