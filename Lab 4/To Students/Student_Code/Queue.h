#include "LinkedList.h"

#pragma once

class Queue
{
private:

LinkedList<int> LL;

public:

	Queue();
	~Queue();

	bool find(int car);

	////add functions below here.
	void push(int car);
	void removeLast();
	int top();
	int size();
};