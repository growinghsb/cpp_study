#include <iostream>
#include <cassert>
#include "MyStack.h"

MyStack::MyStack()
	: mData(nullptr)
	, mCapacity(4)
	, mSize(0)
{
	mData = (int*)malloc(sizeof(int) * mCapacity);
}

MyStack::~MyStack()
{
	free(mData);
}

void MyStack::Add(int data)
{
	if (mCapacity == mSize)
	{
		Release();
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

unsigned int MyStack::GetSize() const
{
	return mSize;
}

void MyStack::Release()
{
	mCapacity *= 2; // ���� �ִ� ũ���� 2�� ũ�⸦ ���� ��´�.

	// ���� ���� ũ�� ��ŭ �޸� �Ҵ� ����
	int* p = (int*)malloc(sizeof(int) * mCapacity); 

	// nullptr �� �ƴ϶�� ������ ���� ����
	if (p != nullptr)
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			*(p + i) = *(mData + i);
		}
		free(mData); // ���� �޸� ���� �� 
		mData = p; // ���� �Ҵ� �ް�, ������ ������ �޸� ���� ����
	}
	else 
	{
		exit(0);
	}
}
