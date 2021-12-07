#pragma once

#include <cassert>

/*
	class Node
*/

class Node
{
	friend class MyLinkedList;

public:
	Node() = delete;

private:
	Node(int data);
	~Node() = default;

	void setNextNode(Node* nextNode)
	{
		mNextNode = nextNode;
	}

	void setPrevNode(Node* prevNode)
	{
		mPrevNode = prevNode;
	}

	int mData;
	Node* mNextNode;
	Node* mPrevNode;
};

/*
	class list
*/

class MyLinkedList
{
public:
	MyLinkedList();
	MyLinkedList(const MyLinkedList& other);
	~MyLinkedList();

	void pushFront(int data);
	void pushBack(int data);

	void popFront();
	void popBack();

	bool isData(const int searchData) const;

	void clear();

	void operator=(const MyLinkedList& rhs);

	void printOrder() const;
	void printReverseOrder() const;

	int getNodeSize() const
	{
		return mNodeSize;
	}

	int getFront() const
	{
		assert(nullptr != mHeadNode);

		return mHeadNode->mData;
	}

	int getBack() const
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

private:
	Node* mHeadNode;
	Node* mTailNode;
	int mNodeSize;
};

