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
		cout << "�θ�" << endl;
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
		cout << "�ڽ�" << endl;
	};

	void pureVirFunc() override
	{
		cout << "�������̵��� ���������Լ�" << endl;
	}

	int mChildInt;
};