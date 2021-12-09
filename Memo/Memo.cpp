#include<iostream>

//template<typename T>
//void Add(T v1, T v2)
//{
//	T tmp = v1;
//	v1 = v2;
//	v2 = tmp;
//}

template<typename T>
void Add(T& v1, T& v2)
{
	T tmp = v1;
	v1 = v2;
	v2 = tmp;
}


//template<typename T>
//int Add(T&& v1, T&& v2)
//{
//	return v1 + v2;
//}

//void Add(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
int& Test()
{
	int a = 100;

	return a;
}

int Test222()
{
	return 0;
}

int main(void)
{
	int a = 10;
	int b = 20;
	int& c = a;
	int& d = b;


	Add(a, b);
	Add(c, d);
	
	//const int& aa = Test();

	//Test222();
	//Test222();
	//Test222();

	//std::cout << aa;

	return 0;
}