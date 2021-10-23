#include <iostream>
#include <ctime>

#include "Arr.h"

using namespace std;

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
	Sort(&arr, true);
	print(&arr);

	cout << "�������� ����" << endl;
	Sort(&arr, false);
	print(&arr);

	Clear(&arr);

	return 0;
}
