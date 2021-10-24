#include <iostream>
#include <ctime>

#include "Arr.h"

using namespace std;

void Asc(const int* arr, const unsigned int count);
void Desc(const int* arr, const unsigned int count);
void Swap(const int* arr, const unsigned int j);

int main(void) {
	srand(static_cast<int>(time(0)));

	arr_t arr;
	InitArr(&arr, 10);
	cout << "�ʱ�ȭ ���� ������" << endl;
	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	for (unsigned int i = 0; i < 15; i++) {
		AddBack(&arr, rand() % 1000);
	}

	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	print(&arr);

	RemoveIndex(&arr, 10);
	cout << "���� ��" << endl;

	print(&arr);
	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	cout << "�߰� ��" << endl;
	AddIndex(&arr, 1111, 5);
	AddIndex(&arr, 1111, 6);

	print(&arr);
	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	cout << "�������� ����" << endl;
	Sort(arr.pInt, arr.iCount, Asc);
	print(&arr);

	cout << "�������� ����" << endl;
	Sort(arr.pInt, arr.iCount, Desc);
	print(&arr);

	Clear(&arr);

	return 0;
}

void Asc(const int* arr, const unsigned int count) {
	bool proceeding = true;
	while (proceeding) {
		proceeding = false;
		for (unsigned int j = 0; j < count - 1; j++)
		{
			
			if (*(arr + j) > *(arr + j + 1)) {
				Swap(arr, j);
				proceeding = true;
			}
		}
	}
}

void Desc(const int* arr, const unsigned int count) {
	bool proceeding = true;
	while (proceeding) {
		proceeding = false;
		for (unsigned int j = 0; j < count - 1; j++)
		{
			if (*(arr + j) < *(arr + j + 1)) {
				Swap(arr, j);
				proceeding = true;
			}
		}
	}
}

void Swap(const int* arr, const unsigned int j) {
	int* notConstP = const_cast<int*>(arr); // �ӽ÷� const ����

	int tmp = *(arr + j);
	*(notConstP + j) = *(arr + j + 1);
	*(notConstP + j + 1) = tmp;
}


