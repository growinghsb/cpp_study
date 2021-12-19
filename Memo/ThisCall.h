#pragma once

#include<iostream>

using std::cout;
using std::endl;

class Test
{
public:
	Test() 
		:mTestInt(1) 
	{}
	
	void PublicFunc1() 
	{
		cout << this << endl;
	}
	
	void PublicFunc2() 
	{
		cout << this << mTestInt << endl;
	}

	virtual void VirtualFunc() 
	{
		cout << this << mTestInt << endl;
	}

	//static void StaticFunc() 
	//{
	//	cout << this << mTestInt << endl;
	//}

private:
	int mTestInt;
};