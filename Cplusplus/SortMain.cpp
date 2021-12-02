#include<iostream>

#include"Sorted.h"

using std::cout;
using std::endl;

enum class ARR_LENGTH
{
	TEST_LENGTH = 5,
	ORIGINAL_LANGTH = 100
};

int main()
{
	srand(time(0));

	int test[] = { 5,4,3,2,1 };

	int arrBubble[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "���� ��");
	BubbleSort(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrBubble, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "BubbleSort ���� ��");

	int arrSelection[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "���� ��");
	SelectionSort(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrSelection, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "SelectionSort ���� ��");

	int arrInsertion[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "���� ��");
	InsertionSort(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrInsertion, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "InsertionSort ���� ��");

	int arrQuickSort[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "���� ��");
	QuickSortLoop(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrQuickSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "QuickSort ���� ��");

	int arrMergeSortRecursive[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrMergeSortRecursive, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrMergeSortRecursive, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "���� ��");
	MergeSortRecursive(arrMergeSortRecursive, 0, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH - 1);
	Verification(arrMergeSortRecursive, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrMergeSortRecursive, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "MergeSortRecursive ���� ��");
	
	return 0;
}
