#include<iostream>

#include"Sorted.h"

using std::cout;
using std::endl;

enum class ARR_LENGTH
{
	TEST_LENGTH = 10,
	ORIGINAL_LANGTH = 100
};

int main()
{
	srand(time(0));

	int test[] = { 5,3,2,1,3,6,7,2,1,9 };

	int arrBubble[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "정렬 전");
	BubbleSort(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "BubbleSort 정렬 후");

	int arrSelection[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "정렬 전");
	SelectionSort(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "SelectionSort 정렬 후");

	int arrInsertion[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "정렬 전");
	InsertionSort(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "InsertionSort 정렬 후");

	int arrQuickSort[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "정렬 전");
	QuickSortLoop(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "QuickSort 정렬 후");

	return 0;
}
