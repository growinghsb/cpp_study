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
	mCapacity *= 2; // 기존 최대 크기의 2배 크기를 새로 잡는다.

	// 새로 잡은 크기 만큼 메모리 할당 진행
	int* p = (int*)malloc(sizeof(int) * mCapacity); 

	// nullptr 이 아니라면 데이터 복사 진행
	if (p != nullptr)
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			*(p + i) = *(mData + i);
		}
		free(mData); // 기존 메모리 해제 후 
		mData = p; // 새로 할당 받고, 데이터 복사한 메모리 공간 참조
	}
	else 
	{
		exit(0);
	}
}
