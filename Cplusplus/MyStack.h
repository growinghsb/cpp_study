#pragma once

#include<cassert>

/*
	스택 필요 함수

	기본생성자
	기본 소멸자
	push
	pop
	resize

	필요 멤버 변수
	정수 포인터
	최대 사이즈
	현재 사이즈

*/

class MyStack {

public:
	MyStack();
	~MyStack();

	void Push(const int data);
	int Pop();
	void ReSize(const int size);
	int GetSize() const;

private:
	int* mData;
	int mCapacity;
	int mSize;
};

MyStack::MyStack() 
	: mData(nullptr)
	, mCapacity(4)
	, mSize(0)
{
	mData = new int[mCapacity];
}

MyStack::~MyStack()
{
	delete[] mData;
}

void MyStack::Push(const int data)
{
	if (mCapacity == mSize) 
	{
		ReSize(mCapacity * 2);
	}

	*(mData + mSize) = data;
	++mSize;
}

int MyStack::Pop() 
{
	assert(mSize > 0);

	--mSize;

	return *(mData + mSize);
}

void MyStack::ReSize(const int size) 
{
	if (mCapacity >= size) 
	{
		return;
	}

	mCapacity = size;
	int* p = new int[mCapacity];

	for (int i = 0; i < mSize; ++i) 
	{
		*(p + i) = *(mData + i);
	}

	delete[] mData;
	mData = p;
}
int MyStack::GetSize() const 
{
	return mSize;
}