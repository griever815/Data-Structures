#include "Queue.h"

using namespace std;

Queue::Queue()
{

}

Queue::~Queue()
{

}


////Function implementation go below here.
bool Queue::find(int car)
{
	if (LL.find(car))
	{
		return true;
	}
	return false;
}

void Queue::push(int car)
{
	LL.insertHead(car);
}

void Queue::removeLast()
{
	LL.remove(LL.at(LL.size()-1));
}

int Queue::top()
{
	return LL.at(LL.size()-1);
}

int Queue::size()
{
	return LL.size();
}