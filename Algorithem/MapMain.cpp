#include <iostream>
#include <map>
#include <ctime>

#include "Map.h"

using std::cout;
using std::endl;
using std::map;
using std::pair;

template<typename KeyT, typename ValueT>
void printMap(MyMap<KeyT, ValueT> map, typename MyMap<KeyT, ValueT>::Iterator iter);

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
	myMap.Insert(MakeMyPair<int, int>(keys[500], 10000));
	myMap.Insert(MakeMyPair<int, int>(keys[550], 20000));

	MyMap<int, int>::Iterator iter1 = myMap.begin();
	MyMap<int, int>::Iterator iter2 = myMap.end();

	MyMap<int, int>::Iterator result1 = myMap.find((int)keys[500]);
	MyMap<int, int>::Iterator result2 = myMap.find((int)keys[550]);

	cout << iter1->GetKey() << endl; // pair* ��ȯ�ؼ� ->�����ڷ� pair ����
	cout << (*iter1).GetKey() << endl; // pair& ��ȯ�ؼ� ()�� ���� pair& �������� .�����ڷ� ����

	printMap(myMap, iter1);
	cout << endl << endl;

	cout << "����� Ű: " << keys[500] << endl;
	iter1 = myMap.erase(myMap.find((int)keys[500]));
	cout << "����� Ű ���� Ű: " << iter1->GetKey() << endl;
	cout << endl << endl;

	cout << "����� Ű: " << keys[550] << endl;
	iter1 =	myMap.erase(myMap.find((int)keys[550]));
	cout << "����� Ű ���� Ű: " << iter1->GetKey() << endl;
	cout << endl << endl;

	printMap(myMap, myMap.begin());
	cout << endl << endl;

	MyMap<int, int> testMap;
	testMap.Insert(MakeMyPair((int)100, (int)0));
	testMap.Insert(MakeMyPair((int)150, (int)0));
	testMap.Insert(MakeMyPair((int)80, (int)0));
	testMap.Insert(MakeMyPair((int)90, (int)0));
	testMap.Insert(MakeMyPair((int)65, (int)0));
	testMap.Insert(MakeMyPair((int)120, (int)0));
	testMap.Insert(MakeMyPair((int)160, (int)0));
	testMap.Insert(MakeMyPair((int)95, (int)0));
	testMap.Insert(MakeMyPair((int)130, (int)0));

	/*
							100
					80				150
				65		90		120		160								
					      95      130
	*/

	MyMap<int, int>::Iterator testIter(testMap.begin());
	printMap(testMap, testMap.begin());
	
	cout << endl;

	testIter = testMap.erase(testMap.find(65));
	testIter = testMap.erase(testMap.find(120));
	testIter = testMap.erase(testMap.find(90));
	testIter = testMap.erase(testMap.find(150));

	/*
							100
					80				160
						95		130		
						        
	*/

	return 0;
}

template<typename KeyT, typename ValueT>
void printMap(MyMap<KeyT, ValueT> map, typename MyMap<KeyT, ValueT>::Iterator iter)
{
	unsigned int count = 0;
	while (iter != map.end())
	{
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
		cout << "[" << iter->GetKey() << "]";

		++iter;
		++count;
	}
}