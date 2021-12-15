#include <iostream>

using std::cout;
using std::endl;

class Test 
{
public:
	Test(int a) 
		: mA(a)
	{
	}

	void operator=(const Test& rhs) 
	{
		cout << "나 대입연산자" << endl;
		mA = rhs.mA;
	}

private:
	int mA;
};

int main()
{
	Test test1(10);
	Test test2 = test1;

	test1 = test2;
	test1.operator=(test2);

	return 0;
}