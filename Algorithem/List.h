#pragma once

template<typename T>
class MyList {

protected:
	unsigned int mSize;

public:
			 MyList();
	virtual ~MyList();

	virtual void         PushBack(const T& value) = 0;
	virtual void		 Remove(const T& value) = 0;
	virtual unsigned int GetSize() const = 0;
	virtual void		 Sort(void(func*)(void)) const = 0;

	virtual T&	 operator[](const unsigned int index) const = 0;
	virtual T&   operator++() = 0;
	virtual T&   operator--() = 0;
	virtual bool operator<(const MyList<T>& rhs) const = 0;
	virtual bool operator==(const MyList<T>& rhs) const = 0;
	virtual bool operator!=(const MyList<T>& rhs) const = 0;
};

template<typename T>
inline MyList<T>::MyList()
	: mSize(0)
{
}

template<typename T>
inline MyList<T>::~MyList()
{
}
