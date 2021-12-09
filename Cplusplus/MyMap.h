#pragma once

template<typename KEY, typename VALUE>
class MyPair
{
public:
	MyPair();
	MyPair(KEY key, VALUE value);
	MyPair(const MyPair<KEY, VALUE>& other);
	MyPair(MyPair<KEY, VALUE>&& other) noexcept;
	~MyPair() = default;

	void operator=(const MyPair<KEY, VALUE>& rhs) 
	{
		if (this == &rhs)
		{
			return;
		}

		mKey = rhs.mKey;
		mValue = rhs.mValue;
	}

	void operator=(MyPair<KEY, VALUE>&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return;
		}
		
		mKey = rhs.mKey;
		mValue = rhs.mValue;

		rhs.mKey = 0;
		rhs.mValue = 0;
	}

	KEY mKey;
	VALUE mValue;
};

class MyMap
{
};

/*
	makePair func
*/
template<typename KEY, typename VALUE>
MyPair<KEY, VALUE> makePair(KEY key, VALUE value) 
{
	return MyPair<KEY, VALUE>(key, value);
}

/*
	Mypair class func
*/
template<typename KEY, typename VALUE>
inline MyPair<KEY, VALUE>::MyPair()
	: mKey(0)
	, mValue(0)
{
}

template<typename KEY, typename VALUE>
inline MyPair<KEY, VALUE>::MyPair(KEY key, VALUE value)
	: mKey(key)
	, mValue(value)
{
}

template<typename KEY, typename VALUE>
inline MyPair<KEY, VALUE>::MyPair(const MyPair<KEY, VALUE>& other)
	: mKey(other.mKey)
	, mValue(other.mValue)
{
}

template<typename KEY, typename VALUE>
inline MyPair<KEY, VALUE>::MyPair(MyPair<KEY, VALUE>&& other) noexcept
	: mKey(other.mKey)
	, mValue(other.mValue)
{
	other.mKey = 0;
	other.mValue = 0;
}