/* �ؾ��� ��
   0. �迭 ���� �ϰ� �� �����ϱ�
   1. ��������
   2. ��������
   3. ��������
   4. ������(��� ����, �ݺ��� ����)
   5. �ڵ� ���ٵ��, ����ȭ �ϱ�
   6. ����
*/

#include "Sorts.h" // �ʿ��� ������� �ִ� �������

int main()
{
	const unsigned int LENGTH = 10;
	int arr[LENGTH] = {};

	/* Bubble Sort*/
	ArraySetting(arr, LENGTH);
	BubbleSort(arr, LENGTH);
	PrintArray(arr, LENGTH, "Bubble Sort");

	/* Selection Sort */
	ArraySetting(arr, LENGTH);
	SelectionSort(arr, LENGTH);
	PrintArray(arr, LENGTH, "Selection Sort");

	/* Insertion Sort */
	ArraySetting(arr, LENGTH);
	InsertionSort(arr, LENGTH);
	PrintArray(arr, LENGTH, "Insertion Sort");

	/* Quick Sort Recursive*/
	ArraySetting(arr, LENGTH);
	QuickSortRecursive(arr, LENGTH);
	PrintArray(arr, LENGTH, "Quick Sort Recursive");

	/* Quick Sort Loop*/
	ArraySetting(arr, LENGTH);
	QuickSortLoop(arr, LENGTH);
	PrintArray(arr, LENGTH, "Quick Sort Loop");

	return 0;
}

void ArraySetting(int* arr, const int length)
{
	srand(rand() % 10);

	for (int i = 0; i < length; ++i)
	{
		*(arr + i) = rand() % 100;
	}
}

void BubbleSort(int* arr, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		bool flag = true;

		for (int j = 0; j < length - (i + 1); ++j)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				Swap(arr + j, arr + j + 1);
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

void SelectionSort(int* arr, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < length; ++j)
		{
			if (*(arr + minIndex) > *(arr + j))
			{
				minIndex = j;
			}
		}
		Swap(arr + minIndex, arr + i);
	}
}

void InsertionSort(int* arr, const int length)
{
	for (int i = 1; i < length; ++i)
	{
		int targetIndex = i;

		for (int j = 0; j < i; ++j)
		{
			if (*(arr + targetIndex) < *(arr + j))
			{
				int targetIndexValue = *(arr + targetIndex);

				for (int k = targetIndex - 1; k >= j; --k)
				{
					*(arr + k + 1) = *(arr + k);
				}
				*(arr + j) = targetIndexValue;
				break;
			}
		}
	}
}

void QuickSortRecursive(int* arr, const int length)
{
	QuickDivide(arr, 0, length - 1);
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
				Swap(arr + startIdx, arr + endIdx);
			}
			else
			{
				Swap(arr + endIdx, arr + pivotIdx);
			}
		}
		QuickDivide(arr, start, endIdx - 1);
		QuickDivide(arr, endIdx + 1, end);
	}
}

void QuickSortLoop(int* arr, int length)
{
	STACK stack;

	int pivot = 0;
	int start = 0;
	int end = 0;

	while (true)
	{
		if (0 == stack.GetSize())
		{
			start = 0;
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
			int left = start + 1;
			int right = end;

			while (left < right)
			{
				while (*(arr + left) <= *(arr + pivot) && left < end)
				{
					++left;
				}
				while (*(arr + right) >= *(arr + pivot) && right > start)
				{
					--right;
				}

				if (left < right)
				{
					Swap(arr + left, arr + right);
				}
				else
				{
					Swap(arr + right, arr + pivot);
				}
			}
			stack.Add(right + 1);
			stack.Add(end);
			stack.Add(start);
			stack.Add(right - 1);
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

void PrintArray(int* arr, const int length, const char* algorithemName)
{
	cout << algorithemName << endl;

	for (int i = 0; i < length; ++i)
	{
		cout << "[" << *(arr + i) << "]";
	}
	cout << endl << endl;
}