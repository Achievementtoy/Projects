#ifndef __SORT__
#define __SORT__

#include "RecursionCounter.h"
#include <cstdlib>
class Sort
{
public:
	Sort(int size);
	~Sort();

	void InitArray();

	void SelectionSort();
	void InsertionSort();
	void AlgorithmSort();
	void MergeSort();
	void QuickSort();
	void printarray();



	int GetSize() const;
	int* GetDataArray() const;
private:


	void MergeSortRecursionHelper(int startindex, int endindex);
	void Merge(int startindex, int middleindex, int endindex);
	void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
	int partition(int lowIndex, int highIndex);
	int* data;
	int size;
};

#endif

