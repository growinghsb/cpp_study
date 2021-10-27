#pragma once

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

// CArr class
template<typename T>
class CArr
{
private:
	T* mArr;
	unsigned int mSize;
	unsigned int mCount;

	void dataCopy(T* target, const T* source, const unsigned int count);

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

	class iterator;
	CArr<T>::iterator begin();
	CArr<T>::iterator end();

	// �ڵ������� �ܺ�Ŭ������ ���ø��� ����ȴ�. 
	class iterator {
	private:
		CArr<T>* mOutside;
		T* mIData;
		unsigned int mIndex;

	public:
		iterator();
		iterator(CArr<T>* outside, T* where, unsigned int index);
		~iterator();

		T& operator[](const unsigned int index);
		T& operator*();
		CArr<T>::iterator& operator++();
		CArr<T>::iterator& operator--();
		bool operator!=(const CArr<T>::iterator& iter);
	};
};
/*
	class ���� ��
*/

/*
	iterator innter class func
*/
template<typename T>
CArr<T>::iterator::iterator()
	: mOutside(nullptr)
	, mIData(nullptr)
	, mIndex(0)
{
}

template<typename T>
CArr<T>::iterator::iterator(CArr<T>* outside, T* where, unsigned int index)
	: mOutside(outside)
	, mIData(where)
	, mIndex(index)
{
}

template<typename T>
CArr<T>::iterator::~iterator()
{
	// �ܺ�Ŭ������ ���� �Ǹ� �굵 ȣ��ǳ�?

	/* ����Ŭ���� ��ü�� ������� ������ �׳� ��ü�� ���� ��
	 �Ҹ��ڰ� ȣ�� �Ǵ� ���̴�. ����Ŭ�������� �ܺ�Ŭ�����ʹ� �������.*/
}

template<typename T>
T& CArr<T>::iterator::operator[](const unsigned int index)
{
	assert(nullptr != mOutside && mIData == mOutside->mArr && mOutside->mCount > index);
	
	return *(mIData + index);
}

template<typename T>
T& CArr<T>::iterator::operator*()
{
	assert(nullptr != mOutside && mIData == mOutside->mArr && mOutside->mCount > mIndex);

	return *(mIData + mIndex);
}

template<typename T>
typename CArr<T>::iterator& CArr<T>::iterator::operator++()
{
	assert(nullptr != mOutside && mIData == mOutside->mArr && mOutside->mCount > mIndex);

	mIndex += 1;
	
	return *this;
}

template<typename T>
typename CArr<T>::iterator& CArr<T>::iterator::operator--()
{
	assert(nullptr != mOutside && mIData == mOutside->mArr && 0 < mIndex);

	mIndex -= 1;
	
	return *this;
}

template<typename T>
bool CArr<T>::iterator::operator!=(const CArr<T>::iterator& iter)
{
	if (mIndex != iter.mIndex) 
	{
		return true;
	}
	return false;
}

/*
	CArr class func
*/
template<typename T>
CArr<T>::CArr()
	: mSize(2) // �⺻ ��å�� ���� 2�� �����, �� �ʿ��ϸ� resize() �̿�
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

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	return CArr<T>::iterator(this, mArr, 0);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return CArr<T>::iterator(this, mArr, mCount);
}
