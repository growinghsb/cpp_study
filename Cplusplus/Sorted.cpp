#include <iostream>
#include <ctime>

#include "Sorted.h"
#include "MyStack.h"

using std::cout;
using std::endl;

void RandomSetting(int* arr, const int length)
{
	srand(rand() % 10);

	for (int i = 0; i < length; ++i)
	{
		*(arr + i) = rand() % 1000;
	}
}

void BubbleSort(int* arr, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - (i + 1); ++j)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				Swap(arr + j, arr + j + 1);
			}
		}
	}
}

void SelectionSort(int* arr, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (*(arr + minIdx) > *(arr + j))
			{
				minIdx = j;
			}
		}
		Swap(arr + i, arr + minIdx);
	}
}

void InsertionSort(int* arr, const int length)
{
	for (int i = 1; i < length; ++i)
	{
		int targetValue = *(arr + i);
		int j = i;
		for (; j > 0; --j)
		{
			if (*(arr + j - 1) > targetValue)
			{
				*(arr + j) = *(arr + j - 1);
			}
			else
			{
				break;
			}
		}
		*(arr + j) = targetValue;
	}
}

void QuickSort(int* arr, const int length)
{
	MyStack stack;

	while (true)
	{
		int pivotIdx;
		int inputIdx;
		int startIdx;

		if (0 == stack.GetSize())
		{
			pivotIdx = length - 1;
			inputIdx = 0;
			startIdx = 0;
		}
		else
		{
			pivotIdx = stack.Pop();
			inputIdx = stack.Pop();
			startIdx = inputIdx;
		}

		while (startIdx < pivotIdx)
		{
			if (*(arr + startIdx) < *(arr + pivotIdx))
			{
				Swap(arr + inputIdx, arr + startIdx);
				++inputIdx;
				++startIdx;
			}
			else
			{
				++startIdx;
			}

			if (startIdx == pivotIdx)
			{
				Swap(arr + inputIdx, arr + pivotIdx);

				stack.Push(inputIdx + 1);
				stack.Push(length - 1);
				stack.Push(0);
				stack.Push(inputIdx - 1);
			}
		}
	}
}

void Swap(int* v1, int* v2)
{
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void Print(int* arr, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << "[" << *(arr + i) << "] ";
	}
	cout << endl;
}