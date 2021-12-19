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
	}

	virtual void Add()
	{
		cout << "부모" << endl;
	};

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
	}

	void Add() override
	{
		cout << "자식" << endl;
	};

	int mChildInt;
};