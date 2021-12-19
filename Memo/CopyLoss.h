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
		cout << "부모 생성자" << endl;
	}

	ParentA(const ParentA& other) 
	{
		cout << "부모 복사 생성자" << endl;
	}

	virtual void vFunc() 
	{
		cout << "부모 가상함수" << endl;
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
		cout << "자식 생성자" << endl;
	}

	ChildA(const ChildA& other)
	{
		cout << "자식 복사 생성자" << endl;
	}

	void vFunc() override
	{
		cout << "자식 가상함수" << endl;
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