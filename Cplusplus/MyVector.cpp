#include "MyVector.h"

MyVector::MyVector()
	: mData(nullptr)
	, mCapacity(0)
	, mSize(0)
{
}

MyVector::~MyVector()
{
	delete[] mData;
}

MyVector::MyVector(const MyVector& other)
	: mData(nullptr)
	, mCapacity(other.mCapacity)
	, mSize(other.mSize)
{
	mData = new int[mCapacity];
	dataCopy(other);
}

void MyVector::reserve(unsigned int newCapacity)
{
	assert(newCapacity > mCapacity);

	mCapacity = newCapacity;
	int* pTmp = new int[mCapacity];

	if (nullptr != mData)
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			*(pTmp + i) = *(mData + i);
		}
		delete[] mData;
	}
	mData = pTmp;
}

void MyVector::pushBack(int data)
{
	if (mSize == mCapacity)
	{
		mCapacity == 0 ? reserve(1) : reserve(mCapacity * 2);
	}

	*(mData + mSize) = data;
	++mSize;
}

int& MyVector::operator[](const unsigned int index) const
{
	assert(index < mSize);

	return *(mData + index);
}

void MyVector::operator=(const MyVector& rhs)
{
	mSize = rhs.mSize;
	mCapacity = rhs.mCapacity;

	delete[] mData;
	mData = new int[mCapacity];

	dataCopy(rhs);
}

bool MyVector::operator==(const MyVector& rhs)
{
	if (mSize != rhs.mSize || mCapacity != rhs.mCapacity) 
	{
		return false;
	}
	
	for (unsigned int i = 0; i < mSize; ++i) 
	{
		if (*(mData + i) != *(rhs.mData + i)) 
		{
			return false;
		}
	}

	return true;
}

void MyVector::dataCopy(const MyVector& other)
{
	for (unsigned int i = 0; i < mSize; ++i)
	{
		*(mData + i) = *(other.mData + i);
	}
}
