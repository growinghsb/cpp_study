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

	cout << "������ �ֱ� ��" << endl;
	
	Print(&list);
	cout << "��� ��" << endl;

	RemoveData(&list, 2000);
	Print(&list);
	cout << "'2000' ����" << endl;

	RemoveData(&list, 300);
	Print(&list);
	cout << "'300' ����" << endl;

	Clear(&list);

	return 0;
}