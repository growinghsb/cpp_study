#pragma once

#include"MyLinkedList.h"
#include"MyStack.h"

using std::cout;
using std::endl;
using std::move;

/*
	MyPair class
*/
template<typename KEY, typename VALUE>
class MyPair final
{
public:
	MyPair();
	MyPair(KEY key, VALUE value);
	MyPair(const MyPair<KEY, VALUE>& other);
	MyPair(MyPair<KEY, VALUE>&& other) noexcept;
	~MyPair() = default;

	void operator=(const MyPair<KEY, VALUE>& rhs)
	{
		if (this == &rhs)
		{
			return;
		}

		mKey = rhs.mKey;
		mValue = rhs.mValue;
	}

	void operator=(MyPair<KEY, VALUE>&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return;
		}

		mKey = rhs.mKey;
		mValue = rhs.mValue;

		rhs.mKey = 0;
		rhs.mValue = 0;
	}

	KEY mKey;
	VALUE mValue;
};

/*
	MyNode class
*/
template<typename KEY, typename VALUE>
class MyNode final
{
	template<typename KEY, typename VALUE>
	friend class MyMap;
public:
	MyNode() = delete;

private:
	MyNode(MyPair<KEY, VALUE>& pairData);
	~MyNode() = default;

	MyPair<KEY, VALUE> mPairData;
	MyNode<KEY, VALUE>* mParentNode;
	MyNode<KEY, VALUE>* mLeftChildNode;
	MyNode<KEY, VALUE>* mRightChildNode;
};

/*
	MyMap class
*/
template<typename KEY, typename VALUE>
class MyMap final
{
public:
	MyMap();
	~MyMap();

	void insert(MyPair<KEY, VALUE>& pairData);
	void insert(MyPair<KEY, VALUE>&& pairData);

	VALUE& find(const KEY& key);
	VALUE& find(const KEY&& key);

	void deleteNode(KEY&& key);

	void clear();
	void printMapLoop();
	void printMapRecursive();

	int getCount() const
	{
		return mCount;
	}

private:
	void orderRecursive(MyNode<KEY, VALUE>* target);
	void preInOrderDelete(MyNode<KEY, VALUE>* target);
	void postInOrderDelete(MyNode<KEY, VALUE>* target);

	MyNode<KEY, VALUE>* mRootNode;
	int mCount;
};

/*
	makePair func
*/
template<typename KEY, typename VALUE>
MyPair<KEY, VALUE> makePair(KEY key, VALUE value)
{
	return MyPair<KEY, VALUE>(key, value);
}

/*
	Mypair class func
*/
template<typename KEY, typename VALUE>
MyPair<KEY, VALUE>::MyPair()
	: mKey(0)
	, mValue(0)
{
}

template<typename KEY, typename VALUE>
MyPair<KEY, VALUE>::MyPair(KEY key, VALUE value)
	: mKey(key)
	, mValue(value)
{
}

template<typename KEY, typename VALUE>
MyPair<KEY, VALUE>::MyPair(const MyPair<KEY, VALUE>& other)
	: mKey(other.mKey)
	, mValue(other.mValue)
{
}

template<typename KEY, typename VALUE>
MyPair<KEY, VALUE>::MyPair(MyPair<KEY, VALUE>&& other) noexcept
	: mKey(other.mKey)
	, mValue(other.mValue)
{
	other.mKey = 0;
	other.mValue = 0;
}

/*
	MyNode class func
*/
template<typename KEY, typename VALUE>
MyNode<KEY, VALUE>::MyNode(MyPair<KEY, VALUE>& pairData)
	: mPairData(pairData)
	, mParentNode(nullptr)
	, mLeftChildNode(nullptr)
	, mRightChildNode(nullptr)
{

}

/*
	MyMap class func
*/
template<typename KEY, typename VALUE>
MyMap<KEY, VALUE>::MyMap()
	: mRootNode(nullptr)
	, mCount(0)
{
}

template<typename KEY, typename VALUE>
MyMap<KEY, VALUE>::~MyMap()
{
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::insert(MyPair<KEY, VALUE>& pairData)
{
	MyNode<KEY, VALUE>* newNode = new MyNode<KEY, VALUE>(pairData);
	++mCount;

	if (nullptr == mRootNode)
	{
		mRootNode = newNode;
	}
	else
	{
		MyNode<KEY, VALUE>* targetNode = mRootNode;

		while (nullptr != targetNode)
		{
			if (pairData.mKey > targetNode->mPairData.mKey)
			{
				if (nullptr == targetNode->mRightChildNode)
				{
					targetNode->mRightChildNode = newNode;
					newNode->mParentNode = targetNode;
					break;
				}

				targetNode = targetNode->mRightChildNode;
			}
			else if (pairData.mKey < targetNode->mPairData.mKey)
			{
				if (nullptr == targetNode->mLeftChildNode)
				{
					targetNode->mLeftChildNode = newNode;
					newNode->mParentNode = targetNode;
					break;
				}

				targetNode = targetNode->mLeftChildNode;
			}

			if (pairData.mKey == targetNode->mPairData.mKey)
			{
				--mCount;
				targetNode->mPairData = move(newNode->mPairData);
				delete newNode;

				break;
			}
		}
	}
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::insert(MyPair<KEY, VALUE>&& pairData)
{
	insert(pairData);
}

template<typename KEY, typename VALUE>
VALUE& MyMap<KEY, VALUE>::find(const KEY& key)
{
	assert(nullptr != mRootNode);

	MyNode<KEY, VALUE>* startNode = mRootNode;

	while (key != startNode->mPairData.mKey)
	{
		if (key > startNode->mPairData.mKey)
		{
			startNode = startNode->mRightChildNode;
		}
		else if (key < startNode->mPairData.mKey)
		{
			startNode = startNode->mLeftChildNode;
		}
	}

	return startNode->mPairData.mKey;
}

template<typename KEY, typename VALUE>
VALUE& MyMap<KEY, VALUE>::find(const KEY&& key)
{
	return find(key);
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::clear()
{
	assert(nullptr != mRootNode);

	MyLinkedList<MyNode<KEY, VALUE>*> queue;
	queue.pushBack(mRootNode);

	while (true != queue.isEmpty())
	{
		MyNode<KEY, VALUE>* targetNode = queue.popFront();

		if (nullptr != targetNode->mLeftChildNode)
		{
			queue.pushBack(targetNode->mLeftChildNode);
		}

		if (nullptr != targetNode->mRightChildNode)
		{
			queue.pushBack(targetNode->mRightChildNode);
		}

		delete targetNode;
	}

	mCount = 0;
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::printMapLoop()
{
	MyStack<MyNode<KEY, VALUE>*> stack;
	MyNode<KEY, VALUE>* target = mRootNode;

	while (true)
	{
		while (nullptr != target)
		{
			if (nullptr != target->mLeftChildNode)
			{
				stack.Push(target);
				target = target->mLeftChildNode;
			}
			else
			{
				cout << "[" << target->mPairData.mKey << ", " << target->mPairData.mValue << "] ";
				target = target->mRightChildNode;
			}
		}

		if (stack.isEmpty())
		{
			break;
		}
		else
		{
			target = stack.Pop();
			cout << "[" << target->mPairData.mKey << ", " << target->mPairData.mValue << "] ";

			target = target->mRightChildNode;
		}
	}
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::printMapRecursive()
{
	orderRecursive(mRootNode);
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::orderRecursive(MyNode<KEY, VALUE>* target)
{
	if (nullptr == target)
	{
		return;
	}

	orderRecursive(target->mLeftChildNode);
	cout << "[" << target->mPairData.mKey << ", " << target->mPairData.mValue << "] ";
	orderRecursive(target->mRightChildNode);
}

// 중위선행자 삭제
template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::preInOrderDelete(MyNode<KEY, VALUE>* target)
{
	MyNode<KEY, VALUE>* inOrderNode = target->mLeftChildNode;

	while (nullptr != inOrderNode->mRightChildNode)
	{
		inOrderNode = inOrderNode->mRightChildNode;
	}

	if (nullptr != inOrderNode->mLeftChildNode)
	{
		inOrderNode->mLeftChildNode->mParentNode = inOrderNode->mParentNode;	
	}

	inOrderNode == inOrderNode->mParentNode->mLeftChildNode
		? inOrderNode->mParentNode->mLeftChildNode = inOrderNode->mLeftChildNode
		: inOrderNode->mParentNode->mRightChildNode = inOrderNode->mLeftChildNode;

	MyPair<KEY, VALUE> tmpPair = move(target->mPairData);
	target->mPairData = move(inOrderNode->mPairData);
	inOrderNode->mPairData = move(tmpPair);

	delete inOrderNode;
}

// 중위후속자 삭제
template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::postInOrderDelete(MyNode<KEY, VALUE>* target)
{
	MyNode<KEY, VALUE>* inOrderNode = target->mRightChildNode;

	while (nullptr != inOrderNode->mLeftChildNode)
	{
		inOrderNode = inOrderNode->mLeftChildNode;
	}

	if (nullptr != inOrderNode->mRightChildNode)
	{
		inOrderNode->mRightChildNode->mParentNode = inOrderNode->mParentNode;
	}

	inOrderNode == inOrderNode->mParentNode->mLeftChildNode
		? inOrderNode->mParentNode->mLeftChildNode = inOrderNode->mRightChildNode
		: inOrderNode->mParentNode->mRightChildNode = inOrderNode->mRightChildNode;

	MyPair<KEY, VALUE> tmpPair = move(target->mPairData);
	target->mPairData = move(inOrderNode->mPairData);
	inOrderNode->mPairData = move(tmpPair);

	delete inOrderNode;
}

template<typename KEY, typename VALUE>
void MyMap<KEY, VALUE>::deleteNode(KEY&& key)
{
	MyNode<KEY, VALUE>* targetNode = mRootNode;

	while (nullptr != targetNode)
	{
		if (key > targetNode->mPairData.mKey)
		{
			targetNode = targetNode->mRightChildNode;
			continue;
		}

		if (key < targetNode->mPairData.mKey)
		{
			targetNode = targetNode->mLeftChildNode;
			continue;
		}

		--mCount;

		/*
			삭제 시 경우의 수
			1. 단말 노드인 경우
			2. 자식이 한 개 있는 노드인 경우
			3. 자식이 두 개 있는 노드인 경우
		*/

		// 1. 단말 노드인 경우
		if (nullptr == targetNode->mLeftChildNode && nullptr == targetNode->mRightChildNode)
		{
			if (targetNode->mParentNode->mLeftChildNode == targetNode)
			{
				targetNode->mParentNode->mLeftChildNode = nullptr;
			}
			else
			{
				targetNode->mParentNode->mRightChildNode = nullptr;
			}

			delete targetNode;
		}
		// 3. 자식이 두 개 있는 노드인 경우
		else if (nullptr != targetNode->mLeftChildNode && nullptr != targetNode->mRightChildNode)
		{
			preInOrderDelete(targetNode);
		}
		// 2. 자식이 한 개 있는 노드인 경우
		else
		{
			if (nullptr != targetNode->mLeftChildNode)
			{
				preInOrderDelete(targetNode);
			}
			else
			{
				postInOrderDelete(targetNode);
			}
		}

		break;
	}
}
