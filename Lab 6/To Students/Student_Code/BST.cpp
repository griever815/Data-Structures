#include "BST.h"

using namespace std;

BST::BST()
{
	root = NULL;
}


BST::~BST()
{

}


NodeInterface* BST::getRootNode()
{
	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	return root;

}


bool BST::add(int data)
{
	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	//cout << "add: " << data << endl;
	bool added = addRecursive(data, root);

	if (added)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool BST::remove(int data)
{
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool removed = removeRecursive(data, root);
	if (removed)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void BST::clear()
{
	while(root != NULL)
	{
		bool cleared = remove(root->data);
	}
}


bool BST::addRecursive(int newData, Node*& current)
{

	if (current == NULL)
	{
		current = new Node(newData);
		if (root == NULL)
		{
			root = current;
		}
		return true;
	}
	else
	{
		if (current->data > newData) //Moves to the left
		{
			return addRecursive(newData, current->left);
		}
		if (current->data < newData) //Moves to the right
		{
			return addRecursive(newData, current->right);
		}
		else  //Do not allow duplicates
		{
			return false;
		}
	}
}



bool BST::removeRecursive(int newData, Node*& current)
{
	
	if (current == NULL) //// If it cant find it, then it returns false.
	{
		return false;
	}
	else
	{
		if (current->data > newData) //Moves to the left
		{
			return removeRecursive(newData, current->left);
		}
		if (current->data < newData) //Moves to the right
		{
			return removeRecursive(newData, current->right);
		}
		if (current->data == newData)  //Do not allow duplicates
		{
			if (current->left == NULL && current->right == NULL) //If there are 0 children nodes
			{
				delete current;
				current = NULL;
				return true;
			}
			if (current->left != NULL && current->right == NULL) //If there is a left child node, but no right.
			{
				Node* temp = current->left;
				delete current;
				current = temp;
				return true;
			}
			if (current->left == NULL && current->right != NULL) //If there is a right child node, but no left.
			{
				Node* temp = current->right;
				delete current;
				current = temp;
				return true;
			}
			if (current->left != NULL && current->right != NULL) //If there are 2 children nodes
			{
				IOP(current, current->left);
			}
		}
	}
}

void BST::IOP(Node*& toRemove, Node*& current) ////Current is the one step to the left
{
	if(current->right != NULL)
	{
		return IOP(toRemove, current->right); //Recurses to the far most right one. 
	}

	toRemove->setValue(current->data);  // Sets the value of the node to the IOP.

	if (current->left != NULL) //// We then delete the node further down the list.
	{
		Node* temp = current->left;
		delete current;
		current = temp;
	}
	else
	{
		delete current;
		current = NULL;
	}	
}




