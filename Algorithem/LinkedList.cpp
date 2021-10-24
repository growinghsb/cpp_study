#include <iostream>

#include "LinkedList.h"

using namespace std;

Node* CreateNewNode(const int data);

void InitList(List* list)
{
	list->headNode = nullptr;
	list->count = 0;
}

void PushBack(List* list, const int data)
{
	Node* node = CreateNewNode(data);

	if (list->headNode == nullptr)
	{
		list->headNode = node;
	}
	else
	{
		Node* pN = list->headNode;
		while (pN->next != nullptr)
		{
			pN = pN->next;
		}
		pN->next = node;
	}
	list->count++;
}

void PushFront(List* list, const int data)
{
	Node* node = CreateNewNode(data);

	if (list->headNode == nullptr)
	{
		list->headNode = node;
	}
	else
	{
		node->next = list->headNode;
		list->headNode = node;
	}
	list->count++;
}

void RemoveData(List* list, const int data)
{
	if (list->headNode == nullptr)
	{
		return;
	}

	Node* pN = list->headNode;
	if (pN->data == data)
	{
		list->headNode = pN->next;
		free(pN);
	}
	else
	{
		Node* back = pN;
		pN = pN->next;

		while (pN != nullptr)
		{
			if (pN->data == data)
			{
				back->next = pN->next;
				free(pN);
				break;
			}
			back = pN;
			pN = pN->next;
		}
	}
	list->count--;
}

void Print(List* list)
{
	Node* start = list->headNode;
	if (start != nullptr) {
		for (unsigned int i = 0; i < list->count; i++)
		{
			cout << start->data << endl;
			start = start->next;
		}
	}
}

void Clear(List* list)
{
	Node* target = list->headNode;
	while (target != nullptr)
	{
		list->headNode = target->next;
		free(target);
		target = list->headNode;
	}
	list->count = 0;
}

Node* CreateNewNode(const int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = nullptr;

	return node;
}
