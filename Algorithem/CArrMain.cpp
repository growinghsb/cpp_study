#include <iostream>
#include <ctime>
#include <vector>

#include "CArr.h"

using std::cout;
using std::endl;
using std::vector;
using std::boolalpha;

int main(void) {
	CArr<int> arr;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;

	cout << endl;

	arr.resize(500);
	cout << "'resize ��'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;

	srand(static_cast<int>(time(0)));

	for (unsigned int i = 0; i < 15; i++)
	{
		arr.pushBack(rand() % 100);
	}

	cout << endl;

	cout << "'data 15�� �߰� / resize ��'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	cout << endl;

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

	cout << endl;

	cout << "'6, 10�� �ε��� �� ����'" << endl;
	//arr.remove(arr.getCount()); // ��谪 �׽�Ʈ assert false
	arr.remove(6);
	arr.remove(10);
	cout << "'data 2�� ����'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	cout << endl;

	CArr<float> arr1;
	CArr<float> arr2;

	arr1.pushBack(1.45f);
	arr1.pushBack(2.87f);
	arr1.pushBack(3.09f);
	arr1.pushBack(4.819f);
	arr1.pushBack(5.99f);

	arr2.pushBack(10.123f);
	arr2.pushBack(20.391f);
	arr2.pushBack(30.219f);

	bool result = arr1 == arr2;
	cout << boolalpha << "arr1 = arr2 ���� ��: " << result << endl;

	arr1 = arr2;

	result = arr1 == arr2;
	cout << boolalpha << "arr1 = arr2 ���� ��: " << result << endl;

	cout << endl;

	//int arrNum3 = arr1[3]; ��谪 �׽�Ʈ
	float arrNum1 = arr1[0];
	float arrNum2 = arr1[1];
	float arrNum3 = arr1[2];
	cout << arrNum1 << " " << arrNum2 << " " << arrNum3;

	cout << endl;

	arr1[0] = 99.0923f;
	arr1[1] = 99.1232f;
	arr1[2] = 99.768f;
	arr1.print();

	cout << endl;
	cout << "��������ڷ� ��ü ����" << endl;
	CArr<float> copy(arr1);
	result = copy == arr1;
	cout << boolalpha << "copy == arr1: " << result << endl;

	cout << endl;
	cout << "<vector class iterator>" << endl;

	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	vector<int>::iterator iter = vec.begin();
	cout << *iter << endl; // int& ��ȯ, 10 ���
	*iter = 100; // �����̱� ������ �� ���� ����
	cout << "*iter = 100 ��" << endl;
	cout << *iter << endl; // ���Ե� 100 ���
	
	unsigned int index = 0;
	while (index != vec.size()) {
		cout << iter[index] << "  ";
		++index;
	}

	while (iter != vec.end()) {
		cout << *iter << "  ";
		++iter;
	}

	cout << endl;
	cout << "<CArr class iterator>" << endl;

	CArr<int> myVec1;
	myVec1.pushBack(1);
	myVec1.pushBack(2);
	myVec1.pushBack(3);
	myVec1.pushBack(4);
	myVec1.pushBack(5);

	CArr<int>::iterator mIter = myVec1.begin();

	cout << mIter[0] << endl;
	cout << *mIter << endl;

	*mIter = 2000;
	mIter[1] = 1000;
	cout << mIter[1] << endl;
	cout << *mIter << endl;
	//mIter = myVec1.end();
	//cout << mIter[0] << endl;
	//cout << *mIter << endl; end() �� ���¿����� ���� �Ұ�. 

	cout << "++mIter �� ��" << endl;
	++mIter;
	cout << *mIter << endl; // iterator ���ؽ� ������ mIter[1] �� ���� 1000�� ���;� �Ѵ�.

	mIter = myVec1.end();
	//++mIter; end() �� ���¿����� ������ų �� ����. 
	--mIter;
	--mIter;
	--mIter;
	--mIter;
	--mIter;
	cout << "--mIter * 5: " << *mIter << endl;

	mIter = myVec1.begin();
	//--mIter; begin() ���¿����� iterator �� ���� �ε����� 0�̱⿡ --�� �Ұ����ϴ�.
	++mIter;
	++mIter;
	++mIter;
	++mIter;
	//++mIter; //������. ������ 5��, ��ȿ �ε������� 4, �� 4���� ������ �� �ִ�.
	cout << "++mIter * 4: " << *mIter << endl;


	//CArr<int>::iterator iter2;
	//++iter2; ó�� itorator �� ������ ���¿����� �ܺ�Ŭ������ ����Ű�� �����Ͱ� nullptr �̱� ������
	// ������ų �� �ִ� �ּҰ� ���� ++ ������ �� �� ����.

	mIter = myVec1.begin();
	while (mIter != myVec1.end()) {
		cout << *mIter << " ";
		++mIter;
	}

	cout << endl;
	cout << "test" << endl;
	CArr<int> testVec;
	testVec.pushBack(100);
	testVec.pushBack(200);
	testVec.pushBack(300);
	testVec.pushBack(400);
	testVec.pushBack(500);

	CArr<int>::iterator testIter;
	// testIter[0]; ���� ��� �����迭�� �ּҰ��� ������ �����Ͱ� �������Ͷ� error
	// ++testIter;  ���� ������ ������ error

	testIter = testVec.begin();
	while (testIter != testVec.end()) {
		cout << *testIter << "  ";
		++testIter;
	}

	return 0;
}