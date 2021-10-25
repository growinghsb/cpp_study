#include <iostream>
#include <ctime>

#include "CArr.h"

using namespace std;

int main(void) {
	CArr arr;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;

	
	arr.resize(500);
	cout << "'resize ��'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;

	srand(static_cast<int>(time(0)));

	for (unsigned int i = 0; i < 15; i++)
	{
		arr.pushBack(rand() % 100);
	}

	cout << "'data 15�� �߰� / resize ��'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	cout << "'pushIndex �߰�'" << endl;
	//arr.pushIndex(1111, arr.getCount()); // ��谪 �׽�Ʈ assert false
	arr.pushIndex(1111, 0);
	arr.pushIndex(1111, 6);
	arr.pushIndex(1111, 10);
	arr.pushIndex(1111, 12);
	cout << "'data 4�� �߰�'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	cout << "'6, 10�� �ε��� �� ����'" << endl;
	//arr.remove(arr.getCount()); // ��谪 �׽�Ʈ assert false
	arr.remove(6);
	arr.remove(10);
	cout << "'data 2�� ����'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	CArr arr1;
	CArr arr2;

	arr1.pushBack(1);
	arr1.pushBack(2);
	arr1.pushBack(3);
	arr1.pushBack(4);
	arr1.pushBack(5);

	arr2.pushBack(10);
	arr2.pushBack(20);
	arr2.pushBack(30);

	bool result = arr1 == arr2;
	cout << boolalpha << "arr1 = arr2 ���� ��: " << result << endl;

	arr1 = arr2;

	result = arr1 == arr2;
	cout << boolalpha << "arr1 = arr2 ���� ��: " << result << endl;

	//int arrNum3 = arr1[3]; ��谪 �׽�Ʈ
	int arrNum1 = arr1[0];
	int arrNum2 = arr1[1];
	int arrNum3 = arr1[2];
	cout << arrNum1 << endl;
	cout << arrNum2 << endl;
	cout << arrNum3 << endl;

	arr1[0] = 1000;
	arr1[1] = 2000;
	arr1[2] = 3000;
	cout << arr1[0] << endl;
	cout << arr1[1] << endl;
	cout << arr1[2] << endl;

	cout << endl;
	cout << "��������ڷ� ��ü ����" << endl;
	CArr copy(arr1);
	result = copy == arr1;
	cout << boolalpha << "copy == arr1: " << result << endl;

	return 0;
}