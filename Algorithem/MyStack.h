#pragma once

typedef struct MyStack
{
	int* mData; // ������ ���� �� �޸� �����ϴ� ������
	unsigned int mCapacity; // �ִ� ũ��
	unsigned int mSize; // ���� ũ��

	MyStack();
	~MyStack();

	void Add(int data);
	int Pop();
	unsigned int GetSize() const;
	void Release();

}STACK;

