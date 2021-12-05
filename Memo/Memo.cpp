#include<iostream>
#include <crtdbg.h>

#include"delete.h"

using std::cout;
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Test* testArr = new Test[10];

 	delete[] testArr;

	return 0;
}