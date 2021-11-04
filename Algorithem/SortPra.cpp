/* 공부할 정렬 알고리즘
	0. 버블정렬
	1. 선택정렬
	2. 삽입정렬
	3. 병합정렬
	4. 퀵정렬
	5. 이분탐색
*/

#include <iostream>

using std::cout;
using std::endl;

void Swap(int& arr1, int& arr2);

void BubbleSort(int* arr, unsigned int size);
void SelectionSort(int* arr, unsigned int size);

void print(int* arr, unsigned int size);

int main(void)
{
	const unsigned int SIZE = 10;
	int arr[10] = { 10, 4, 8, 5, 6, 9, 13, 1, 3, 2 };

	// BubbleSort(arr, SIZE); 구현 완료 O(n * n)
	// SelectionSort(arr, SIZE); 구현 완료 O(n * n)
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

void print(int* arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << "[" << *(arr + i) << "]";
	}
	cout << endl << endl;
}
