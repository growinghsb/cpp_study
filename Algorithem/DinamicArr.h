#pragma once

#include "List.h"

template<typename T>
class ArrayList : MyList<T> {

private:
	unsigned int mCapacity;

public:
			 ArrayList();
			 ArrayList(const unsigned int capacity);
			 ArrayList(const ArrayList<T>& other);
	virtual ~ArrayList();

	virtual void         PushBack(const T& value);
	void				 PushIndex(const unsigned int index);
	virtual void		 Remove(const T& value);
	void				 RemoveIndex(const unsigned int index);
	T					 Get(const unsigned int index) const;
	bool				 Search(const T& value) const;
	unsigned int		 GetCapacity() const;
	virtual unsigned int GetSize() const;
	void				 Increase(const unsigned int capacity);
	virtual void		 Sort(void(func*)(void)) const;

	ArrayList<T>& operator=(const MyList<T>& other);
	virtual T&	  operator[](const unsigned int index) const;
	virtual T&	  operator++();
	virtual T&	  operator--();
	virtual bool  operator<(const MyList<T>& rhs) const;
	virtual bool  operator==(const MyList<T>& rhs) const;
	virtual bool  operator!=(const MyList<T>& rhs) const;
};
