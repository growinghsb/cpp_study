#pragma once

#include"MyVector.h"
#include"MyLinkedList.h"

using std::hash;

/*
   HashPair class
*/
template<typename KEY, typename VALUE>
class HashPair
{
	template<typename KEY, typename VALUE>
	friend class HashMap;

	template<typename KEY, typename VALUE>
	friend std::ostream& operator<<(std::ostream& os, const HashPair<KEY, VALUE>& rhs);

public:
	HashPair();
	HashPair(KEY key);
	HashPair(KEY key, VALUE value);

	bool operator==(const HashPair<KEY, VALUE>& rhs)
	{
		if (this == &rhs)
		{
			return true;
		}

		return mKey == rhs.mKey ? true : false;
	}

	bool operator==(const KEY& key)
	{
		return mKey == key ? true : false;
	}

private:
	KEY mKey;
	VALUE mValue;
};

/*
   HashMap class
*/
template<typename KEY, typename VALUE>
class HashMap
{
public:
	HashMap();
	HashMap(KEY key, VALUE value);
	HashMap(HashPair<KEY, VALUE> hashPair);

	void insert(KEY& key, VALUE& value);
	void insert(KEY&& key, VALUE&& value);
	void insert(HashPair<KEY, VALUE> pairData);

	HashPair<KEY, VALUE> get(const KEY key);

	void bucketResize(const int newBucketCount);

	void printMap() const;

private:
	const unsigned int getBucketIndex(const KEY key);

	MyVector<MyLinkedList<HashPair<KEY, VALUE>>> mBucket;
	int mBucketCount;
	int mDataCount;
};

// << 연산자 오버로딩
template<typename KEY, typename VALUE>
std::ostream& operator<<(std::ostream& os, const HashPair<KEY, VALUE>& rhs)
{
	os << rhs.mKey << ", " << rhs.mValue;
	return os;
}

/*
   makeHashPair func
*/
template<typename KEY, typename VALUE>
HashPair<KEY, VALUE> makeHashPair(KEY key, VALUE value)
{
	return HashPair<KEY, VALUE>(key, value);
}

/*
   HashPair clsss func
*/
template<typename KEY, typename VALUE>
HashPair<KEY, VALUE>::HashPair()
	: mKey(0)
	, mValue(0)
{
}

template<typename KEY, typename VALUE>
HashPair<KEY, VALUE>::HashPair(KEY key)
	: mKey(key)
{
}

template<typename KEY, typename VALUE>
HashPair<KEY, VALUE>::HashPair(KEY key, VALUE value)
	: mKey(key)
	, mValue(value)
{
}

/*
   HashMap class func
*/
template<typename KEY, typename VALUE>
HashMap<KEY, VALUE>::HashMap()
	: mBucket()
	, mBucketCount(11)
	, mDataCount(0)
{
	mBucket.resize(mBucketCount);
}

template<typename KEY, typename VALUE>
HashMap<KEY, VALUE>::HashMap(KEY key, VALUE value)
	: mBucket()
	, mBucketCount(11)
	, mDataCount(0)
{
	mBucket.resize(mBucketCount);
	insert(key, value);
}

template<typename KEY, typename VALUE>
HashMap<KEY, VALUE>::HashMap(HashPair<KEY, VALUE> hashPair)
	: mBucket()
	, mBucketCount(11)
	, mDataCount(0)
{
	mBucket.resize(mBucketCount);
	insert(hashPair);
}

template<typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::insert(KEY& key, VALUE& value)
{
	if (mBucketCount == mDataCount)
	{
		bucketResize(mBucketCount * 2);
	}

	HashPair<KEY, VALUE> pairData(key, value);
	const unsigned int bucketIndex = getBucketIndex(pairData.mKey);

	if (!mBucket[bucketIndex].isData(pairData))
	{
		mBucket[bucketIndex].pushBack(pairData);
		++mDataCount;
	}
}

template<typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::insert(KEY&& key, VALUE&& value)
{
	insert(key, value);
}

template<typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::insert(HashPair<KEY, VALUE> pairData)
{
	if (mBucketCount == mDataCount)
	{
		bucketResize(mBucketCount * 2);
	}

	const unsigned int bucketIndex = getBucketIndex(pairData.mKey);

	if (!mBucket[bucketIndex].isData(pairData))
	{
		mBucket[bucketIndex].pushBack(pairData);
		++mDataCount;
	}
}

template<typename KEY, typename VALUE>
HashPair<KEY, VALUE> HashMap<KEY, VALUE>::get(const KEY key)
{
	HashPair<KEY, VALUE> tmpPair(key);
	const unsigned int index = getBucketIndex(key);

	if (mBucket[index].isData(tmpPair))
	{
		typename MyLinkedList<HashPair<KEY, VALUE>>::iterator iter = mBucket[index].get(tmpPair);
		return HashPair<KEY, VALUE>(*iter);
	}

	return HashPair<KEY, VALUE>(0, 0);
}

template<typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::bucketResize(const int newBucketCount)
{
	assert(mBucketCount < newBucketCount);

	mBucketCount = newBucketCount;

	mBucket.resize(mBucketCount);
}

template<typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::printMap() const
{
	for (int i = 0; i < mBucketCount; ++i)
	{
		cout << "[" << i << "] -> ";
		mBucket[i].printOrder();
		cout << endl;
	}
}

template<typename KEY, typename VALUE>
const unsigned int HashMap<KEY, VALUE>::getBucketIndex(const KEY key)
{
	hash<KEY> keyHashCode;
	return keyHashCode(key) % mBucketCount;
}