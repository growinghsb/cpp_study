#include <iostream>
#include "strFunc.h"

using namespace std;

int main(void) {
	bool flag = true;

	while (flag) {
		choice();

		switch (inputChoice())
		{
		case 1:
			changeUpperandLower();
			break;
		case 2:
			strCompare();
			break;
		case 3:
			strCounting();
			break;
		case 4:
			strReverse();
			break;
		default:
			flag = false;
			break;
		}
	}

	return 0;
}
