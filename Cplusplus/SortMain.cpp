#include<iostream>

#include"Sorted.h"

using std::cout;
using std::endl;

int main()
{
	const int TEST_LENGTH = 5;
	int test[] = { 5,4,3,2,1 };

	const int LENGTH = 100;

	int arrBubble[LENGTH] = {};
	RandomSetting(arrBubble, LENGTH);
	BubbleSort(arrBubble, LENGTH);

	int arrSelection[LENGTH] = {};
	RandomSetting(arrSelection, LENGTH);
	SelectionSort(arrSelection, LENGTH);

	int arrInsertion[LENGTH] = {};
	RandomSetting(arrInsertion, LENGTH);
	InsertionSort(arrInsertion, LENGTH);

	int arrQuickSort[LENGTH] = {};
	//RandomSetting(arrQuickSort, LENGTH);
	QuickSort(test, TEST_LENGTH);

	return 0;
}
