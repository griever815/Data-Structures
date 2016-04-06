#include "Station.h"

using namespace std;

Station::Station()
{

}

Station::~Station()
{

}


bool Station::find(int car)
{
	if(myStack.find(car))
	{
		return true;
	}

	if(myQueue.find(car))
	{
		return true;
	}
	if(myDeque.find(car))
	{
		return true;
	}

	return false;

}


//Part 1--------------------------------------------------------------
bool Station::addToStation(int car)
{
/**
 * Let another car arrive at the station and become the current car.
 * Do not allow a new car to arrive if any of the following conditions apply:
 * 1.	There is already a current car
 * 2.	The new car's ID already exists in any structure
 * 3.	The new car's ID is negative
 *
 * @param car the ID of the car arriving at the station
 * @return true if the car successfully arrived; false otherwise
*/

if(currentCar != -1)
{
	return false;
}

if(find(car))
{
	return false;
}

if(car < 0 )
{
	return false;
}

currentCar = car;

return true;


}

int Station::showCurrentCar()
{
/**
* Returns the ID of the current car.
* Return -1 if there is no current car.
*
* @return the ID of the current car; -1 if there is no current car
*/

	return currentCar;
}

bool Station::removeFromStation()
{
/**
* Removes the current car from the station.
* Does nothing if there is no current car.
*
* @return true if the current car successfully left; false otherwise
*/

	if (currentCar == -1)
	{
		return false;
	}

	currentCar = -1;

	return true;


}

//Part 2--------------------------------------------------------------
bool Station::addToStack()
{
/**
* Adds the current car to the stack.  After this operation, there should be no current car.
* Does nothing if there is no current car or if the stack is already full.
*
* @return true if the car is successfully added to the stack; false otherwise
*/


	if (currentCar != -1 && myStack.size() < 5)
	{
		myStack.push(currentCar);
		currentCar = -1;
		return true;
	}

	return false;
}


bool Station::removeFromStack()
{
/**
* Removes the first car in the stack and makes it the current car.
* Does nothing if there is already a current car or if the stack already empty.
*
* @return true if the car is successfully removed from the stack; false otherwise
*/

	if(currentCar != -1)
	{
		return false;
	}	

	currentCar = myStack.top();
	myStack.pop();
	return true;

}

int Station::showTopOfStack()
{
/**
* Returns the ID of the first car in the stack.
*
* @return the ID of the first car in the stack; -1 if the stack is empty
*/

	if (myStack.size() < 1)
	{
		return -1;
	}

	return myStack.top();

}

int Station::showSizeOfStack()
{
/**
* Returns the number of cars in the stack.
*
* @return the number of cars in the stack
*/

	return myStack.size();

}

//Part 3--------------------------------------------------------------
bool Station::addToQueue()
{
/**
* Adds the current car to the queue.  After this operation, there should be no current car.
* Does nothing if there is no current car or if the queue is already full.
*
* @return true if the car is successfully added to the queue; false otherwise
*/

	if (currentCar != -1 && myQueue.size() < 5)
	{
		myQueue.push(currentCar);
		currentCar = -1;
		return true;
	}

	return false;

}

bool Station::removeFromQueue()
{
/**
* Removes the first car in the queue and makes it the current car.
* Does nothing if there is already a current car or if the queue already empty.
*
* @return true if the car is successfully removed from the queue; false otherwise
*/

	if (myQueue.size() < 1 || currentCar != -1)
	{
		return false;
	}

	currentCar = myQueue.top();
	myQueue.removeLast();
	currentCar = -1;

	return true;


}

int Station::showTopOfQueue()
{
/**
* Returns the ID of the first car in the queue.
*
* @return the ID of the first car in the queue; -1 if the queue is empty
*/

	if (myQueue.size() < 1)
	{
		return -1;
	}

	return myQueue.top();

}

int Station::showSizeOfQueue()
{
/**
* Returns the number of cars in the queue.
*
* @return the number of cars in the queue
*/

	return myQueue.size();

}

//Part 4--------------------------------------------------------------
bool Station::addToDequeLeft()
{
/**
* Adds the current car to the deque on the left side.  After this operation, there should be no current car.
* Does nothing if there is no current car or if the deque is already full.
*
* @return true if the car is successfully added to the deque; false otherwise
*/

	if (currentCar != -1 && myDeque.size() < 5)
	{
		myDeque.push_left(currentCar);
		currentCar = -1;
		return true;
	}

	return false;

}

bool Station::addToDequeRight()
{
/**
* Adds the current car to the deque on the right side.  After this operation, there should be no current car.
* Does nothing if there is no current car or if the deque is already full.
*
* @return true if the car is successfully added to the deque; false otherwise
*/

	if (currentCar != -1 && myDeque.size() < 5)
	{
		myDeque.push_right(currentCar);
		currentCar = -1;
		return true;
	}

	return false;
}

bool Station::removeFromDequeLeft()
{
/**
* Removes the leftmost car in the deque and makes it the current car.
* Does nothing if there is already a current car or if the deque already empty.
*
* @return true if the car is successfully removed from the deque; false otherwise
*/

	if (myDeque.size() < 0 || currentCar != -1)
	{
		return false;
	}

	currentCar = myDeque.top_left();
	myDeque.pop_left();
	currentCar = -1;

	return true;

}

bool Station::removeFromDequeRight()
{
/**
* Removes the rightmost car in the deque and makes it the current car.
* Does nothing if there is already a current car or if the deque already empty.
*
* @return true if the car is successfully removed from the deque; false otherwise
*/

	if (myDeque.size() < 0 || currentCar != -1)
	{
		return false;
	}

	currentCar = myDeque.top_right();
	myDeque.pop_right();
	currentCar = -1;

	return true;

}

int Station::showTopOfDequeLeft()
{
/**
* Returns the ID of the leftmost car in the deque.
*
* @return the ID of the leftmost car in the deque; -1 if the deque is empty
*/

	if (myDeque.size() < 1)
	{
		return -1;
	}

	return myDeque.top_left();

}

int Station::showTopOfDequeRight()
{
/**
* Returns the ID of the rightmost car in the deque.
*
* @return the ID of the rightmost car in the deque; -1 if the deque is empty
*/

	if (myDeque.size() < 1)
	{
		return -1;
	}

	return myDeque.top_right();

}

int Station::showSizeOfDeque()
{
/**
* Returns the number of cars in the deque.
*
* @return the number of cars in the deque
*/

	return myDeque.size();

}