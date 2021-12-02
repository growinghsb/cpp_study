#include<iostream>

#include"Sorted.h"

using std::cout;
using std::endl;

enum class ARR_LENGTH
{
	TEST_LENGTH = 12,
	ORIGINAL_LANGTH = 23
};

int main()
{
	srand(time(0));

	int test[] = { 5, 6, 9, 4, 3, 8, 2, 0, 1, 3, 6, 9 };

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

	int arrHeapSort[(unsigned int)ARR_LENGTH::ORIGINAL_LANGTH] = {};
	RandomSetting(arrHeapSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrHeapSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "���� ��");
	HeapSort(arrHeapSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Verification(arrHeapSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH);
	Print(arrHeapSort, (unsigned int)ARR_LENGTH::ORIGINAL_LANGTH, "HeapSort ���� ��");

	return 0;
}
