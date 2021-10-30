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

	mIter = m.find((int)10); // iterator ��ȯ
	//(*mIter); // pair& ��ȯ, .�����ڷ� pair ������ ���� ����
	//mIter->first; // pair* ��ȯ, ->�����ڷ� pair ������ ���� ����

	/*
		MyMap test place
	*/

	// Ű ����
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

	cout << iter1->GetKey() << endl; // pair* ��ȯ�ؼ� ->�����ڷ� pair ����
	cout << (*iter1).GetKey() << endl; // pair& ��ȯ�ؼ� ()�� ���� pair& �������� .�����ڷ� ����

	return 0;
}