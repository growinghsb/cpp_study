#include<iostream>
#include<list>

#include"MyLinkedList.h"

using std::cout;
using std::endl;
using std::list;

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	list<int> stdList;
	stdList.push_front(10);
	stdList.push_front(20);
	stdList.push_back(1);
	stdList.push_back(2);

	stdList.pop_front();
	stdList.pop_back();

	stdList.clear();

	list<int>::iterator stdListBeginIter;
	list<int>::iterator stdListEndIter = stdList.end();
	
	for (stdListBeginIter = stdList.begin(); stdListBeginIter != stdListEndIter; ++stdListBeginIter)
	{
		cout << *stdListBeginIter << "  ";
	}

	stdListBeginIter = stdList.begin();

	// MyLinkedList

	MyLinkedList<int> myList;

	myList.pushFront(10);
	myList.pushFront(20);
	myList.pushFront(30);
	myList.pushFront(40);
	myList.pushFront(50);
	myList.pushBack(9);
	myList.pushBack(8);
	myList.pushBack(7);
	myList.pushBack(6);
	myList.pushBack(5);

	myList.popFront();
	myList.popFront();
	myList.popFront();

	myList.popBack();
	myList.popBack();
	myList.popBack();

	bool isData = myList.isData(10); // true
	isData = myList.isData(50); // false

	MyLinkedList<int> list2 = myList;
	MyLinkedList<int> list3;

	bool isEmpty = list3.isEmpty();

	list3 = myList;

	cout << "[myList]" << endl;
	myList.printOrder();
	myList.printReverseOrder();

	cout << "[list2]" << endl;
	list2.printOrder();
	list2.printReverseOrder();

	cout << "[list3]" << endl;
	list3.printOrder();
	list3.printReverseOrder();

	MyLinkedList<int>::iterator beginIter = myList.begin();
	MyLinkedList<int>::iterator endIter = myList.end();

	cout << endl;
	cout << "[iterator ¼øÈ¸]" << endl;
	for (beginIter = myList.begin(); beginIter != endIter; ++beginIter) 
	{
		cout << *beginIter << "  ";
	}

	return 0;
}