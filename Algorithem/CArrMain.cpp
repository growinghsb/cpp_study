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
	cout << "'resize 후'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;

	srand(static_cast<int>(time(0)));

	for (unsigned int i = 0; i < 15; i++)
	{
		arr.pushBack(rand() % 100);
	}

	cout << endl;

	cout << "'data 15개 추가 / resize 후'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	cout << endl;

	cout << "'pushIndex 추가'" << endl;
	//arr.pushIndex(1111, arr.getCount()); // 경계값 테스트 assert false
	arr.pushIndex(1111, 0);
	arr.pushIndex(1111, 6);
	arr.pushIndex(1111, 10);
	arr.pushIndex(1111, 12);
	cout << "'data 4개 추가'" << endl;
	cout << "size: " << arr.getSize() << endl;
	cout << "count: " << arr.getCount() << endl;
	arr.print();

	cout << endl;

	cout << "'6, 10번 인덱스 값 삭제'" << endl;
	//arr.remove(arr.getCount()); // 경계값 테스트 assert false
	arr.remove(6);
	arr.remove(10);
	cout << "'data 2개 삭제'" << endl;
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
	cout << boolalpha << "arr1 = arr2 진행 전: " << result << endl;

	arr1 = arr2;

	result = arr1 == arr2;
	cout << boolalpha << "arr1 = arr2 진행 후: " << result << endl;

	cout << endl;

	//int arrNum3 = arr1[3]; 경계값 테스트
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
	cout << "복사생성자로 객체 생성" << endl;
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
	cout << *iter << endl; // int& 반환, 10 출력
	*iter = 100; // 참조이기 때문에 값 대입 가능
	cout << "*iter = 100 후" << endl;
	cout << *iter << endl; // 대입된 100 출력
	
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
	//cout << *mIter << endl; end() 인 상태에서는 접근 불가. 

	cout << "++mIter 한 후" << endl;
	++mIter;
	cout << *mIter << endl; // iterator 인텍스 증가로 mIter[1] 의 값인 1000이 나와야 한다.

	mIter = myVec1.end();
	//++mIter; end() 인 상태에서는 증가시킬 수 없다. 
	--mIter;
	--mIter;
	--mIter;
	--mIter;
	--mIter;
	cout << "--mIter * 5: " << *mIter << endl;

	mIter = myVec1.begin();
	//--mIter; begin() 상태에서는 iterator 가 가진 인덱스가 0이기에 --가 불가능하다.
	++mIter;
	++mIter;
	++mIter;
	++mIter;
	//++mIter; //에러다. 데이터 5개, 유효 인덱스범위 4, 총 4번만 증가할 수 있다.
	cout << "++mIter * 4: " << *mIter << endl;


	//CArr<int>::iterator iter2;
	//++iter2; 처음 itorator 를 생성한 상태에서는 외부클래스를 가르키는 포인터가 nullptr 이기 때문에
	// 증가시킬 수 있는 주소가 없어 ++ 연산을 할 수 없다.

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
	// testIter[0]; 생성 당시 가변배열의 주소값을 가지는 포인터가 널포인터라 error
	// ++testIter;  위와 동일한 이유로 error

	testIter = testVec.begin();
	while (testIter != testVec.end()) {
		cout << *testIter << "  ";
		++testIter;
	}

	return 0;
}