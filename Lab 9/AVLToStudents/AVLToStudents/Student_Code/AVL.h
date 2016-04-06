
#pragma once
#include <string>
#include "Node.h"
#include "AVLInterface.h"

using namespace std;

class AVL: public AVLInterface
{

private:



public:
	
	Node* root;
	
	AVL();
	~AVL();

	Node* getRootNode();
	bool add(int data);
	bool RecAdd(int data, Node* current, int height);
	bool remove(int data);
	Node* RecRemove(int data, Node* current);
	Node* IOP(Node* toRemove, Node* current);
	bool contains(int data);
	bool RecContains(int data, Node* current);
	
	Node* balance(Node* current);
	
	void deleteNode(Node* current);
	void clear();
	
	Node* LeftRebalance(Node* current);
	Node* RightRebalance(Node*& current);
	
	Node* RightRotate(Node* current);
	Node* LeftRotate(Node*& current);

};
