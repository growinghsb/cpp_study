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
	루프를 이용해 구현한 퀵정렬
	재귀함수 대신 직접 구현한
	자료구조 스택을 이용해 구현

	피벗 값을 이용해 한 번 정렬한 후
	피벗 값을 기준으로 재귀함수로
	배열을 분할 하는 과정을 스택에
	인덱스를 순서에 맞게 넣는 방식으로
	재귀함수를 사용하지 않고 구현 가능.
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
	병합정렬 재귀함수 버전으로 구현.
	일단 될 때 까지 나눈 뒤 나눠진
	두 배열을 서로 비교해 좀 더 큰
	배열로 만들고, 그 배열과 같은
	사이즈의 배열을 비교해 더 큰
	배열로 만들어 가는 방식으로 구현.

	이 과정에서 임시 배열이 필요함.
	정렬 된 배열을 담아둘 공간이
	필요하기 때문이다.
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
	추후 구현할 예정
*/
void MergeSortLoop(int* arr, const int length)
{
}

/*
	최대힙을 만드는 힙 알고리즘.
	한 번 실행할 때 마다 항상
	트리에서 최대값이 루트노드에
	위치 하게 하는 것이 포인트.
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
	힙정렬은 힙을 한 번 최대힙으로
	만들 때 마다 최대값이 루트 노드에
	위치 하는 것을 이용해 정렬한다.

	한 번 최대힙으로 만들고 루트노드를
	배열의 맨 뒤에 위치시키고, 또 한 번
	최대힙을 만들고, 맨 뒤 - 1 에 위치시키는
	식으로 뒤에서 부터 채워가는 오름차순
	정렬을 구현한다.

	최대힙을 데이터 개수인 n 번 실행 하고,
	최대힙의 시간복잡도가 log n 이므로
	힙정렬 알고리즘의 시간복잡도는
	O(n log n)이 된다.
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
	정렬이 잘 됬는지 검증하는 코드
	assert() 에 조건으로 값을 비교하는데,
	현재 i 위치의 값과 i + 1 위치의 값을
	비교해 항상 i 의 값이 작거나 같아야
	한다고 단정 지었으므로,정렬이 안되면
	assert 에러가 발생한다.

	assert() 조건이 거짓이 되려면
	i + 1 값이 더 작아야 하기 때문이고,
	이는 정렬이 안됬다는 증거이기 때문이다.
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