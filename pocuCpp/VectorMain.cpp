#include "Vector.h"

using namespace sample;
using namespace std;

int mainVec(void) {

	Vector vec1(10, 20);
	Vector vec2(vec1);


	if (vec1 == vec2)
	{
		std::cout << "���� Ÿ��? main";
	}

	return 0;
}