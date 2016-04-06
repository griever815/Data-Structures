#include "StationInterface.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"

#pragma once





class Station : public StationInterface
{
private:

Stack myStack;
Queue myQueue;
Deque myDeque;

int currentCar = -1;


public:

	Station();
	~Station();

	bool find(int car);

////Part 1
	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();

////Part 2
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();

////Part 3
	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();

////Part 4
	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();

};
