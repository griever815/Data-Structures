#include "LinkedList.h"

#pragma once

class Stack
{
private:

LinkedList<int> LL;

public:

	Stack();
	~Stack();

	////add functions below here.

	bool find(int car);

	void push(int car);
	void pop();
	int top();
	int size();

};