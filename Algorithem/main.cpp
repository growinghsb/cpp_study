#include <iostream>
#include <ctime>

#include "Arr.h"

using namespace std;

int main(void) {
	srand(static_cast<int>(time(0)));

	arr_t arr;
	InitArr(&arr, 10);
	cout << "초기화 직후 사이즈" << endl;
	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	for (unsigned int i = 0; i < 15; i++) {
		AddBack(&arr, rand() % 1000);
	}

	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	print(&arr);
	
	RemoveIndex(&arr, 10);
	cout << "삭제 후" << endl;

	print(&arr);
	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	cout << "추가 후" << endl;
	AddIndex(&arr, 1111, 5);
	AddIndex(&arr, 1111, 6);

	print(&arr);
	cout << "iCount: " << arr.iCount << endl;
	cout << "iSize : " << arr.iSize << endl;

	cout << "오름차순 정렬" << endl;
	Sort(&arr, true);
	print(&arr);

	cout << "내림차순 정렬" << endl;
	Sort(&arr, false);
	print(&arr);

	Clear(&arr);

	return 0;
}
