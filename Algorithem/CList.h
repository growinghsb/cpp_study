#pragma once

// class Node
template <typename T>
class Node {
public:
	T		 mData;
	Node<T>* mNext;
	Node<T>* mPrev;

	Node(T data);
};

template<typename T>
Node<T>::Node(T data)
	: mData(data)
	, mNext(nullptr)
	, mPrev(nullptr)
{

}

// class LinkedList
template<typename T>
class LinkedList {
private:
	Node<T>* mHead;
	Node<T>* mTail;
	unsigned int mCount;

public:
	LinkedList();
	~LinkedList();



	void pushBack(T data);
	void pushFront(T data);
	void remove(T data);

};

template<typename T>
LinkedList<T>::LinkedList()
	: mHead(nullptr)
	, mTail(nullptr)
	, mCount(0)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* target = mHead;

	while (target != nullptr)
	{
		mHead = target->mNext;
		delete target;
		target = mHead;
	}

	mCount = 0;
}

template<typename T>
void LinkedList<T>::pushBack(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (nullptr == mHead)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		newNode->mPrev = mTail;
		mTail->mNext = newNode;
		mTail = newNode;
	}

	mCount++;
}

template<typename T>
void LinkedList<T>::pushFront(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (nullptr == mHead)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		newNode->mNext = mHead;
		mHead->mPrev = newNode;
		mHead = newNode;
	}

	mCount++;
}

template<typename T>
void LinkedList<T>::remove(T data)
{
	Node<T>* start = mHead;

	if (start->mData == data)
	{
		mHead = start->mNext;
		start->mNext->mPrev = nullptr;
		delete start;
	}
	else
	{
		start = start->mNext;

		for (unsigned int i = 0; i < mCount; i++)
		{
			if (start->mData == data)
			{
				start->mPrev->mNext = start->mNext;
				start->mNext->mPrev = start->mPrev;
				delete start;
				break;
			}

			start = start->mNext;
		}
	}
	mCount--;
}
