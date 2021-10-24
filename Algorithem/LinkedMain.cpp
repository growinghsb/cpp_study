#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(void) {
	List list;
	InitList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushFront(&list, 1000);
	PushBack(&list, 300);
	PushBack(&list, 400);
	PushFront(&list, 2000);
	PushBack(&list, 500);

	cout << "데이터 넣기 끝" << endl;
	
	Print(&list);
	cout << "출력 끝" << endl;

	RemoveData(&list, 2000);
	Print(&list);
	cout << "'2000' 삭제" << endl;

	RemoveData(&list, 300);
	Print(&list);
	cout << "'300' 삭제" << endl;

	Clear(&list);

	return 0;
}