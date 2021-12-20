#include<iostream>

using std::cout;
using std::endl;

class Parent
{
public:
	Parent()
		: mParentInt(1)
	{
		Add();
		//pureVirFunc();
	}

	virtual ~Parent() 
	{
		Add();
		//pureVirFunc();
	}

	virtual void Add()
	{
		cout << "부모" << endl;
	};

	virtual void pureVirFunc() = 0;

	int mParentInt;
};

class Child
	: public Parent
{
public:
	Child()
		: mChildInt(2)
	{
		Add();
		pureVirFunc();
	}

	~Child() 
	{
		Add();
		pureVirFunc();
	}
	
	void Add() override
	{
		cout << "자식" << endl;
	};

	void pureVirFunc() override
	{
		cout << "오버라이딩한 순수가상함수" << endl;
	}

	int mChildInt;
};