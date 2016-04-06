#include "Deque.h"

using namespace std;

Deque::Deque()
{

}

Deque::~Deque()
{

}

bool Deque::find(int car)
{
	if (LL.find(car))
	{
		return true;
	}
	return false;
}

////Function implementation go below here.
void Deque::push_left(int car)
{
	LL.insertHead(car);
}

void Deque::push_right(int car)
{
	LL.insertTail(car);
}

void Deque::pop_left()
{
	LL.remove(LL.at(0));
}

void Deque::pop_right()
{
	LL.remove(LL.at(LL.size()-1));
}

int Deque::top_left()
{
	return LL.at(0);
}

int Deque::top_right()
{
	return LL.at(LL.size()-1);
}

int Deque::size()
{
	return LL.size();
}
