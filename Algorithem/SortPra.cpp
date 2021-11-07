/* ������ ���� �˰���
	0. ��������
	1. ��������
	2. ��������
	3. ��������
	4. ������
	5. �̺�Ž��
*/

#include <iostream>

const unsigned int SIZE = 8;
static int sorted[SIZE] = {};

using std::cout;
using std::endl;

void Swap(int& arr1, int& arr2);

void BubbleSort(int* arr, unsigned int size);
void SelectionSort(int* arr, unsigned int size);
void InsertionSort(int* arr, unsigned int size);

void MergeSort(int* arr, int start, int end);
void Merge(int* arr, int start, int mid, int end);

void QuickSort(int* arr, int start, int end);

void print(int* arr, unsigned int size);

int main(void)
{
	int arr[SIZE] = { 10, 4, 8, 5, 6, 9, 13, 2 };

	// BubbleSort(arr, SIZE);    ���� �Ϸ� O(n * n)
	// SelectionSort(arr, SIZE); ���� �Ϸ� O(n * n)
	// InsertionSort(arr, SIZE); ���� �Ϸ� O(n * n)
	// MergeSort(arr, 0, SIZE - 1); ���� �Ϸ� O(n * logN)
	// QuickSort(arr, 0, SIZE - 1); ���� �Ϸ� O(n * logN)
	print(arr, SIZE);

	return 0;
}

void Swap(int& max, int& min)
{
	int tmp = max;
	max = min;
	min = tmp;
}

void BubbleSort(int* arr, unsigned int size)
{
	for (unsigned int i = 0; i < size - 1; ++i)
	{
		for (unsigned int j = 0; j < size - i - 1; ++j)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				Swap(*(arr + j), *(arr + j + 1));
			}
		}
	}
}

void SelectionSort(int* arr, unsigned int size)
{
	for (unsigned int i = 0; i < size - 1; i++)
	{
		unsigned int minIndex = i;
		for (unsigned int j = i + 1; j < size; j++)
		{
			if (*(arr + minIndex) > *(arr + j))
			{
				minIndex = j;
			}
		}
		Swap(*(arr + i), *(arr + minIndex));
	}
}

void InsertionSort(int* arr, unsigned int size)
{
	for (unsigned int i = 1; i < size; i++)
	{
		int target = *(arr + i);
		int startIndex = i - 1;

		while (startIndex != -1)
		{
			if (target < *(arr + startIndex))
			{
				*(arr + startIndex + 1) = *(arr + startIndex);
			}
			else
			{
				break;
			}
			--startIndex;
		}
		*(arr + startIndex + 1) = target;
	}
}

void MergeSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int midIndex = (start + end) / 2;

		MergeSort(arr, start, midIndex);
		MergeSort(arr, midIndex + 1, end);
		Merge(arr, start, midIndex, end);
	}
}

void Merge(int* arr, int start, int mid, int end)
{
	int part1 = start;
	int part2 = mid + 1;
	int sortedIndex = start;

	while (part1 <= mid && part2 <= end)
	{
		if (*(arr + part1) < *(arr + part2))
		{
			sorted[sortedIndex++] = *(arr + part1);
			++part1;
		}
		else
		{
			sorted[sortedIndex++] = *(arr + part2);
			++part2;
		}
	}

	if (part1 > mid)
	{
		for (int i = part2; i < end + 1; i++)
		{
			sorted[sortedIndex++] = *(arr + i);
		}
	}
	else
	{
		for (int i = part1; i < mid + 1; i++)
		{
			sorted[sortedIndex++] = *(arr + part1);
		}
	}

	for (int i = start; i < end + 1; i++)
	{
		*(arr + i) = *(sorted + i);
	}
}

void QuickSort(int* arr, int start, int end)
{
	if (start < end) 
	{
		int pivot = start; // �ǹ����� ù ��° ������ ����
		int s = start + 1;
		int e = end;
		int tmp;

		while (s <= e) // start index �� end index ���� �۰ų� ���� �� ������ �ݺ� ����, �������� ���� 
		{
			while (*(arr + s) <= *(arr + pivot) && s < end)
			{
				++s;
			}

			while (*(arr + e) >= *(arr + pivot) && e > start)
			{
				--e;
			}

			if (s > e)
			{
				tmp = *(arr + e);
				*(arr + e) = *(arr + pivot);
				*(arr + pivot) = tmp;
			}
			else
			{
				tmp = *(arr + s);
				*(arr + s) = *(arr + e);
				*(arr + e) = tmp;
			}
		}
		QuickSort(arr, start, e);
		QuickSort(arr, e + 1, end);
	}
}

void print(int* arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << "[" << *(arr + i) << "]";
	}
	cout << endl << endl;
}
