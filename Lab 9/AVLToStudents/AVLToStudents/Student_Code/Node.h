#pragma once
#include "NodeInterface.h"

struct Node: public NodeInterface
{

private:


public:
	int data;
	Node* left;
	Node* right;
	int height;
	enum balance_type {LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1};
	
	balance_type balance;
	
	Node(int newData, int newHeight);
	~Node();
	
	int getData();
	
	Node* getLeftChild();
	Node* getRightChild();
	void setData(int newData);
	void setLeftChild(Node* current);
	void setRightChild(Node* current);
	bool hasChild();
	
	bool rightBalance();
	bool leftBalance();
	bool balanceBalance();

	int updateHeight();

	int getHeight();

};