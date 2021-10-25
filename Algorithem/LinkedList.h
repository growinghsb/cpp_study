#pragma once
typedef struct node {
	struct node* next;
	int data;
	char emptySpace[4] = {};
}Node;

typedef struct list {
	Node* headNode;
	unsigned int count;
}List;

void InitList(List* list);
void PushBack(List* list, const int data);
void PushFront(List* list, const int data);
void RemoveData(List* list, const int data);
void Print(List* list);
void Clear(List* list); // 리스트 전체 노드 삭제