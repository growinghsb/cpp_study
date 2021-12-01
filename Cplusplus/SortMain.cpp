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
	BubbleSort(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);

	int arrSelection[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	SelectionSort(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);

	int arrInsertion[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	InsertionSort(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);

	int arrQuickSort[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	QuickSort(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);

	return 0;
}
