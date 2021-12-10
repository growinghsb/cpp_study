#include "MyMap.h"
#include <map>

using std::map;
using std::pair;
using std::make_pair;

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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

	//MyPair<int, int> myPair;
	//myPair.mKey = 100;
	//myPair.mValue = 10;

	//MyPair<int, int> myPairCopy = myPair;
	//MyPair<int, int> myPairConstructor(200, 20);
	//myPairConstructor = myPair;
	//myPair = myPair;
	//MyPair<int, int> makePairFunc = makePair(300, 30);
	//makePairFunc = move(myPairConstructor);

	/*
						100
				80				130	
			65		90		110		150
	 	50		 85	  95  105			170	    
	      55                          165
		53
	*/

	MyMap<int, int> myMap;
	
	MyPair<int, int> myPair1(100, 1);
	
	MyPair<int, int> myPair2;
	myPair2.mKey = 80;
	myPair2.mValue = 2;

	MyPair<int, int> myPair3 = makePair(130, 3);

	MyPair<int, int> myPair4;
	myPair4 = makePair(65, 4);

	MyPair<int, int> rValuePair(90, 5);
	MyPair<int, int> myPair5;
	myPair5 = move(rValuePair);

	MyPair<int, int> copyPair(110, 6);
	MyPair<int, int> myPair6 = copyPair;

	MyPair<int, int> copyPairRValue(150, 7);
	MyPair<int, int> myPair7 = move(copyPairRValue);

	myMap.insert(myPair1);
	myMap.insert(myPair2);
	myMap.insert(myPair3);
	myMap.insert(myPair4);
	myMap.insert(myPair5);
	myMap.insert(myPair6);
	myMap.insert(myPair7);
	myMap.insert(makePair(50, 8));
	myMap.insert(makePair(85, 9));
	myMap.insert(makePair(95, 10));
	myMap.insert(makePair(105, 11));
	myMap.insert(makePair(170, 12));
	myMap.insert(makePair(170, 13));
	myMap.insert(makePair(55, 14));
	myMap.insert(makePair(53, 15));
	myMap.insert(makePair(165, 16));

	int result1 = myMap.find(50);
	int result2 = myMap.find(myPair7.mKey);

	myMap.printMapRecursive();

	cout << endl << endl;

	myMap.printMapLoop();
	cout << endl << "개수: " << myMap.getCount() << "개" << endl;

	cout << endl << endl;

	cout << "[단말노드 지운 후] 85" << endl;
	myMap.deleteNode(85); // 단말노드 지우기 
	myMap.printMapLoop();
	cout << endl << "개수: " << myMap.getCount() << "개" << endl;

	cout << endl << endl;

	cout << "[자식 두 개 노드 지운 후] 130" << endl;
	myMap.deleteNode(130); // 자식 두 개 노드 지운 후
	myMap.printMapLoop();
	cout << endl << "개수: " << myMap.getCount() << "개" << endl;

	cout << endl << endl;

	cout << "[자식 한 개 노드 지운 후] 65" << endl;
	myMap.deleteNode(65); // 자식 한 개 노드 지운 후
	myMap.printMapLoop();
	cout << endl << "개수: " << myMap.getCount() << "개" << endl;

	cout << endl << endl;

	cout << "[자식 한 개 노드 지운 후] 150" << endl;
	myMap.deleteNode(150); // 자식 한 개 노드 지운 후
	myMap.printMapLoop();
	cout << endl << "개수: " << myMap.getCount() << "개" << endl;

	myMap.clear();

	return 0;
}
