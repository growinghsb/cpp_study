#pragma once
class CArr
{
public:
	CArr();
	CArr(const CArr& other);
	~CArr();

	CArr& operator=(const CArr& other);
	bool operator==(const CArr& other) const;
	int& operator[](const unsigned int index) const;

	void pushBack(const int data);
	void pushIndex(const int data, const unsigned int index);
	void resize(const unsigned int size);
	void remove(const unsigned int index);
	unsigned int getCount() const;
	unsigned int getSize() const;
	void print() const;

private:
	int* mArr;
	unsigned int mSize;
	unsigned int mCount;

	void dataCopy(int* target, const int* source, const unsigned int count);
};

