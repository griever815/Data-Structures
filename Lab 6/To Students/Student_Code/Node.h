#pragma once

#include "NodeInterface.h"



class Node : public NodeInterface
{
private:


public:

	int data;
	Node* left;
	Node* right;

	Node(int newData);
	~Node();

	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();

	void setValue(int newData);


};