#include <iostream>

#include "DinamicArr.h"

using std::cout;
using std::endl;
using std::boolalpha;

template<typename T>
void print(const ArrayList<T>& arr);

template<typename T>
void QuickSort(T* arr, int start, int end);

int main(void)
{
	ArrayList<int> arr;
	cout << arr.GetSize() << endl;
	cout << arr.GetCapacity() << endl;

	cout << endl;

	arr.PushBack(10);
	arr.PushBack(20);
	arr.PushBack(30);
	arr.PushBack(40);
	arr.PushBack(50);

	cout << arr.GetSize() << endl;
	cout << arr.GetCapacity() << endl;

	cout << endl;

	ArrayList<int> copyArr(arr);
	cout << arr.GetSize() << endl;
	cout << arr.GetCapacity() << endl;

	cout << endl;

	bool result = arr == copyArr;
	cout << boolalpha << result << endl;

	cout << endl;

	copyArr.PushBack(60);
	copyArr.PushBack(70);
	copyArr.PushBack(80);
	copyArr.PushBack(90);
	copyArr.PushBack(100);
	copyArr.PushBack(110);
	copyArr.PushBack(120);
	copyArr.PushBack(130);
	copyArr.PushBack(140);
	copyArr.PushBack(150);
	cout << copyArr.GetSize() << endl;
	cout << copyArr.GetCapacity() << endl;

	cout << endl;

	copyArr.PushBack(160);
	cout << copyArr.GetSize() << endl;
	cout << copyArr.GetCapacity() << endl;

	cout << endl;

	copyArr.PushBack(170);
	cout << copyArr.GetSize() << endl;
	cout << copyArr.GetCapacity() << endl;

	cout << endl;

	cout << "index 10: " << copyArr[10] << endl;
	cout << "index 11: " << copyArr[11] << endl;
	cout << "index 12: " << copyArr[12] << endl;
	cout << "index 13: " << copyArr[13] << endl;

	cout << endl;

	cout << "index 1: " << copyArr.Get(1) << endl;
	cout << "index 2: " << copyArr.Get(2) << endl;
	cout << "index 3: " << copyArr.Get(3) << endl;
	cout << "index 4: " << copyArr.Get(4) << endl;

	cout << endl;

	ArrayList<int> copyArr2(copyArr);
	result = copyArr == copyArr2;
	cout << "copyArr == copyArr2: " << boolalpha << result << endl;

	cout << endl;

	result = copyArr != copyArr2;
	cout << "copyArr != copyArr2: " << boolalpha << result << endl;

	cout << endl;

	result = arr == copyArr;
	cout << "arr == copyArr: " << boolalpha << result << endl;

	arr = copyArr;
	result = arr == copyArr;
	cout << "대입 후: arr == copyArr: " << boolalpha << result << endl;
	print(copyArr);

	copyArr.RemoveIndex(10);
	copyArr.RemoveIndex(2);
	copyArr.RemoveIndex(3);
	copyArr.RemoveIndex(11);
	copyArr.RemoveIndex(5);
	copyArr.RemoveIndex(9);
	copyArr.RemoveIndex(7);

	print(copyArr);

	cout << endl;
	cout << "삭제 후" << endl;
	cout << "size: " << copyArr.GetSize() << endl;
	cout << "capacity: " << copyArr.GetCapacity() << endl;
	print(copyArr);

	cout << endl;

	copyArr.Sort(QuickSort);

	cout << "정렬 후" << endl;
	print(copyArr);

	return 0;
}

template<typename T>
void print(const ArrayList<T>& arr)
{
	for (unsigned int i = 0; i < arr.GetSize(); i++)
	{
		cout << "[" << arr.Get(i) << "] ";
	}
	cout << endl;
}

template<typename T>
void QuickSort(T* arr, int start, int end)
{
	if (start < end)
	{
		int pivot = start;
		int s = start + 1;
		int e = end;
		int tmp;

		while (s <= e)
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
		for (unsigned int i = 0; i < end + 1; i++)
		{
			cout << "[" << *(arr + i) << "] ";
		}
		cout << endl;

		QuickSort(arr, start, e);
		QuickSort(arr, e + 1, end);
	}
}
