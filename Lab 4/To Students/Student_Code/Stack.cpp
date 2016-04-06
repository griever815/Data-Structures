#include "Stack.h"

using namespace std;


Stack::Stack()
{

}

Stack::~Stack()
{

}

////Function implementation go below here.

bool Stack::find(int car)
{
	if (LL.find(car))
	{
		return true;
	}
	return false;
}

void Stack::push(int car)
{
	LL.insertHead(car);
}

void Stack::pop()
{
	LL.remove(LL.at(0));
}

int Stack::top()
{
	return LL.at(0);
}

int Stack::size()
{
	return LL.size();
}