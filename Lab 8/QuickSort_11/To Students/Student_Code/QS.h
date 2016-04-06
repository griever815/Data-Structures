#pragma once

#include "QSInterface.h"
#include <iostream>
#include <array>
#include <sstream>


using namespace std;


class QS : public QSInterface
{
private:

	int currentIndex = 0;
	int currentVolume = 0;
	int cap = 0;
	int* p = NULL;


public:

	QS();
	~QS();


	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray();
	int getSize();
	void addToArray(int value);
	bool createArray(int capacity);
	void clear();

	void recSort(int left, int right);
	



};