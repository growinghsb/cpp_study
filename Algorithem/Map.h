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
#include <cassert>

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
	MyPair(const KeyT& key, const ValueT& value);
	~MyPair();

	const KeyT& GetKey() const;
	const ValueT& GetValue() const;
};

template<typename KeyT, typename ValueT>
inline MyPair<KeyT, ValueT>::MyPair(const KeyT& key, const ValueT& value)
	: mKey(key)
	, mValue(value)
{
}

template<typename KeyT, typename ValueT>
inline MyPair<KeyT, ValueT>::~MyPair()
{
}

template<typename KeyT, typename ValueT>
inline const KeyT& MyPair<KeyT, ValueT>::GetKey() const
{
	return mKey;
}

template<typename KeyT, typename ValueT>
inline const ValueT& MyPair<KeyT, ValueT>::GetValue() const
{
	return mValue;
}

/*
	make_pair func
*/
template<typename KeyT, typename ValueT>
const MyPair<KeyT, ValueT> MakeMyPair(const KeyT& key, const ValueT& value) {
	return MyPair<KeyT, ValueT>(key, value);
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
	Node(const MyPair<KeyT, ValueT>& pair);
	~Node();

	MyPair<KeyT, ValueT>* GetPair();
	Node<KeyT, ValueT>* GetParent() const;
	Node<KeyT, ValueT>* GetLeftChild() const;
	Node<KeyT, ValueT>* GetRightChild() const;

	void SetPair(MyPair<KeyT, ValueT> pair);
	void SetParent(Node<KeyT, ValueT>* parent);
	void SetLeftChild(Node<KeyT, ValueT>* leftChild);
	void SetRightChild(Node<KeyT, ValueT>* rightChild);
	/*
		Setter �� ������ �Ű������� const �� �ȵȴ�.
		������� = �Ű����� �ϴµ� const �Ű������� ������ �ȵȴ�.
		��������� const �� �ƴϱ� ����
	*/

};

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>::Node(const MyPair<KeyT, ValueT>& pair)
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
inline MyPair<KeyT, ValueT>* Node<KeyT, ValueT>::GetPair() // ���� const �� ������ & ��ȯ�� �ȵȴ�. 
														   // ���� ���ɼ��� �ִٰ� �����ϱ� ����
{
	return &mPair;
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
inline void Node<KeyT, ValueT>::SetPair(MyPair<KeyT, ValueT> pair)
{
	mPair = pair;
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

	void DeleteNode(Node<KeyT, ValueT>* node, Node<KeyT, ValueT>* successor);
	Node<KeyT, ValueT>* GetInOrederSuccessor(Node<KeyT, ValueT>& cNode);

public:
	MyMap();
	~MyMap();

	bool Insert(const MyPair<KeyT, ValueT>& pair);

	class Iterator;
	MyMap<KeyT, ValueT>::Iterator begin();
	MyMap<KeyT, ValueT>::Iterator end();
	MyMap<KeyT, ValueT>::Iterator find(const KeyT& key);
	MyMap<KeyT, ValueT>::Iterator erase(const MyMap<KeyT, ValueT>::Iterator& iter);

	/*
		inner class Iterator
	*/
	class Iterator {
	private:
		MyMap<KeyT, ValueT>* mCMap;
		Node<KeyT, ValueT>* mCNode;

	public:
		Iterator();
		Iterator(MyMap<KeyT, ValueT>* map, Node<KeyT, ValueT>* node);
		~Iterator();

		MyMap<KeyT, ValueT>* GetMap() const;
		Node<KeyT, ValueT>*  GetNode() const;
		void SetMap(MyMap<KeyT, ValueT>* map);
		void SetNode(Node<KeyT, ValueT>* node);

		bool operator==(const MyMap<KeyT, ValueT>::Iterator& rhs) const;
		bool operator!=(const MyMap<KeyT, ValueT>::Iterator& rhs) const;
		const MyPair<KeyT, ValueT>* operator->() const;
		const MyPair<KeyT, ValueT>& operator*() const;
		MyMap<KeyT, ValueT>::Iterator& operator++();
	};
};

/*
	Iterator class func
*/
template<typename KeyT, typename ValueT>
inline MyMap<KeyT, ValueT>::Iterator::Iterator()
	: mCMap(nullptr)
	, mCNode(nullptr)
{
}

template<typename KeyT, typename ValueT>
inline MyMap<KeyT, ValueT>::Iterator::Iterator(MyMap<KeyT, ValueT>* map, Node<KeyT, ValueT>* node)
	: mCMap(map)
	, mCNode(node)
{
}

template<typename KeyT, typename ValueT>
inline MyMap<KeyT, ValueT>::Iterator::~Iterator()
{
}

template<typename KeyT, typename ValueT>
inline MyMap<KeyT, ValueT>* MyMap<KeyT, ValueT>::Iterator::GetMap() const
{
	return mCMap;
}

template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>* MyMap<KeyT, ValueT>::Iterator::GetNode() const
{
	return mCNode;
}

template<typename KeyT, typename ValueT>
inline void MyMap<KeyT, ValueT>::Iterator::SetMap(MyMap<KeyT, ValueT>* map)
{
	mCMap = map;
}

template<typename KeyT, typename ValueT>
inline void MyMap<KeyT, ValueT>::Iterator::SetNode(Node<KeyT, ValueT>* node)
{
	mCNode = node;
}

template<typename KeyT, typename ValueT>
inline bool MyMap<KeyT, ValueT>::Iterator::operator==(const MyMap<KeyT, ValueT>::Iterator& rhs) const
{
	assert(nullptr != mCMap);

	if (nullptr == mCNode)
	{
		if (nullptr == rhs.mCNode)
		{
			return true;
		}
		return false;
	}

	if (mCMap->mRootNode == rhs.mCMap->mRootNode
		&& nullptr != rhs.mCNode
		&& mCNode->GetPair().GetKey() == rhs.mCNode->GetPair().GetKey())
	{
		return true;
	}
	return false;
}

template<typename KeyT, typename ValueT>
inline bool MyMap<KeyT, ValueT>::Iterator::operator!=(const MyMap<KeyT, ValueT>::Iterator& rhs) const
{
	assert(nullptr != mCMap);

	if (nullptr == mCNode)
	{
		if (nullptr == rhs.mCNode)
		{
			return false;
		}
		return true;
	}

	if (mCMap->mRootNode != rhs.mCMap->mRootNode
		|| nullptr == rhs.mCNode
		|| mCNode->GetPair()->GetKey() != rhs.mCNode->GetPair()->GetKey())
	{
		return true;
	}
	return false;
}

template<typename KeyT, typename ValueT>
inline const MyPair<KeyT, ValueT>* MyMap<KeyT, ValueT>::Iterator::operator->() const
{
	assert(nullptr != mCNode);

	return mCNode->GetPair();
}

template<typename KeyT, typename ValueT>
inline const MyPair<KeyT, ValueT>& MyMap<KeyT, ValueT>::Iterator::operator*() const
{
	assert(nullptr != mCNode);

	return *(mCNode->GetPair());
}

template<typename KeyT, typename ValueT>
inline typename MyMap<KeyT, ValueT>::Iterator& MyMap<KeyT, ValueT>::Iterator::operator++()
{
	/*
		�����ļ���: �ڽ��� ���� ���� - next
		����������: �ڽ��� ���� ���� - prev
	*/
	this->SetNode(this->mCMap->GetInOrederSuccessor(*(this->mCNode)));
	return *this;
}

/*
	MyMap class func
*/
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

			if (target->GetPair()->GetKey() < newNode->GetPair()->GetKey())
			{
				if (nullptr == target->GetRightChild())
				{
					target->SetRightChild(newNode);
					break;
				}
				target = target->GetRightChild();
			}
			else if (target->GetPair()->GetKey() > newNode->GetPair()->GetKey())
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

/*
	�����ļ��ڸ� ��ȯ�ϴ� �Լ�
	�����ļ��ڶ� ������ȸ���� ����
	����� ��带 ���Ѵ�. ���� ������
	��带 ���Ѵ�.

	& �� �Ű������� ������ nullptr �� ���� �� ����.
	�ؼ� nullptr üũ�� ���� �ʾƵ� �ȴ�.
*/
template<typename KeyT, typename ValueT>
inline Node<KeyT, ValueT>* MyMap<KeyT, ValueT>::GetInOrederSuccessor(Node<KeyT, ValueT>& cNode)
{
	Node<KeyT, ValueT>* target = nullptr;

	if (nullptr != cNode.GetRightChild())
	{
		target = cNode.GetRightChild();

		while (nullptr != target && nullptr != target->GetLeftChild())
		{
			target = target->GetLeftChild();
		}
	}
	else
	{
		target = cNode.GetParent();

		while (true)
		{
			if (nullptr == target)
			{
				break;
			}

			if (cNode.GetPair()->GetKey() < target->GetPair()->GetKey())
			{
				break;
			}
			target = target->GetParent();
		}
	}
	return target;
}

template<typename KeyT, typename ValueT>
inline typename MyMap<KeyT, ValueT>::Iterator MyMap<KeyT, ValueT>::begin()
{
	Node<KeyT, ValueT>* target = mRootNode;

	while (nullptr != target->GetLeftChild())
	{
		target = target->GetLeftChild();
	}
	return MyMap<KeyT, ValueT>::Iterator(this, target);
}

template<typename KeyT, typename ValueT>
inline typename MyMap<KeyT, ValueT>::Iterator MyMap<KeyT, ValueT>::end()
{
	return MyMap<KeyT, ValueT>::Iterator(this, nullptr);
}

template<typename KeyT, typename ValueT>
inline typename MyMap<KeyT, ValueT>::Iterator MyMap<KeyT, ValueT>::find(const KeyT& key)
{
	MyMap<KeyT, ValueT>::Iterator iter;
	iter.SetMap(this);
	iter.SetNode(nullptr);

	Node<KeyT, ValueT>* target = mRootNode;

	while (nullptr != target)
	{
		if (target->GetPair()->GetKey() == key)
		{
			iter.SetNode(target);
			break;
		}
		target->GetPair()->GetKey() < key ? target = target->GetRightChild() : target = target->GetLeftChild();
	}
	return iter;
}

template<typename KeyT, typename ValueT>
inline typename MyMap<KeyT, ValueT>::Iterator MyMap<KeyT, ValueT>::erase(const MyMap<KeyT, ValueT>::Iterator& iter)
{
	/* �� ���� ���
		1. ������带 ���� ��
		2. �ڽ��� �ϳ� �ִ� ��带 ���� ��
		3. �ڽ��� �� �� �ִ� ��带 ���� ��
	*/
	Node<KeyT, ValueT>* successor = GetInOrederSuccessor(*(iter.GetNode()));

	if (nullptr == iter.GetNode()->GetLeftChild() && nullptr == iter.GetNode()->GetRightChild())
	{
		DeleteNode(iter.GetNode(), nullptr);
	}
	else if (nullptr != iter.GetNode()->GetLeftChild() && nullptr != iter.GetNode()->GetRightChild())
	{
		Node<KeyT, ValueT>* targetNode = iter.GetNode();

		KeyT successorKey = successor->GetPair()->GetKey();
		ValueT successorValue = successor->GetPair()->GetValue();

		nullptr != successor->GetRightChild()
			? DeleteNode(successor, successor->GetRightChild())
			: DeleteNode(successor, nullptr);

		targetNode->SetPair(MyPair<KeyT, ValueT>(successorKey, successorValue));
		successor = targetNode;
	}
	else
	{
		nullptr != iter.GetNode()->GetLeftChild()
			? DeleteNode(iter.GetNode(), iter.GetNode()->GetLeftChild())
			: DeleteNode(iter.GetNode(), iter.GetNode()->GetRightChild());
	}
	--mCount;

	return MyMap<KeyT, ValueT>::Iterator(this, successor);
}

template<typename KeyT, typename ValueT>
inline void MyMap<KeyT, ValueT>::DeleteNode(Node<KeyT, ValueT>* node, Node<KeyT, ValueT>* successor)
{
	Node<KeyT, ValueT>* parent = node->GetParent();

	// �����Ͱ� ���� ��Ʈ����� ��
	if (nullptr == successor && nullptr == parent)
	{
		mRootNode = successor;
	}
	// �����Ͱ� �ִ� ��Ʈ����� ��
	else if (nullptr != successor && nullptr == parent)
	{
		successor->SetParent(nullptr);
		mRootNode = successor;
	}
	else
	{
		if (nullptr != successor)
		{
			successor->SetParent(parent);
		}

		if (node->GetPair()->GetKey() < parent->GetPair()->GetKey())
		{
			parent->SetLeftChild(successor);
		}
		else
		{
			parent->SetRightChild(successor);
		}
	}
	delete node;
}