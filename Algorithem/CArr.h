#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class CArr
{
public:
	CArr();
	CArr(const CArr<T>& other);
	~CArr();

	CArr<T>& operator=(const CArr<T>& other);
	bool operator==(const CArr<T>& other) const;
	T& operator[](const unsigned int index) const;

	void pushBack(const T& data);
	void pushIndex(const T& data, const unsigned int index);
	void resize(const unsigned int size);
	void remove(const unsigned int index);
	unsigned int getCount() const;
	unsigned int getSize() const;
	void print() const;

private:
	T* mArr;
	unsigned int mSize;
	unsigned int mCount;

	void dataCopy(T* target, const T* source, const unsigned int count);
};

// 템플릿 클래스 함수 상세 구현

template<typename T>
CArr<T>::CArr()
	: mSize(2) // 기본 정책은 공간 2개 만들기, 더 필요하면 resize() 이용
	, mCount(0)
{

	mArr = new T[mSize];
}

template<typename T>
CArr<T>::CArr(const CArr<T>& other)
	: mSize(other.mSize)
	, mCount(other.mCount)

{
	mArr = new T[mSize];

	dataCopy(mArr, other.mArr, other.mCount);
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] mArr;
}

template<typename T>
CArr<T>& CArr<T>::operator=(const CArr<T>& other)
{
	mSize = other.mSize;
	mCount = other.mCount;

	delete[] mArr;
	mArr = new T[mSize];

	dataCopy(mArr, other.mArr, other.mCount);

	return *this;
}

template<typename T>
bool CArr<T>::operator==(const CArr<T>& other) const
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

template<typename T>
T& CArr<T>:: operator[](const unsigned int index) const
{
	assert(mCount > index);

	return *(mArr + index);
}

template<typename T>
void CArr<T>::pushBack(const T& data)
{
	if (mSize == mCount)
	{
		resize(mSize * 2);
	}

	*(mArr + mCount) = data;
	mCount++;
}

template<typename T>
void CArr<T>::pushIndex(const T& data, const unsigned int index)
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

template<typename T>
void CArr<T>::resize(const unsigned int size)
{
	assert(mSize < size);

	mSize = size;
	T* p = new T[mSize];

	dataCopy(p, mArr, mCount);

	delete[] mArr;
	mArr = p;
}

template<typename T>
void CArr<T>::remove(const unsigned int index)
{
	assert(mCount > index);

	*(mArr + index) = *(mArr + mCount - 1);
	mCount--;
}

template<typename T>
unsigned int CArr<T>::getCount() const
{
	return mCount;
}

template<typename T>
unsigned int CArr<T>::getSize() const
{
	return mSize;
}

template<typename T>
void CArr<T>::print() const
{
	for (unsigned int i = 0; i < mCount; i++)
	{
		cout << *(mArr + i) << "  ";
	}
	cout << endl;
}

template<typename T>
void CArr<T>::dataCopy(T* target, const T* source, const unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		*(target + i) = *(source + i);
	}
}