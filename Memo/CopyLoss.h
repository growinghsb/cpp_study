#pragma once

#include<iostream>

using std::cout;
using std::endl;

class ParentA 
{
public:
	ParentA() 
		: mParentInt(1)
	{
		cout << "�θ� ������" << endl;
	}

	ParentA(const ParentA& other) 
	{
		cout << "�θ� ���� ������" << endl;
	}

	virtual void vFunc() 
	{
		cout << "�θ� �����Լ�" << endl;
	}

	int mParentInt;

private:
};

class ChildA
	: public ParentA
{
public:
	ChildA()
		: mChildInt(2)
	{
		cout << "�ڽ� ������" << endl;
	}

	ChildA(const ChildA& other)
	{
		cout << "�ڽ� ���� ������" << endl;
	}

	void vFunc() override
	{
		cout << "�ڽ� �����Լ�" << endl;
	}

	int mChildInt;

private:
};

void Func(ParentA args)
{
	args.vFunc();
}


void TestMain() 
{
	ChildA cA;

	Func(cA);
}