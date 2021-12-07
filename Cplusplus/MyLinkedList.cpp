#include<iostream>

#include "MyLinkedList.h"

using std::cout;
using std::endl;

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

MyLinkedList::MyLinkedList(const MyLinkedList& other)
	: mHeadNode(nullptr)
	, mTailNode(nullptr)
	, mNodeSize(0)
{
	Node* tmpNode = other.mHeadNode;

	while(nullptr != tmpNode) 
	{
		pushBack(tmpNode->mData);

		tmpNode = tmpNode->mNextNode;
	}
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

bool MyLinkedList::isData(const int searchData) const
{
	Node* tmpNode = mHeadNode;

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

void MyLinkedList::clear()
{
	while (mNodeSize > 0) 
	{
		popFront();
	}
}

void MyLinkedList::operator=(const MyLinkedList& rhs)
{
	clear();

	Node* tmpNode = rhs.mHeadNode;

	while (nullptr != tmpNode) 
	{
		pushBack(tmpNode->mData);
		
		tmpNode = tmpNode->mNextNode;
	}
}

void MyLinkedList::printOrder() const 
{
	Node* tmpNode = mHeadNode;

	while (nullptr != tmpNode) 
	{
		cout << "[" << tmpNode->mData << "] ";
		
		tmpNode = tmpNode->mNextNode;
	}

	cout << endl;
}

void MyLinkedList::printReverseOrder() const 
{
	Node* tmpNode = mTailNode;

	while (nullptr != tmpNode) 
	{
		cout << "[" << tmpNode->mData << "] ";

		tmpNode = tmpNode->mPrevNode;
	}

	cout << endl;
}