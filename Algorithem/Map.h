/*
	map �� ��� pair ��ü�� Ű-���� �����Ѵ�.

	�� pair ��ü�� ������ �� ū Ŭ������ Node ��ü�� �ִ�.

	Node ��ü���� �ڽ��� �θ�, �����ڽ�, �������ڽ���
	����Ű�� ������ ������ �ִ�. �ű⿡ pair ��ü�� �ִ�.

	4���� ��������� ������ Node ��ü�� �����Ҵ� �޾�
	�����ϰ�, pair �ȿ� �ִ� Ű�� �������� ���� �����
	���� �����鼭 �����͸� ������ ���� ã�´�.

	�� Node ��ü�� �����͸� �����ϴ� �����̴�.
*/
#pragma once

#include <iostream>

using std::cout;
using std::endl;

/*
	pair class
*/
template<typename KeyT, typename ValueT>
class MyPair {
private:
	KeyT	mKey;
	ValueT  mValue;

public:
	MyPair(KeyT key, ValueT value);
	~MyPair();

	KeyT   GetKey() const;
	ValueT GetValue() const;
};

template<typename KeyT, typename ValueT>
inline MyPair<KeyT, ValueT>::MyPair(KeyT key, ValueT value)
	: mKey(key)
	, mValue(value)
{
}

template<typename KeyT, typename ValueT>
inline MyPair<KeyT, ValueT>::~MyPair()
{
}

template<typename KeyT, typename ValueT>
inline KeyT MyPair<KeyT, ValueT>::GetKey() const
{
	return mKey;
}

template<typename KeyT, typename ValueT>
inline ValueT MyPair<KeyT, ValueT>::GetValue() const
{
	return mValue;
}

/*
	Node class
*/
template<typename KeyT, typename ValueT>
class Node {
private:
	MyPair<KeyT, ValueT> mPair;
	Node* mParent;
	Node* mLeftChild;
	Node* mRightChild;

public:
	Node(MyPair<KeyT, ValueT> pair);
	~Node();

	MyPair<KeyT, ValueT> GetPair() const;
	Node<KeyT, ValueT>* GetParent() const;
	Node<KeyT, ValueT>* GetLeftChild() const;
	Node<KeyT, ValueT>* GetRightChild() const;

	void SetParent(Node<KeyT, ValueT>* parent);
	void SetLeftChild(Node<KeyT, ValueT>* leftChild);
	void SetRightChild(Node<KeyT, ValueT>* rightChild);

};

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>::Node(MyPair<KeyT, ValueT> pair)
	: mPair(pair)
	, mParent(nullptr)
	, mLeftChild(nullptr)
	, mRightChild(nullptr)
{
}

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>::~Node()
{
}

template<typename KeyT, typename ValueT>
inline MyPair<KeyT, ValueT> Node<KeyT, ValueT>::GetPair() const
{
	return mPair;
}

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>* Node<KeyT, ValueT>::GetParent() const
{
	return mParent;
}

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>* Node<KeyT, ValueT>::GetLeftChild() const
{
	return mLeftChild;
}

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>* Node<KeyT, ValueT>::GetRightChild() const
{
	return mRightChild;
}

template<typename KeyT, typename ValueT>
inline void Node<KeyT, ValueT>::SetParent(Node<KeyT, ValueT>* parent)
{
	mParent = parent;
}

template<typename KeyT, typename ValueT>
inline void Node<KeyT, ValueT>::SetLeftChild(Node<KeyT, ValueT>* leftChild)
{
	mLeftChild = leftChild;
}

template<typename KeyT, typename ValueT>
inline void Node<KeyT, ValueT>::SetRightChild(Node<KeyT, ValueT>* rightChild)
{
	mRightChild = rightChild;
}

/*
	map class
*/
template<typename KeyT, typename ValueT>
class MyMap {
private:
	Node<KeyT, ValueT>* mRootNode;
	unsigned int mCount;

public:
	MyMap();
	~MyMap();
	bool Insert(const MyPair<KeyT, ValueT>& pair);
};

template<typename KeyT, typename ValueT>
inline MyMap<KeyT, ValueT>::MyMap()
	: mRootNode(nullptr)
	, mCount(0)
{
}

template<typename KeyT, typename ValueT>
inline MyMap<KeyT, ValueT>::~MyMap()
{
}

template<typename KeyT, typename ValueT>
inline bool MyMap<KeyT, ValueT>::Insert(const MyPair<KeyT, ValueT>& pair)
{
	Node<KeyT, ValueT>* newNode = new Node<KeyT, ValueT>(pair);

	if (nullptr == mRootNode)
	{
		mRootNode = newNode;
	}
	else
	{
		Node<KeyT, ValueT>* target = mRootNode;
		Node<KeyT, ValueT>* parent = nullptr;

		while (true)
		{
			parent = target;

			if (target->GetPair().GetKey() < newNode->GetPair().GetKey())
			{
				if (nullptr == target->GetRightChild())
				{
					target->SetRightChild(newNode);
					break;
				}
				target = target->GetRightChild();
			}
			else if (target->GetPair().GetKey() > newNode->GetPair().GetKey())
			{
				if (nullptr == target->GetLeftChild())
				{
					target->SetLeftChild(newNode);
					break;
				}
				target = target->GetLeftChild();
			}
			else
			{
				return false;
			}
		}
		newNode->SetParent(parent);
	}
	++mCount;

	return true;
}