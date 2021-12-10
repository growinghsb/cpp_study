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

template<typename T>
class MyStack {

public:
	MyStack();
	~MyStack();

	void Push(const T& data);
	T Pop();
	void ReSize(const int size);
	
	int GetSize() const
	{
		return mSize;
	}
	
	bool isEmpty() const
	{
		if (0 == mSize) 
		{
			return true;
		}
		return false;
	}	

private:
	T* mData;
	int mCapacity;
	int mSize;
};

template<typename T>
MyStack<T>::MyStack()
	: mData(nullptr)
	, mCapacity(4)
	, mSize(0)
{
	mData = new T[mCapacity];
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[] mData;
}

template<typename T>
void MyStack<T>::Push(const T& data)
{
	if (mCapacity == mSize)
	{
		ReSize(mCapacity * 2);
	}

	*(mData + mSize) = data;
	++mSize;
}

template<typename T>
T MyStack<T>::Pop()
{
	assert(mSize > 0);

	--mSize;

	return *(mData + mSize);
}

template<typename T>
void MyStack<T>::ReSize(const int size)
{
	if (mCapacity >= size)
	{
		return;
	}

	mCapacity = size;
	T* p = new T[mCapacity];

	for (int i = 0; i < mSize; ++i)
	{
		*(p + i) = *(mData + i);
	}

	delete[] mData;
	mData = p;
}