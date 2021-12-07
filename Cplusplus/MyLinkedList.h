#pragma once

#include <cassert>

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

class MyLinkedList
{
public:
	MyLinkedList();
	~MyLinkedList();

	void pushFront(int data);
	void pushBack(int data);

	void popFront();
	void popBack();

	void clear();

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


private:
	Node* mHeadNode;
	Node* mTailNode;
	int mNodeSize;
};

