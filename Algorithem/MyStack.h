#pragma once

typedef struct MyStack
{
	int* mData; // 데이터 담을 힙 메모리 참조하는 포인터
	unsigned int mCapacity; // 최대 크기
	unsigned int mSize; // 현재 크기

	MyStack();
	~MyStack();

	void Add(int data);
	int Pop();
	unsigned int GetSize() const;
	void Release();

}STACK;

