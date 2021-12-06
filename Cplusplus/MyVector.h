#pragma once

#include<cassert>

class MyVector
{
public:
	MyVector();
	~MyVector();

	// const MyVector* const other
	MyVector(const MyVector& other);

	void reserve(const unsigned int newCapacity);
	void pushBack(const int data);
	int& operator[](const unsigned int index)const;
	void operator=(const MyVector& rhs);
	bool operator==(const MyVector& rhs);

	int getSize() const
	{
		return mSize;
	}

	int getCapacity() const
	{
		return mCapacity;
	}

	int front() const
	{
		assert(0 < mSize);

		return *mData;
	}

	int back() const
	{
		assert(0 < mSize);

		return *(mData + mSize - 1);
	}

	bool empty() const
	{
		if (0 == mSize)
		{
			return true;
		}
		return false;
	}

	void popBack()
	{
		assert(0 < mSize);

		--mSize;
	}

private:
	int* mData;
	int mCapacity;
	int mSize;

	void dataCopy(const MyVector& other);
};

