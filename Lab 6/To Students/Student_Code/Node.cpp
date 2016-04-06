#include "Node.h"

using namespace std;

Node::Node(int newData)
{
	data = newData;
	left = NULL;
	right = NULL;
}

Node::~Node()
{

}

int Node::getData()
{
	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/

	return data;
}

NodeInterface * Node::getLeftChild()
{
	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/

	return left;
}

NodeInterface * Node::getRightChild()
{
	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/

	return right;
}

void Node::setValue(int value) ///Instead of deleting the node, I change its value to its in order predecesor. 
{
	data = value;
}