#pragma once

template<typename T>
class MyList {

private:
	unsigned int mSize;

public:
	MyList();
	MyList(const unsigned int size);
	virtual ~MyList();

	virtual void         PushBack(const T& value) = 0;
	virtual void		 Remove(const T& value) = 0;
	virtual void		 Sort(void(*func)(void)) const = 0;

	virtual unsigned int GetSize() const;
	virtual void		 SetSize(const unsigned int size);
	virtual void		 IncreaseSize();
	virtual void		 DecreaseSize();

};

template<typename T>
inline MyList<T>::MyList()
	: mSize(0)
{
}

template<typename T>
inline MyList<T>::MyList(const unsigned int size)
	: mSize(size)
{
}

template<typename T>
inline MyList<T>::~MyList()
{
}

template<typename T>
inline unsigned int MyList<T>::GetSize() const
{
	return mSize;
}

template<typename T>
inline void MyList<T>::SetSize(const unsigned int size)
{
	mSize = size;
}

template<typename T>
inline void MyList<T>::IncreaseSize()
{
	++mSize;
}

template<typename T>
inline void MyList<T>::DecreaseSize()
{
	--mSize;
}
