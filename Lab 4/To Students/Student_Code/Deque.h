#include "LinkedList.h"

#pragma once

class Deque
{
private:

LinkedList<int> LL;

public:

	Deque();
	~Deque();

	
	////add functions below here.

	void push_left(int car);
	void push_right(int car);
	void pop_left();
	void pop_right();
	int top_left();
	int top_right();
	int size();
	bool find(int car);

};