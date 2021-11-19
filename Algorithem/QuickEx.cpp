#include <iostream>
#include "QuickEx.h"

static void QuickSort(int* arr, int start, int end);
static void QuickDivide(int* arr, int start, int end);

int mainExEx()
{
	int tmp[] = { 5, 4, 3, 2, 1 };

	QuickSort(tmp, 0, 4);

	return 0;
}

void QuickSort(int* arr, int start, int end)
{
	QuickDivide(arr, start, end);
}

void QuickDivide(int* arr, int start, int end)
{
	if (start < end)
	{
		int pivotIdx = start;
		int startIdx = start + 1;
		int endIdx = end;

		while (startIdx < endIdx)
		{
			while (*(arr + startIdx) <= *(arr + pivotIdx) && startIdx < end)
			{
				++startIdx;
			}

			while (*(arr + endIdx) >= *(arr + pivotIdx) && endIdx > start)
			{
				--endIdx;
			}

			if (startIdx < endIdx)
			{
				int t = arr[startIdx];
				arr[startIdx] = arr[endIdx];
				arr[endIdx] = t;
			}
			else 
			{
				int t = arr[endIdx];
				arr[endIdx] = arr[pivotIdx];
				arr[pivotIdx] = t;
			}
		}
		QuickDivide(arr, start, endIdx - 1);
		QuickDivide(arr, endIdx + 1, end);
	}
}