#pragma once

#include<cassert>

/*
	���� �ʿ� �Լ�

	�⺻������
	�⺻ �Ҹ���
	push
	pop
	resize

	�ʿ� ��� ����
	���� ������
	�ִ� ������
	���� ������

*/

template<typename T>
class MyStack {

public:
	MyStack();
	~MyStack();

	void Push(const T& data);
	int Pop();
	void ReSize(const int size);
	int GetSize() const
	{
		return mSize;
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
int MyStack<T>::Pop()
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
	int* p = new T[mCapacity];

	for (int i = 0; i < mSize; ++i)
	{
		*(p + i) = *(mData + i);
	}

	delete[] mData;
	mData = p;
}