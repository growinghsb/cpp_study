#include<iostream>
#include<vector>

#include"MyVector.h"

using std::vector;
using std::cout;
using std::endl;

int mainVector()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<int> stlVec;
	stlVec.reserve(100);
	stlVec.push_back(10);
	stlVec.push_back(20);
	stlVec.push_back(30);
	stlVec.push_back(40);
	stlVec.push_back(50);
	stlVec.push_back(60);
	stlVec.push_back(70);
	int stlSize = stlVec.size();
	int stlCapacity = stlVec.capacity();
	int stlData1 = stlVec[1];
	stlVec[1] = 30;
	int stlVecfront = stlVec.front();
	int stlVecback = stlVec.back();
	bool isEmpty = stlVec.empty();

	vector<int>::iterator beginIter = stlVec.begin();
	vector<int>::iterator endIter = stlVec.end();

	++beginIter;
	*beginIter = 100;
	int indirection = *beginIter;

	/*for (beginIter = stlVec.begin(); beginIter != endIter; ++beginIter)
	{
		cout << *beginIter << endl;
	}*/

	stlVec.erase(beginIter);

	// =========================================

	MyVector<int> myVec;
	bool myVecisEmpty = myVec.empty(); // true

	myVec.pushBack(10);
	myVec.pushBack(20);
	myVec.pushBack(30);
	myVec.pushBack(40);
	myVec.pushBack(50);

	int myVecSize = myVec.getSize();
	int myVecCapacity = myVec.getCapacity();

	/*
		경계값 테스트
	int value1 = myVec[-1];
	int value2 = myVec[5];
	*/

	int value1 = myVec[0];
	int value2 = myVec[1];
	int value3 = myVec[2];
	int value4 = myVec[3];
	int value5 = myVec[4];

	myVec[0] = 100;

	int myVecfront = myVec.front(); // 100
	int myVecback = myVec.back();   // 50

	myVecisEmpty = myVec.empty(); // false

	int addResult = myVec[0] + myVec[4];

	MyVector<int> myVec2(myVec);
	bool isSame = myVec2 == myVec; // true

	myVec.pushBack(60);
	myVec.pushBack(70);
	myVec.pushBack(80);
	myVec.pushBack(90);
	isSame = myVec2 == myVec; // false

	myVec2 = myVec;
	isSame = myVec2 == myVec; // true

	myVec[5] = 1000;
	isSame = myVec2 == myVec; // false

	MyVector<int> iterTestVec;
	
	for (int i = 1; i <= 10; ++i) 
	{
		iterTestVec.pushBack(i * 2);
	}

	MyVector<int>::iterator myBeginIter;
	MyVector<int>::iterator myEndIter = iterTestVec.end();

	cout << "[순서대로 출력]" << endl;

	for (myBeginIter = iterTestVec.begin(); myBeginIter != myEndIter; ++myBeginIter)
	{
		cout << *myBeginIter << endl;
	}

	cout << endl;

	MyVector<int>::iterator myRBeginIter;
	MyVector<int>::iterator myREndIter = iterTestVec.rEnd();

	cout << "[역순으로 출력]" << endl;
	for (myRBeginIter = iterTestVec.rBegin(); myRBeginIter != myREndIter; --myRBeginIter)
	{
		cout << *myRBeginIter << endl;
	}

	MyVector<int>::iterator targetIter = myVec.begin();
	++targetIter;

	targetIter = myVec.erase(targetIter);
	myVec.pushBack(1000);

	return 0;
}