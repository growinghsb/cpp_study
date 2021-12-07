#include "MyLinkedList.h"

/*
	Node func
*/

Node::Node(int data)
	: mData(data)
	, mNextNode(nullptr)
	, mPrevNode(nullptr)
{
}

/*
	MyLinkedList func
*/

MyLinkedList::MyLinkedList()
	: mHeadNode(nullptr)
	, mTailNode(nullptr)
	, mNodeSize(0)
{
}

MyLinkedList::~MyLinkedList()
{
	clear();
}

void MyLinkedList::pushFront(int data)
{
	Node* newNode = new Node(data);

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

void MyLinkedList::pushBack(int data)
{
	Node* newNode = new Node(data);

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

void MyLinkedList::popFront()
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

void MyLinkedList::popBack()
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

void MyLinkedList::clear()
{
	while (mNodeSize > 0) 
	{
		popFront();
	}
}