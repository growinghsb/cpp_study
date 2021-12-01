#include <iostream>
#include <ctime>

#include "Sorted.h"
#include "MyStack.h"

using std::cout;
using std::endl;

void RandomSetting(int* arr, const int length)
{
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
		int start = 0;
		int end = 0;

		if (0 == stack.GetSize())
		{
			end = length - 1;
		}
		else
		{
			end = stack.Pop();
			start = stack.Pop();
		}

		if (start < end)
		{
			int pivot = start;
			int right = start + 1;
			int left = end;

			while (right <= left)
			{
				while (*(arr + right) <= *(arr + pivot) && right < end)
				{
					++right;
				}

				while (*(arr + left) >= *(arr + pivot) && left > start)
				{
					--left;
				}

				if (right < left)
				{
					Swap(arr + right, arr + left);
				}
				else
				{
					Swap(arr + pivot, arr + left);
				}
			}
			stack.Push(left + 1);
			stack.Push(end);
			stack.Push(start);
			stack.Push(right - 1);
		}
		else
		{
			if (0 == stack.GetSize())
			{
				break;
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

void Verification(int* arr, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		assert(*(arr + i) <= *(arr + i + 1));
	}
}

void Print(int* arr, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << "[" << *(arr + i) << "] ";
	}
	cout << endl;
}