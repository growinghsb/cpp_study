#include <iostream>
#include <cassert>

#include "CArr.h"

using namespace std;

CArr::CArr()
	: mSize(2) // 기본 정책은 공간 2개 만들기, 더 필요하면 resize() 이용
	, mCount(0)
{
	
	mArr = new int[mSize];
}

CArr::CArr(const CArr& other)
	: mSize(other.mSize)
	, mCount(other.mCount)
	
{
	mArr = new int[mSize];

	dataCopy(mArr, other.mArr, other.mCount);
}

CArr::~CArr()
{
	delete[] mArr;
}

CArr& CArr::operator=(const CArr& other)
{
	mSize = other.mSize;
	mCount = other.mCount;

	delete[] mArr;
	mArr = new int[mSize];

	dataCopy(mArr, other.mArr, other.mCount);

	return *this;
}

bool CArr::operator==(const CArr& other) const
{
	if (mCount != other.mCount) {
		return false;
	}

	for (unsigned int i = 0; i < mCount; i++)
	{
		if (*(mArr + i) != *(other.mArr + i)) {
			return false;
		}
	}

	return true;
}

int& CArr::operator[](const unsigned int index) const
{
	assert(mCount > index);

	return *(mArr + index);
}

void CArr::pushBack(const int data)
{
	if (mSize == mCount)
	{
		resize(mSize * 2);
	}

	*(mArr + mCount) = data;
	mCount++;
}

void CArr::pushIndex(const int data, const unsigned int index)
{
	assert(mCount > index);

	if (mSize == mCount)
	{
		resize(mSize * 2);
	}

	*(mArr + mCount) = *(mArr + index);
	*(mArr + index) = data;
	mCount++;
}

void CArr::resize(const unsigned int size)
{
	assert(mSize < size);

	mSize = size;
	int* p = new int[mSize];

	dataCopy(p, mArr, mCount);

	delete[] mArr;
	mArr = p;
}

void CArr::remove(const unsigned int index)
{
	assert(mCount > index);

	*(mArr + index) = *(mArr + mCount - 1);
	mCount--;
}

unsigned int CArr::getCount() const
{
	return mCount;
}

unsigned int CArr::getSize() const
{
	return mSize;
}

void CArr::print() const
{
	for (unsigned int i = 0; i < mCount; i++)
	{
		cout << *(mArr + i) << "  ";
	}
	cout << endl;
}

void CArr::dataCopy(int* target, const int* source, const unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		*(target + i) = *(source + i);
	}
}
