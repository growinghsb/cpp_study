#include<iostream>
#include <crtdbg.h>

using std::cout;
using std::endl;

class A
{
public:
	A()
	{
		m_pData = new int[5]{};
	}

	A(const A& other)
	{
		m_pData = new int[5]{};
		for (int i = 0; i < 5; ++i)
		{
			m_pData[i] = other.m_pData[i];
		}
	}

	void SetDataA()
	{
		for (int i = 0; i < 5; ++i)
		{
			m_pData[i] = i + 10;
		}
	}

	void PrintDataA()
	{
		std::cout << "A" << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			std::cout << m_pData[i] << std::endl;
		}
	}

	~A()
	{
		delete[] m_pData;
	}

protected:
	int* m_pData;
};

class B : public A
{
public:
	B()
		: m_data{ 5.f }
	{
	}

protected:
	float m_data;
};

class C : public B
{
public:
	C()
	{
		m_pDouble = new double[10]{};
	}

	//멤버 초기화 리스트를 제거 해보고 디버그 해보세요
	C(const C& other)
	{
		m_pDouble = new double[10]{};

		for (int i = 0; i < 10; ++i)
		{
			m_pDouble[i] = other.m_pDouble[i];
		}
	}

	~C()
	{
		delete[] m_pDouble;
	}

	void PrintDataC()
	{
		std::cout << std::endl;
		std::cout << "C" << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			std::cout << m_pData[i] << std::endl;
		}
	}

private:
	double* m_pDouble;
};

int mainCopyConstructor()
{
	C c{};
	c.SetDataA();

	C copy_c{ c };
	copy_c.PrintDataA();

	return 0;
}