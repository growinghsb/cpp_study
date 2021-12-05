#include<iostream>
#include <crtdbg.h>

#include"Sub.h"

using std::cout;
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Sub sub(10);
	Sub sub2("sub2");

	return 0;
}