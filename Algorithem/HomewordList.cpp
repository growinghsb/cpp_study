#include <iostream>
#include <cassert>

/*
	구현해야 하는 기능

	PushFront();
	PushBack();
	PopFront();
	PopBack();
*/

struct Node {
	int data;
	Node* nextNode;
	Node* prevNode;
};

struct List {
	Node* headNode;
	Node* tailNode;
	int count;
};

void PushFront(List* list, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->nextNode = nullptr;
	newNode->prevNode = nullptr;

	if (list->count == 0)
	{
		list->headNode = newNode;
		list->tailNode = newNode;
	}
	else
	{
		Node* firstNode = list->headNode;
		firstNode->prevNode = newNode;
		list->headNode = newNode;
		newNode->nextNode = firstNode;
	}

	++list->count;
}

void PushBack(List* list, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->nextNode = nullptr;
	newNode->prevNode = nullptr;

	if (list->count == 0)
	{
		list->headNode = newNode;
		list->tailNode = newNode;
	}
	else
	{
		newNode->prevNode = list->tailNode;
		list->tailNode->nextNode = newNode;
		list->tailNode = newNode;
	}

	++list->count;
}

void PopFront(List* list)
{
	assert(list->count > 0);

	Node* firstNode = list->headNode;

	if (list->count == 1)
	{
		delete firstNode;
		list->headNode = nullptr;
		list->tailNode = nullptr;
	}
	else
	{
		list->headNode = firstNode->nextNode;
		list->headNode->prevNode = nullptr;
		delete firstNode;
	}

	--list->count;
}

void PopBack(List* list)
{
	assert(list->count > 0);

	Node* targetNode = list->tailNode;

	if (list->count == 1)
	{
		delete targetNode;
		list->headNode = nullptr;
		list->tailNode = nullptr;
	}
	else
	{
		list->tailNode = targetNode->prevNode;
		list->tailNode->nextNode = nullptr;
		delete targetNode;
	}

	--list->count;
}

int main()
{
	List list = {};

	PushFront(&list, 10);
	PushFront(&list, 20);
	PushFront(&list, 30);

	PopFront(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);

	PopBack(&list);

	Delete(&list);

	return 0;
}