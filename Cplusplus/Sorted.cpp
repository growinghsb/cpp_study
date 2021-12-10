#include <iostream>

#include "Sorted.h"
#include "MyStack.h"

using std::cout;
using std::endl;

void RandomSetting(int* arr, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		*(arr + i) = rand() % 100;
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

/*
	������ �̿��� ������ ������
	����Լ� ��� ���� ������
	�ڷᱸ�� ������ �̿��� ����

	�ǹ� ���� �̿��� �� �� ������ ��
	�ǹ� ���� �������� ����Լ���
	�迭�� ���� �ϴ� ������ ���ÿ�
	�ε����� ������ �°� �ִ� �������
	����Լ��� ������� �ʰ� ���� ����.
*/
void QuickSortLoop(int* arr, const int length)
{
	MyStack<int> stack;

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

/*
	�������� ����Լ� �������� ����.
	�ϴ� �� �� ���� ���� �� ������
	�� �迭�� ���� ���� �� �� ū
	�迭�� �����, �� �迭�� ����
	�������� �迭�� ���� �� ū
	�迭�� ����� ���� ������� ����.

	�� �������� �ӽ� �迭�� �ʿ���.
	���� �� �迭�� ��Ƶ� ������
	�ʿ��ϱ� �����̴�.
*/
void MergeSortRecursive(int* arr, int startIndex, int lastIndex)
{
	int tmpArr[100] = {};

	if (startIndex < lastIndex)
	{
		int mid = (lastIndex + startIndex) / 2;
		MergeSortRecursive(arr, startIndex, mid);
		MergeSortRecursive(arr, mid + 1, lastIndex);

		int front = startIndex;
		int back = mid + 1;
		int tmpIdx = startIndex;

		while (front <= mid && back <= lastIndex)
		{
			if (*(arr + front) <= *(arr + back))
			{
				*(tmpArr + tmpIdx) = *(arr + front);
				++front;
			}
			else
			{
				*(tmpArr + tmpIdx) = *(arr + back);
				++back;
			}
			++tmpIdx;
		}
		for (int i = 0; i <= mid - front; ++i)
		{
			*(tmpArr + tmpIdx++) = *(arr + front + i);
		}

		for (int i = startIndex; i < tmpIdx; ++i)
		{
			*(arr + i) = *(tmpArr + i);
		}
	}
}

/*
	���� ������ ����
*/
void MergeSortLoop(int* arr, const int length)
{
}

/*
	�ִ����� ����� �� �˰���.
	�� �� ������ �� ���� �׻�
	Ʈ������ �ִ밪�� ��Ʈ��忡
	��ġ �ϰ� �ϴ� ���� ����Ʈ.
*/
void MaxHeap(int* arr, int lastIndex)
{
	int parentIdx;

	if (0 != lastIndex % 2)
	{
		parentIdx = lastIndex / 2;

		if (*(arr + lastIndex) > *(arr + parentIdx))
		{
			Swap(arr + lastIndex, arr + parentIdx);
		}
		--parentIdx;
	}
	else
	{
		parentIdx = lastIndex / 2 - 1;
	}

	for (; parentIdx >= 0; --parentIdx)
	{
		int childIdx = parentIdx * 2 + 1;

		if (*(arr + childIdx) < *(arr + childIdx + 1))
		{
			++childIdx;
		}

		if (*(arr + childIdx) > *(arr + parentIdx))
		{
			Swap(arr + childIdx, arr + parentIdx);
		}
	}
}

/*
	�������� ���� �� �� �ִ�������
	���� �� ���� �ִ밪�� ��Ʈ ��忡
	��ġ �ϴ� ���� �̿��� �����Ѵ�.

	�� �� �ִ������� ����� ��Ʈ��带
	�迭�� �� �ڿ� ��ġ��Ű��, �� �� ��
	�ִ����� �����, �� �� - 1 �� ��ġ��Ű��
	������ �ڿ��� ���� ä������ ��������
	������ �����Ѵ�.

	�ִ����� ������ ������ n �� ���� �ϰ�,
	�ִ����� �ð����⵵�� log n �̹Ƿ�
	������ �˰����� �ð����⵵��
	O(n log n)�� �ȴ�.
*/
void HeapSort(int* arr, const int length)
{
	for (int i = 1; i < length; ++i)
	{
		MaxHeap(arr, length - i);
		Swap(arr + 0, arr + length - i);
	}
}

void Swap(int* v1, int* v2)
{
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

/*
	������ �� ����� �����ϴ� �ڵ�
	assert() �� �������� ���� ���ϴµ�,
	���� i ��ġ�� ���� i + 1 ��ġ�� ����
	���� �׻� i �� ���� �۰ų� ���ƾ�
	�Ѵٰ� ���� �������Ƿ�,������ �ȵǸ�
	assert ������ �߻��Ѵ�.

	assert() ������ ������ �Ƿ���
	i + 1 ���� �� �۾ƾ� �ϱ� �����̰�,
	�̴� ������ �ȉ�ٴ� �����̱� �����̴�.
*/
void Verification(int* arr, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		assert(*(arr + i) <= *(arr + i + 1));
	}
}

void Print(int* arr, const int length, const char* coment)
{
	cout << coment << endl;

	for (int i = 0; i < length; ++i)
	{
		cout << "[" << *(arr + i) << "] ";
	}
	cout << endl << endl;
}