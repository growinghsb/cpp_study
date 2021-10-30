#include <iostream>
#include <map>
#include <ctime>

#include "Map.h"

using std::cout;
using std::endl;
using std::map;
using std::pair;


int main(void) {
	srand(static_cast<int>(time(0)));

	map<int, int> m;
	m.insert(pair<int, int>(10, 100));
	map<int, int>::iterator mIter(m.begin());

	cout << "STL map" << endl;

	cout << mIter->first << endl;
	cout << mIter->second << endl;

	mIter = m.find((int)10); // iterator 반환
	//(*mIter); // pair& 반환, .연산자로 pair 데이터 접근 가능
	//mIter->first; // pair* 반환, ->연산자로 pair 데이터 접근 가능

	/*
		MyMap test place
	*/

	// 키 세팅
	unsigned int keys[1000];
	for (unsigned int i = 0; i < 1000; i++)
	{
		keys[i] = i + 1;
	}

	for (unsigned int i = 0; i < 1000; i++)
	{
		unsigned int idx1 = rand() % 1000;
		unsigned int idx2 = rand() % 1000;

		unsigned int tmp = keys[idx1];
		keys[idx1] = keys[idx2];
		keys[idx2] = tmp;
	}

	cout << endl;
	cout << endl;
	cout << "MyMap" << endl;

	MyMap<int, int> myMap;

	for (unsigned int i = 0; i < 10; i++)
	{
		myMap.Insert(MakeMyPair<int, int>(keys[i], i + 1));
	}
	myMap.Insert(MakeMyPair<int, int>(1001, 10000));
	myMap.Insert(MakeMyPair<int, int>(2001, 20000));

	MyMap<int, int>::Iterator iter1 = myMap.begin();
	MyMap<int, int>::Iterator iter2 = myMap.end();

	MyMap<int, int>::Iterator result1 = myMap.find((int)1001);
	MyMap<int, int>::Iterator result2 = myMap.find((int)2001);

	cout << iter1->GetKey() << endl; // pair* 반환해서 ->연산자로 pair 접근
	cout << (*iter1).GetKey() << endl; // pair& 반환해서 ()로 묶어 pair& 가져오고 .연산자로 접근

	return 0;
}