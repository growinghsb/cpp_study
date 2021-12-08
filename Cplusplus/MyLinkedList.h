#pragma once

#include <cassert>
#include<iostream>

using std::cout;
using std::endl;

/*
	class Node
*/

template<typename T>
class Node
{
	template<typename T>
	friend class MyLinkedList;

public:
	Node() = delete;

	T& getData()
	{
		return mData;
	}

	Node<T>* getNextNode() 
	{
		return mNextNode;
	}
	
	Node<T>* getPrevNode() 
	{
		return mPrevNode;
	}

private:
	Node(T& data);
	~Node() = default;

	void setNextNode(Node<T>* nextNode)
	{
		mNextNode = nextNode;
	}

	void setPrevNode(Node<T>* prevNode)
	{
		mPrevNode = prevNode;
	}

	T mData;
	Node<T>* mNextNode;
	Node<T>* mPrevNode;
};

/*
	class list
*/

template<typename T>
class MyLinkedList
{
public:
	MyLinkedList();
	MyLinkedList(const MyLinkedList<T>& other);
	~MyLinkedList();

	void pushFront(T data);
	void pushBack(T data);

	void popFront();
	void popBack();

	bool isData(const T searchData) const;

	void clear();

	void operator=(const MyLinkedList<T>& rhs);

	void printOrder() const;
	void printReverseOrder() const;

	class iterator;

	iterator begin();
	iterator end();

	int getNodeSize() const
	{
		return mNodeSize;
	}

	T& getFront() const
	{
		assert(nullptr != mHeadNode);

		return mHeadNode->mData;
	}

	T& getBack() const
	{
		assert(nullptr != mTailNode);

		return mTailNode->mData;
	}

	bool isEmpty() const
	{
		if (0 == mNodeSize)
		{
			return true;
		}
		return false;
	}

	class iterator
	{
	public:
		iterator();
		iterator(MyLinkedList<T>* list, Node<T>* targetNode);
		~iterator() = default;

		bool operator!=(iterator& rhs)
		{
			assert(mList == rhs.mList);

			if (mTargetNode != rhs.mTargetNode)
			{
				return true;
			}
			return false;
		}

		bool operator==(iterator& rhs)
		{
			return !((*this) != rhs);
		}

		iterator& operator++()
		{
			assert(nullptr != mTargetNode);

			mTargetNode = mTargetNode->getNextNode();

			return *this;
		}

		T& operator* ()
		{
			assert(nullptr != mTargetNode);

			return mTargetNode->getData();
		}

	private:
		MyLinkedList<T>* mList;
		Node<T>* mTargetNode;
	};

private:
	Node<T>* mHeadNode;
	Node<T>* mTailNode;
	int mNodeSize;
};

/*
	Node func
*/

template<typename T>
Node<T>::Node(T& data)
	: mData(data)
	, mNextNode(nullptr)
	, mPrevNode(nullptr)
{
}

/*
	MyLinkedList func
*/

template<typename T>
MyLinkedList<T>::MyLinkedList()
	: mHeadNode(nullptr)
	, mTailNode(nullptr)
	, mNodeSize(0)
{
}

template<typename T>
MyLinkedList<T>::MyLinkedList(const MyLinkedList<T>& other)
	: mHeadNode(nullptr)
	, mTailNode(nullptr)
	, mNodeSize(0)
{
	Node<T>* tmpNode = other.mHeadNode;

	while (nullptr != tmpNode)
	{
		pushBack(tmpNode->mData);

		tmpNode = tmpNode->mNextNode;
	}
}

template<typename T>
MyLinkedList<T>::~MyLinkedList()
{
	clear();
}

template<typename T>
void MyLinkedList<T>::pushFront(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (nullptr == mHeadNode)
	{
		mTailNode = newNode;
	}
	else
	{
		mHeadNode->setPrevNode(newNode);
		newNode->setNextNode(mHeadNode);
	}

	mHeadNode = newNode;
	++mNodeSize;
}

template<typename T>
void MyLinkedList<T>::pushBack(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (nullptr == mHeadNode)
	{
		mHeadNode = newNode;
	}
	else
	{
		mTailNode->setNextNode(newNode);
		newNode->setPrevNode(mTailNode);
	}

	mTailNode = newNode;
	++mNodeSize;
}


template<typename T>
void MyLinkedList<T>::popFront()
{
	assert(0 != mNodeSize);

	if (1 == mNodeSize)
	{
		delete mHeadNode;

		mHeadNode = nullptr;
		mTailNode = nullptr;
	}
	else
	{
		mHeadNode = mHeadNode->mNextNode;
		delete mHeadNode->mPrevNode;
		mHeadNode->setPrevNode(nullptr);
	}

	--mNodeSize;
}


template<typename T>
void MyLinkedList<T>::popBack()
{
	assert(0 != mNodeSize);

	if (1 == mNodeSize)
	{
		delete mHeadNode;

		mHeadNode = nullptr;
		mTailNode = nullptr;
	}
	else
	{
		mTailNode = mTailNode->mPrevNode;
		delete mTailNode->mNextNode;
		mTailNode->setNextNode(nullptr);
	}

	--mNodeSize;
}

template<typename T>
bool MyLinkedList<T>::isData(const T searchData) const
{
	Node<T>* tmpNode = mHeadNode;

	while (nullptr != tmpNode)
	{
		if (tmpNode->mData == searchData)
		{
			return true;
		}
		tmpNode = tmpNode->mNextNode;
	}

	return false;
}

template<typename T>
void MyLinkedList<T>::clear()
{
	while (mNodeSize > 0)
	{
		popFront();
	}
}

template<typename T>
void MyLinkedList<T>::operator=(const MyLinkedList<T>& rhs)
{
	clear();

	Node<T>* tmpNode = rhs.mHeadNode;

	while (nullptr != tmpNode)
	{
		pushBack(tmpNode->mData);

		tmpNode = tmpNode->mNextNode;
	}
}

template<typename T>
void MyLinkedList<T>::printOrder() const
{
	Node<T>* tmpNode = mHeadNode;

	while (nullptr != tmpNode)
	{
		cout << "[" << tmpNode->mData << "] ";

		tmpNode = tmpNode->mNextNode;
	}

	cout << endl;
}

template<typename T>
void MyLinkedList<T>::printReverseOrder() const
{
	Node<T>* tmpNode = mTailNode;

	while (nullptr != tmpNode)
	{
		cout << "[" << tmpNode->mData << "] ";

		tmpNode = tmpNode->mPrevNode;
	}

	cout << endl;
}

template<typename T>
typename MyLinkedList<T>::iterator MyLinkedList<T>::begin()
{
	return iterator(this, mHeadNode);
}

template<typename T>
typename MyLinkedList<T>::iterator MyLinkedList<T>::end()
{
	return iterator(this, nullptr);
}

/*
	iterator func
*/

template<typename T>
MyLinkedList<T>::iterator::iterator()
	: mList(nullptr)
	, mTargetNode(nullptr)
{
}

template<typename T>
MyLinkedList<T>::iterator::iterator(MyLinkedList<T>* list, Node<T>* targetNode)
	: mList(list)
	, mTargetNode(targetNode)
{
}