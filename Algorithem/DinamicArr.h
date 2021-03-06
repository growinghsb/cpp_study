#pragma once

#include<cstring>
#include<cassert>

#include "List.h"
#include "Sorted.h"

template<typename T>
class ArrayList : public MyList<T> {

private:
	T* mArr;
	unsigned int mCapacity;

public:
	ArrayList();
	ArrayList(const unsigned int capacity);
	ArrayList(const ArrayList<T>& other);
	virtual ~ArrayList();

	virtual void         PushBack(const T& value);
	void				 PushIndex(const T& value, const unsigned int index);
	virtual bool		 Remove(const T& value);
	void				 RemoveIndex(const unsigned int index);
	T					 Get(const unsigned int index) const;
	int			 		 Search(const T& value);
	unsigned int		 GetCapacity() const;
	void				 Increase(const unsigned int capacity);
	void			     Sort(void(*func)(T*, int, int));

	T* GetArr();

	ArrayList<T>& operator=(const ArrayList<T>& other);
	T& operator[](const unsigned int index);
	bool  operator==(const ArrayList<T>& rhs) const;
	bool  operator!=(const ArrayList<T>& rhs) const;
};

template<typename T>
inline ArrayList<T>::ArrayList()
	: mCapacity(16)
{
	mArr = new T[mCapacity];
	memset(mArr, 0, mCapacity);
}

template<typename T>
inline ArrayList<T>::ArrayList(const unsigned int capacity)
	: mCapacity(capacity)
{
	mArr = new T[mCapacity];
	memset(mArr, 0, mCapacity);
}

template<typename T>
inline ArrayList<T>::ArrayList(const ArrayList<T>& other)
	: MyList<T>(other.GetSize())
	, mCapacity(other.mCapacity)
{
	mArr = new T[mCapacity];
	T* tmp = mArr;

	for (unsigned int i = 0; i < this->GetSize(); ++i)
	{
		*(tmp + i) = *(other.mArr + i);
	}
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
	delete[] mArr;
}

template<typename T>
inline void ArrayList<T>::PushBack(const T& value)
{
	if (mCapacity == this->GetSize())
	{
		Increase(mCapacity * 2);
	}
	*(mArr + this->GetSize()) = value;
	this->IncreaseSize();
}

template<typename T>
inline void ArrayList<T>::PushIndex(const T& value, const unsigned int index)
{
	if (mCapacity == this->GetSize())
	{
		Increase(mCapacity * 2);
	}
	*(mArr + this->GetSize()) = *(mArr + index);
	*(mArr + index) = value;
	this->IncreaseSize();
}

template<typename T>
inline bool ArrayList<T>::Remove(const T& value)
{
	int index = Search(value);
	
	if (-1 != index) 
	{
		RemoveIndex(index);
		return true;
	}
	return false;
}

template<typename T>
inline void ArrayList<T>::RemoveIndex(const unsigned int index)
{
	if (0 < this->GetSize())
	{
		*(mArr + index) = *(mArr + this->GetSize() - 1);
		this->DecreaseSize();
	}
}

template<typename T>
inline T ArrayList<T>::Get(const unsigned int index) const
{
	return *(mArr + index);
}

template<typename T>
inline void ArrayList<T>::Sort(void(*func)(T*, int, int))
{
	func(mArr, 0, this->GetSize() - 1);
}

template<typename T>
inline T* ArrayList<T>::GetArr()
{
	return mArr;
}

template<typename T>
inline int ArrayList<T>::Search(const T& value)
{
	Sort(QuickSort);

	int start = 0;
	int end = this->GetSize();

	while (start <= end)
	{
		int mid = (end + start) / 2;

		if (*(mArr + mid) < value)
		{
			start = mid + 1;
		}
		else if (*(mArr + mid) > value)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

template<typename T>
inline unsigned int ArrayList<T>::GetCapacity() const
{
	return mCapacity;
}

template<typename T>
inline void ArrayList<T>::Increase(const unsigned int capacity)
{
	if (mCapacity < capacity)
	{
		mCapacity = capacity;

		T* p = new T[mCapacity];
		T* tmp = p;

		for (unsigned int i = 0; i < this->GetSize(); i++)
		{
			*(tmp + i) = *(mArr + i);
		}
		delete[] mArr;
		mArr = p;
	}
}

template<typename T>
inline ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
{
	T* p = nullptr;

	if (mCapacity > other.mCapacity)
	{
		memset(mArr, 0, mCapacity);
		p = mArr;
	}
	else
	{
		mCapacity = other.mCapacity;

		delete[] mArr;
		p = new T[mCapacity];
		mArr = p;
	}
	this->SetSize(other.GetSize());

	for (unsigned int i = 0; i < this->GetSize(); i++)
	{
		*(p + i) = *(other.mArr + i);
	}
	return *this;
}

template<typename T>
inline T& ArrayList<T>::operator[](const unsigned int index)
{
	return *(mArr + index);
}

template<typename T>
inline bool ArrayList<T>::operator==(const ArrayList<T>& rhs) const
{
	unsigned int size = this->GetSize();
	if (size != rhs.GetSize())
	{
		return false;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		if (*(mArr + i) != *(rhs.mArr + i))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
inline bool ArrayList<T>::operator!=(const ArrayList<T>& rhs) const
{
	unsigned int size = this->GetSize();
	if (size != rhs.GetSize())
	{
		return true;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		if (*(mArr + i) != *(rhs.mArr + i))
		{
			return true;
		}
	}
	return false;
}