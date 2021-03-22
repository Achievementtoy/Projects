#include <random>
#include <algorithm>
#include <cassert>
#include <iostream>

#include "Sort.h"
using namespace std;


int Sort::GetSize() const
{
	return size;
}

int* Sort::GetDataArray() const
{
	return data;
}


void Sort::QuickSort()
{
	QuickSortRecursionHelper(0, size - 1);
}

void Sort::printarray()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << ", " << endl;
	}
}

void Sort::QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE

	if (initialLowIndex >= initialHighIndex)
		return;

	int pivot = partition(initialLowIndex, initialHighIndex);
	QuickSortRecursionHelper(initialLowIndex, pivot - 1);
	QuickSortRecursionHelper(pivot + 1, initialHighIndex);


}

int Sort::partition(int lowIndex, int highIndex)
{
	int pivotnumber = data[highIndex];
	int pivotstart = lowIndex;

	for (int i = lowIndex; i < highIndex; ++i)
	{
		if (data[i] <= pivotnumber)
		{
			int temp = data[i];
			data[i] = data[pivotstart];
			data[pivotstart] = temp;
			pivotstart++;
		}
	}
	int temp = data[pivotstart];
	data[pivotstart] = data[highIndex];
	data[highIndex] = temp;

	return pivotstart;
}

Sort::Sort(int size)
{
	assert(size > 0);

	data = new int[size];
	this->size = size;

	InitArray();

}

Sort::~Sort()
{
	delete[] data;
}

void Sort::InitArray()
{
	srand(0);
	for (int i = 0; i < size; i++)
	{
		//data[i] = (rand() + 1) * (rand() % 10000 + 1);
		data[i] = rand() % size;
	}


}

void Sort::SelectionSort()
{
	int bottom = 0;
	int temp = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		bottom = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (data[j] < data[bottom])
				bottom = j;
		}
		temp = data[i];
		data[i] = data[bottom];
		data[bottom] = temp;
	}

}

void Sort::InsertionSort()
{
	int nested;
	for (int i = 1; i < size; ++i)
	{
		nested = i;
		while (nested > 0 && data[nested] < data[nested - 1])
		{

			int temp = data[nested];
			data[nested] = data[nested - 1];
			data[nested - 1] = temp;
			--nested;

		}

	}
}

void Sort::AlgorithmSort()
{
	std::sort(data, data + size);
}

void Sort::MergeSort()
{

	MergeSortRecursionHelper(0, size - 1);

}
void Sort::MergeSortRecursionHelper(int startindex, int endindex)
{

	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE

	if (startindex >= endindex)
		return;

	int middleindex = (startindex + endindex) / 2;

	MergeSortRecursionHelper(startindex, middleindex);
	MergeSortRecursionHelper(middleindex + 1, endindex);

	Merge(startindex, middleindex, endindex);


}


void Sort::Merge(int startindex, int middleindex, int endindex)
{

	int tsize = (endindex - startindex) + 1;
	int* temp;
	temp = new int[tsize];

	int middleindextemp = middleindex + 1;
	int	counter = 0;
	while (startindex <= middleindex && middleindextemp <= endindex) {
		if (data[startindex] <= data[middleindextemp]) {
			temp[counter] = data[startindex];
			++startindex;
			

		}
		else {
			temp[counter] = data[middleindextemp];;
			++middleindextemp;

		}
		++counter;
	}
	while (startindex <= middleindex) {
		temp[counter] = data[startindex];
		++counter;
		++startindex;


	}
	while (middleindextemp <= endindex) {
		temp[counter] = data[middleindextemp];
		++counter;
		++middleindextemp;
	}

	/*for (counter = 0; counter < tsize; counter++)
	{
		data[startindex + counter] = temp[counter];

	}*/

	delete[] temp;

}
