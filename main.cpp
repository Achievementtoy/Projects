/********************************************************************************************
**	Project: Sort
**  Programmer: Garrett Cook
**  Course:		cs2420
**	Section:	001
**	Assignment: 5
**	Data:		Sept 29, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"

using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;
int main() {


	int array = 500;
	Sort sort(array);
	Timer t;

	
	
	cout << "starting SelectionSort" << endl;
	t.Start();
	sort.SelectionSort();
	t.End();
	cout << "Selection sort duration " << t.DurationInMilliSeconds() << "ms" << endl << endl;
	sort.printarray();

	;
	cout << "Starting Insertion sort" << endl;
	t.Start();
	sort.InsertionSort();
	t.End();
	cout << "Insertion sort duration " << t.DurationInMilliSeconds() << "ms" << endl << endl;
	sort.printarray();

	
	cout << "Starting merge sort" << endl;
	t.Start();
	sort.MergeSort();
	t.End();
	cout << "Merge sort duration " << t.DurationInMilliSeconds() << "ms" << endl << endl;
	sort.printarray();

	
	cout << "Starting Quicksort sort" << endl;
	t.Start();
	sort.QuickSort();
	t.End();
	cout << "Quick sort duration " << t.DurationInMilliSeconds() << "ms" << endl << endl;
	sort.printarray();

	
	cout << "Starting  std::sort()" << endl;
	t.Start();
	sort.AlgorithmSort();
	t.End();
	cout << " std::sort() duration " << t.DurationInMilliSeconds() << "ms" << endl << endl;
	sort.printarray();










	return 0;
}
