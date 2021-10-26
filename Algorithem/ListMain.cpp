#include <iostream>

#include "CList.h"

int main(void) {
	LinkedList<int> list;
	list.pushBack(10);
	list.pushBack(20);
	list.pushFront(1000);
	list.pushBack(30);
	list.pushBack(40);
	list.pushFront(2000);

	list.remove(30);
	list.remove(2000);

	return 0;
}