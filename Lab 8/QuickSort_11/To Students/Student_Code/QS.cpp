#include "QS.h"

using namespace std;

QS::QS()
{

}

QS::~QS()
{
	clear();
}


void QS::recSort(int left, int right)
{
	int pivot;
	int sorted;

	if (right - left < 3)
	{
		pivot = medianOfThree(left, right);
		return;
	}

	pivot = medianOfThree(left, right);
	sorted = partition(left, right, pivot);
	string blah = getArray();
	//cout << "array: " << blah << endl;

	recSort(left, sorted -1);
	recSort(sorted+1, right);


}

void QS::sortAll()
{
	/*
	* sortAll()
	*
	* Sorts elements of the array.  After this function is called, every
	* element in the array is less than or equal its successor.
	*
	* Does nothing if the array is empty.
	*/


	//recursiveSort(left index, right index);
	//base case{}if Right - Left < 3, call Mof3 on L and R, and return.

	//action. it calls medianOf3 on left and right. Now it has you have an int pivot = Mof3(L,R).
	//int sorted = partition(L,R,pivot);
	//recSort(L, sorted-1);
	//recSort(sorted+1. R);
	if (p != NULL)
	{
		recSort(0, currentVolume-1);
	}

	
}

int QS::medianOfThree(int left, int right)
{
	/*
	* medianOfThree()
	*
	* The median of three pivot selection has two parts:
	*
	* 1) Calculates the middle index by averaging the given left and right indices:
	*
	* middle = (left + right)/2
	*
	* 2) Then bubble-sorts the values at the left, middle, and right indices.
	*
	* After this method is called, data[left] <= data[middle] <= data[right].
	* The middle index will be returned.
	*
	* Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
	*
	* @param left
	* 		the left boundary for the subarray from which to find a pivot
	* @param right
	* 		the right boundary for the subarray from which to find a pivot
	* @return
	*		the index of the pivot (middle index); -1 if provided with invalid input
	*/

	//left and right index are the two ends of the list.
	//middle = left + right / 2.
	//is value->left > value-> middle.
		//swap them
	//is middle > right
		//swap them

	//is left > middle
		//swap them.

	if (currentVolume < 1)
	{
		return -1;
	}
	if (left < 0)
	{
		return -1;
	}
	if (right > currentVolume -1)
	{
		return -1;
	}
	if (left >= right)
	{
		return -1;
	}

	int middle = (left + right) / 2;

	int temp;

	if (p[left] > p[middle])
	{
		temp = p[left];
		p[left] = p[middle];
		p[middle] = temp;
	}

		if (p[middle] > p[right])
	{
		temp = p[right];
		p[right] = p[middle];
		p[middle] = temp;
	}

		if (p[left] > p[middle])
	{
		temp = p[left];
		p[left] = p[middle];
		p[middle] = temp;
	}

	return middle;
}

int QS::partition(int left, int right, int pivotIndex)
{
	/*
	* Partitions a subarray around a pivot value selected according to
	* median-of-three pivot selection.
	*
	* The values which are smaller than the pivot should be placed to the left
	* of the pivot; the values which are larger than the pivot should be placed
	* to the right of the pivot.
	*
	* Returns -1 if the array is null, if either of the given integers is out of 			
	* bounds, or if the first integer is not less than the second integer, or if the 			 
	* pivot is not between the two boundaries.
	*
	* @param left
	* 		the left boundary for the subarray to partition
	* @param right
	* 		the right boundary for the subarray to partition
	* @param pivotIndex
	* 		the index of the pivot in the subarray
	* @return
	*		the pivot's ending index after the partition completes; -1 if
	* 		provided with bad input
	*/

	//pivot is still the middle
	///move 
	// 1. swap left and pivot
	// 2. up starts at left + 1. Up++ until value->up is greater than left.
			//down starts at right. down-- until value ->down < left.
			//if up < down, then swap them.
			//when up> down, 
	// 3. Swap left and down. move pivot back to the middle. 

	if (p == NULL)
	{
		return -1;
	}
	if (currentVolume < 1)
	{
		return -1;
	}
	if (left < 0)
	{
		return -1;
	}
	if (right > currentVolume -1)
	{
		return -1;
	}
	if (left >= right)
	{
		return -1;
	}
	if (left > pivotIndex || right <= pivotIndex)
	{
		return -1;
	}
	if (right - left < 2)
	{
		return -1;
	}
	
	int temp = p[left];
	p[left] = p[pivotIndex];
	p[pivotIndex] = temp;

	int up = left + 1;
	int down = right;

	while(up < down)
	{
		while(up < currentVolume && p[up] <= p[left])
		{
			up++;
		}

		while(down >= 0 && p[down] > p[left])
		{
			down--;
		}

		if (up < down)
		{
			int newTemp = p[up];
			p[up] = p[down];
			p[down] = newTemp;

		}
	}

	temp = p[left];
	p[left] = p[down];
	p[down] = temp;

	return down;

}

 string QS::getArray()
 {
	/*
	* Produces a comma delimited string representation of the array. For example: if my array
	* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0" 			 
	* with no trailing comma.  The number of cells included equals the number of values added.
	* Do not include the entire array if the array has yet to be filled.
	*
	* Returns an empty string, if the array is NULL or empty.
	*
	* @return
	*		the string representation of the current array
	*/
	stringstream ss;

	for (int i = 0; i < currentVolume; ++i)
	{

		ss << p[i];
		if (i+1 != currentVolume)
		{
			ss << ",";
		}
		
	}

	return ss.str();

 }

 int QS::getSize()
 {
	/*
	* Returns the number of elements which have been added to the array.
	*/

	return currentVolume;
 }

 void QS::addToArray(int value)
 {

	/*
	* Adds the given value to the end of the array starting at index 0.
	* For example, the first time addToArray is called,
	* the give value should be found at index 0.
	* 2nd time, value should be found at index 1.
	* 3rd, index 2, etc up to its max capacity.
	*
	* If the array is filled, do nothing.
	*/
	
		if (cap > currentVolume)
		{
			p[currentIndex] = value;
			currentVolume++;
			currentIndex++;
		}
	
	

 }

 bool QS::createArray(int capacity)
 {
	/*
	* Dynamically allocates an array with the given capacity.
	* If a previous array had been allocated, delete the previous array.
	* Returns false if the given capacity is non-positive, true otherwise.
	*
	* @param
	*		size of array
	* @return
	*		true if the array was created, false otherwise
	*/

	cap = capacity;

	if (p != NULL)
	{
		delete p;
		p = NULL;
	}	

	if (capacity > 0)
	{
		p = new int[capacity];
		return true;
	}
	else
	{
		return false;
	}
	

 }

 void QS::clear()
 {
	/*
	* Resets the array to an empty or NULL state.
	*/

	delete [] p;
	currentIndex = 0;
	currentVolume = 0;
	cap = 0;
	p = NULL;



 }