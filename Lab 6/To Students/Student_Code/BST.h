#pragma once

#include "BSTInterface.h"
#include "Node.h"





class BST : public BSTInterface
{
private:

	



public:

	Node* root;


	BST();
	~BST();

	NodeInterface * getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();

	bool addRecursive(int newData, Node*& current);
	bool removeRecursive(int newData, Node*& current);
	void IOP(Node*& toRemove, Node*& current);


};

