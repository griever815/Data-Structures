#include "Node.h"
#include <algorithm>

using namespace std;

Node::Node(int newData, int newHeight)
{
		data = newData;
		left = NULL;
		right = NULL;
		height = newHeight;
		balance = BALANCED;
}

Node::~Node()
{
		left = NULL;
		right = NULL;
}


int Node::getData() 
{
	return data;
}

Node* Node::getLeftChild() 
{
	return left;
}

Node* Node::getRightChild() 
{
	return right;
}

int Node::getHeight() 
{
	return height;
}

void Node::setData(int newData) 
{
	data = newData;
}

void Node::setLeftChild(Node* current) 
{
	left = current;
}

void Node::setRightChild(Node* current) 
{
	right = current;
}

bool Node::hasChild() 
{
	return(left != NULL || right != NULL);
}

int Node::updateHeight() 
{

	int lh = -1;
	int rh = -1;

	if(left != NULL) 
	{
		lh = left->updateHeight();
	}

	if(right != NULL) 
	{
		rh = right->updateHeight();
	}

	return max(lh, rh)+1;
}

bool Node::rightBalance() 
{
	this->balance = RIGHT_HEAVY;
	return true;
}

bool Node::leftBalance() 
{
	this->balance = LEFT_HEAVY;
	return true;
}

bool Node::balanceBalance() 
{
	this->balance = BALANCED;
	return true;
}