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

	// 전방선언
	class iterator;

	iterator begin();
	iterator end();
	iterator rBegin();
	iterator rEnd();

	class iterator {
	public:
		iterator();
		iterator(MyVector* arr, int* arrData, int size);
		~iterator() = default;

		iterator& operator++() 
		{
			assert(mArrSize == mArr->mSize);
			assert(mArr->mData + mArrSize + 1 != mArrData + 1);

			++mArrData;
	
			return *this;
		}

		iterator& operator--() 
		{
			assert(mArrSize == mArr->mSize);
			assert(mArr->mData - 1 != mArrData);

			--mArrData;

			return *this;
		}

		bool operator!=(const iterator& rhs) 
		{
			assert(mArrSize == mArr->mSize && rhs.mArrSize == mArr->mSize);

			if (this->mArrData != rhs.mArrData) 
			{
				return true;
			}
			return false;
		}

		bool operator==(const iterator& rhs) 
		{
			return !(operator!=(rhs));
		}

		int& operator*() 
		{
			assert(mArr->mData + mArrSize + 1 != mArrData + 1);

			return *mArrData;
		}

	private:
		MyVector* mArr;
		int* mArrData;
		int mArrSize;
	};

private:
	int* mData;
	int mCapacity;
	int mSize;

	void dataCopy(const MyVector& other);
};

