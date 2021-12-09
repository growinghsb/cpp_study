#include <iostream>
#include <map>

#include "MyMap.h"

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::make_pair;

int main() 
{
	map<int, int> stlMap;
	pair<int, int> stlPair;

	stlPair.first = 100;
	stlPair.second = 10;

	pair<int, int> stlPairCopy = stlPair;
	
	int a = 1000;
	int b = 40;

	stlMap.insert(make_pair(a, b));

	/*
		MyMap
	*/
	MyPair<int, int> myPair;
	myPair.mKey = 100;
	myPair.mValue = 10;

	MyPair<int, int> myPairCopy = myPair;
	MyPair<int, int> myPairConstructor(200, 20);
	myPairConstructor = myPair;
	myPair = myPair;
	MyPair<int, int> makePairFunc = makePair(300, 30);
	makePairFunc = std::move(myPairConstructor);

	return 0;
}
