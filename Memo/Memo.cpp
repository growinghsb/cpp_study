#include "ConstructorInVertualFunc.h"
#include "ThisCall.h"
#include "CopyLoss.h"

int main() 
{
	Child child;
	Parent* parent = &child;
	parent->Add();

	//Test::StaticFunc();
	
	//Test* t = nullptr;
	//int tClassSize = sizeof(Test);
	//t->PublicFunc1();
	//t->PublicFunc2();
	//t->VirtualFunc();
	//t->StaticFunc();

	//TestMain();

	return 0;
}