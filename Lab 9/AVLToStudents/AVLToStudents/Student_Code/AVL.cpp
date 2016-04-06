#include "AVL.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

AVL::AVL()
{
	root = NULL;
}


AVL::~AVL()
{
	clear();
}

Node* AVL::getRootNode() 
{
	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/

	return root;
}

bool AVL::add(int data)
{
	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/

	if(this->contains(data) == true) 
	{
		return false;
	}

	if(this->getRootNode() == NULL) 
	{
		this->root = new Node(data, 0);
		return true;
	} 
	else 
	{

		if(this->getRootNode()->getData() == data) 
		{ //duplicate (which was hopefully already caught by contains())
			return false;
		} 
		else 
		{
			if(RecAdd(data, this->getRootNode(), 0)) 
			{
				this->root = balance(this->getRootNode());
				return true;
			}
		}
	}
}

bool AVL::RecAdd(int data, Node* current, int height) 
{
	if(data > current->getData()) 
	{
		
		if(current->getRightChild() == NULL)
		{
			current->setRightChild(new Node(data, height+1));

			if(current->balance == Node::BALANCED)
			{
				return current->rightBalance();
			}
			else if(current->balance == Node::LEFT_HEAVY) 
			{
				return current->balanceBalance();
			}
			return true;
		} 
		else if(current->getRightChild()->getData() == data) 
		{
			return false;
		} 
		else 
		{
			return RecAdd(data, current->getRightChild(), height+1);
		}
	}
	else
	{
		
		if(current->getLeftChild() == NULL) 
		{
			current->setLeftChild(new Node(data, height+1));

			if(current->balance == Node::BALANCED) 
			{
				return current->leftBalance();
			} 
			else if(current->balance == Node::RIGHT_HEAVY) 
			{
				return current->balanceBalance();
			}
			return true;
		} 
		else if(current->getLeftChild()->getData() == data) 
		{
			return false;
		} 
		else 
		{
			return RecAdd(data, current->getLeftChild(), height+1);
		}
	}
}

bool AVL::remove(int data) 
{
	if(this->root == NULL || this->contains(data) == false)
	{
		return false;
	} 
	else
	{
		if(data == this->root->getData() && this->root->getLeftChild() == NULL && this->root->getRightChild() == NULL)
		{
			
			delete this->root;
			this->root = NULL;
			return true;
		} 
		else 
		{
			this->root = RecRemove(data, this->getRootNode());
		}
		this->root = balance(this->getRootNode());
		return true;
	}
}

Node* AVL::RecRemove(int data, Node* current) 
{
	if(data < current->getData()) ////Moves it to the left
	{
		current->left = RecRemove(data, current->getLeftChild());
		return current;
	} 
	else if(data > current->getData()) ////Moves it to the right
	{
		current->right = RecRemove(data, current->getRightChild());
		return current;

	} 
	else 
	{
		if(current->getLeftChild() == NULL && current->getRightChild() == NULL) 
		{
			delete current;
			current = NULL;
		}
		else if(current->getLeftChild() != NULL) 
		{
			current->left = IOP(current, current->left);
		} 
		else if(current->getRightChild() != NULL) 
		{
			Node* temp = current->right;
			delete current;
			current = NULL;
			return temp;
		}

		return current;
	}
}

Node* AVL::IOP(Node* toRemove, Node* current) 
{
	if(current->getRightChild() != NULL) 
	{
		current->right = IOP(toRemove, current->getRightChild());
		return current;
	} 
	else 
	{
		toRemove->setData(current->getData());
		Node* temp = current->getLeftChild();
		delete current;
		current = NULL;
		return temp;
	}
}

bool AVL::contains(int data) 
{
	return RecContains(data, this->getRootNode());
}

bool AVL::RecContains(int data, Node* current) 
{

	if(current == NULL) 
	{
		return false;
	}

	if(data == current->getData()) 
	{
		return true;
	}
	else if(data < current->getData()) 
	{
		return RecContains(data, current->getLeftChild());
	} 
	else 
	{
		return RecContains(data, current->getRightChild());
	}
}

void AVL::clear()
{

	if(this->root!=NULL) 
	{
		if(root->left) 
		{
			deleteNode(this->getRootNode()->getLeftChild());
		}

		if(root->right) 
		{
			deleteNode(this->getRootNode()->getRightChild());
		}

		delete this->root;
		this->root = NULL;
	}
}

void AVL::deleteNode(Node* current)
{
	if(current->getLeftChild() != NULL) 
	{
		deleteNode(current->getLeftChild());
	}

	if(current->getRightChild() != NULL) 
	{
		deleteNode(current->getRightChild());
	}
	
	delete current;
	current = NULL;
}


/*
 * modifies the balance of each node
 */
Node* AVL::balance(Node* current)
{
	//use recursion to go from the leaves to the root via stack
	//functions below will be called as the stack is popped
	if(current->left && current->left->hasChild()) 
	{
		current->left = balance(current->left);
	}

	if(current->right && current->right->hasChild()) 
	{
		current->right = balance(current->right);
	}

	int lh;  ////left height
	int rh; ////right height

	if(!current->left) 
	{
		lh = -1;
	} 
	else 
	{
		lh = current->left->updateHeight();
	}

	if(!current->right) 
	{
		rh = -1;
	} 
	else 
	{
		rh = current->right->updateHeight();
	}

	if(lh - rh > 1) 
	{
		return LeftRebalance(current);
	}

	if(rh - lh > 1) 
	{
		return RightRebalance(current);
	}

	if(lh - rh == 1 && current->leftBalance()) 
	{
		return current;
	}

	if(rh - lh == 1 && current->rightBalance()) 
	{
		return current;
	}

	if(rh - lh == 0 && current->balanceBalance()) 
	{
		return current;
	}

	return current;
}

Node* AVL::LeftRebalance(Node* current) 
{
	Node* LocalRoot = dynamic_cast<Node*>(current);
	
	Node* LeftChild = dynamic_cast<Node*>(current->getLeftChild());
	if(LeftChild->balance == Node::RIGHT_HEAVY) 
	{
		Node* LeftRightChild = dynamic_cast<Node*>(LeftChild->getRightChild());
		if(LeftRightChild->balance == Node::LEFT_HEAVY) 
		{
			LeftChild->balance = Node::BALANCED;
			LeftRightChild->balance = Node::BALANCED;
			LocalRoot->balance = Node::RIGHT_HEAVY;
		} 
		else if(LeftRightChild->balance == Node::BALANCED) 
		{
			LeftChild->balance = Node::BALANCED;
			LeftRightChild->balance = Node::BALANCED;
			LocalRoot->balance = Node::BALANCED;
		} 
		else
		{
			LeftChild->balance = Node::LEFT_HEAVY;
			LeftRightChild->balance = Node::BALANCED;
			LocalRoot->balance = Node::BALANCED;
		}

		current->left = LeftRotate(current->left);

	} 
	else 
	{
		/*
		 * In this case the left child (the new root) and the local root (new 
		 * right child) will both be balanced after the rotation
		 */
		LeftChild->balance = Node::BALANCED;
		LocalRoot->balance = Node::BALANCED;
	}

	current = RightRotate(current);
	return current;
}

Node* AVL::RightRebalance(Node*& current) 
{
	Node* LocalRoot = dynamic_cast<Node*>(current);
	Node* RightChild = dynamic_cast<Node*>(current->getRightChild());
	
	if(RightChild->balance == Node::LEFT_HEAVY) 
	{
		Node* RightLeftChild = dynamic_cast<Node*>(RightChild->getLeftChild());
		if(RightLeftChild->balance == Node::RIGHT_HEAVY) 
		{
			RightChild->balance = Node::BALANCED;
			RightLeftChild->balance = Node::BALANCED;
			LocalRoot->balance = Node::LEFT_HEAVY;
		} 
		else if(RightLeftChild->balance == Node::BALANCED) 
		{
			RightChild->balance = Node::BALANCED;
			RightLeftChild->balance = Node::BALANCED;
			LocalRoot->balance = Node::BALANCED;
		} 
		else 
		{
			RightChild->balance = Node::RIGHT_HEAVY;
			RightLeftChild->balance = Node::BALANCED;
			LocalRoot->balance = Node::BALANCED;
		}

		current->right = RightRotate(current->right);
	} 
	else 
	{
		RightChild->balance = Node::BALANCED;
		LocalRoot->balance = Node::BALANCED;
	}

	current = LeftRotate(current);
	return current;
}

Node* AVL::RightRotate(Node* current) 
{
	int dat = current->getData();
	Node* temp = current->getLeftChild();
	current->left = temp->getRightChild();
	temp->right = current;
	current = temp;

	if(this->getRootNode()->getData() == dat) 
	{
		this->root = current;
	}

	return temp;
}

Node* AVL::LeftRotate(Node*& current) 
{
	int dat = current->getData();
	Node* temp =  current->getRightChild();
	current->right = temp->getLeftChild();
	temp->left = current;

	if(this->getRootNode()->getData() == dat) 
	{
		this->root = temp;
	}

	return temp;
}