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

	/*
		MyMap test place
	*/

	// Å° ¼¼ÆÃ
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
		myMap.Insert(MyPair<int, int>(keys[i], i + 1));
	}

	return 0;
}