#pragma once

#include<cassert>

template<typename T>
class MyVector
{
public:
    MyVector();
    ~MyVector();

    // const MyVector* const other
    MyVector(const MyVector<T>& other);

    void reserve(const unsigned int newCapacity);
    void resize(const int newCapacity);
    void pushBack(const T& data);
    T& operator[](const int index)const;
    void operator=(const MyVector<T>& rhs);
    bool operator==(const MyVector<T>& rhs);

    // 전방선언
    class iterator;

    iterator& erase(iterator& target);

    int getSize() const
    {
        return mSize;
    }

    int getCapacity() const
    {
        return mCapacity;
    }

    T& front() const
    {
        assert(0 < mSize);

        return *mData;
    }

    T& back() const
    {
        assert(0 < mSize);

        return *(mData + mSize - 1);
    }

    bool empty() const
    {
        if (0 == mSize)
        {
            return true;
        }
        return false;
    }

    void popBack()
    {
        assert(0 < mSize);

        --mSize;
    }


    iterator begin();
    iterator end();
    iterator rBegin();
    iterator rEnd();

    class iterator {
        friend class MyVector;
    public:
        iterator();
        iterator(MyVector<T>* arr, T* arrData, int size);
        ~iterator() = default;

        iterator& operator++()
        {
            assert(mArrSize == mArr->mSize);
            assert(mArr->mData + mArrSize + 1 != mArrData + 1);

            ++mArrData;

            return *this;
        }

        iterator& operator--()
        {
            assert(mArrSize == mArr->mSize);
            assert(mArr->mData - 1 != mArrData);

            --mArrData;

            return *this;
        }

        bool operator!=(const iterator& rhs)
        {
            assert(mArrSize == mArr->mSize && rhs.mArrSize == mArr->mSize);

            if (this->mArrData != rhs.mArrData)
            {
                return true;
            }
            return false;
        }

        bool operator==(const iterator& rhs)
        {
            return !(operator!=(rhs));
        }

        int& operator*()
        {
            assert(mArr->mData + mArrSize + 1 != mArrData + 1 && mArr->mData - 1 != mArrData);

            return *mArrData;
        }

    private:
        MyVector<T>* mArr;
        T* mArrData;
        int mArrSize;
    };

private:
    T* mData;
    int mCapacity;
    int mSize;

    void dataCopy(const MyVector<T>& other);
};

/*
   template code
*/
template<typename T>
MyVector<T>::MyVector()
    : mData(nullptr)
    , mCapacity(0)
    , mSize(0)
{
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete[] mData;
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
    : mData(nullptr)
    , mCapacity(other.mCapacity)
    , mSize(other.mSize)
{
    mData = new int[mCapacity];
    dataCopy(other);
}

template<typename T>
void MyVector<T>::reserve(unsigned int newCapacity)
{
    assert(newCapacity > mCapacity);

    mCapacity = newCapacity;
    T* pTmp = new T[mCapacity];

    if (nullptr != mData)
    {
        for (unsigned int i = 0; i < mSize; ++i)
        {
            *(pTmp + i) = *(mData + i);
        }
        delete[] mData;
    }
    mData = pTmp;
}

template<typename T>
void MyVector<T>::resize(const int newCapacity)
{
    assert(newCapacity > mCapacity);

    mCapacity = newCapacity;
    T* pTmp = new T[mCapacity];

    if (nullptr != mData)
    {
        for (int i = 0; i < mSize; ++i)
        {
            *(pTmp + i) = *(mData + i);
        }
        delete[] mData;
    }

    mData = pTmp;
    mSize = mCapacity;
}

template<typename T>
void MyVector<T>::pushBack(const T& data)
{
    if (mSize == mCapacity)
    {
        mCapacity == 0 ? reserve(1) : reserve(mCapacity * 2);
    }

    *(mData + mSize) = data;
    ++mSize;
}

template<typename T>
T& MyVector<T>::operator[](const int index) const
{
    assert(index < mSize);

    return *(mData + index);
}

template<typename T>
void MyVector<T>::operator=(const MyVector<T>& rhs)
{
    mSize = rhs.mSize;
    mCapacity = rhs.mCapacity;

    delete[] mData;
    mData = new T[mCapacity];

    dataCopy(rhs);
}

template<typename T>
bool MyVector<T>::operator==(const MyVector<T>& rhs)
{
    if (mSize != rhs.mSize || mCapacity != rhs.mCapacity)
    {
        return false;
    }

    for (unsigned int i = 0; i < mSize; ++i)
    {
        if (*(mData + i) != *(rhs.mData + i))
        {
            return false;
        }
    }

    return true;
}

template<typename T>
typename MyVector<T>::iterator& MyVector<T>::erase(iterator& target)
{
    int offset = target.mArrData - mData;

    for (int i = offset; i < target.mArrSize - 1; ++i)
    {
        *(mData + i) = *(mData + i + 1);
    }

    --mSize;
    --target.mArrSize;

    return target;
}

template<typename T>
typename MyVector<T>::iterator MyVector<T>::begin()
{
    return iterator(this, mData, mSize);
}

template<typename T>
typename MyVector<T>::iterator MyVector<T>::end()
{
    return iterator(this, mData + mSize, mSize);
}

template<typename T>
typename MyVector<T>::iterator MyVector<T>::rBegin()
{
    return iterator(this, mData + mSize - 1, mSize);
}

template<typename T>
typename MyVector<T>::iterator MyVector<T>::rEnd()
{
    return iterator(this, mData - 1, mSize);
}

template<typename T>
void MyVector<T>::dataCopy(const MyVector<T>& other)
{
    for (unsigned int i = 0; i < mSize; ++i)
    {
        *(mData + i) = *(other.mData + i);
    }
}

/*
   iterator func
*/
template<typename T>
MyVector<T>::iterator::iterator()
    : mArr(nullptr)
    , mArrData(nullptr)
    , mArrSize(0)
{
}

template<typename T>
MyVector<T>::iterator::iterator(MyVector<T>* arr, T* arrData, int size)
    : mArr(arr)
    , mArrData(arrData)
    , mArrSize(size)
{
}