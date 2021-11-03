#include <iostream>

#include "DinamicArr.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main(void) 
{
	ArrayList<int> arr;
	cout << arr.GetSize() << endl;
	cout << arr.GetCapacity() << endl;

	cout << endl;

	arr.PushBack(10);
	arr.PushBack(20);
	arr.PushBack(30);
	arr.PushBack(40);
	arr.PushBack(50);
	
	cout << arr.GetSize() << endl;
	cout << arr.GetCapacity() << endl;

	cout << endl;

	ArrayList<int> copyArr(arr);
	cout << arr.GetSize() << endl;
	cout << arr.GetCapacity() << endl;

	cout << endl;
	
	bool result = arr == copyArr;
	cout << boolalpha << result << endl;

	cout << endl;

	copyArr.PushBack(60);
	copyArr.PushBack(70);
	copyArr.PushBack(80);
	copyArr.PushBack(90);
	copyArr.PushBack(100);
	copyArr.PushBack(110);
	copyArr.PushBack(120);
	copyArr.PushBack(130);
	copyArr.PushBack(140);
	copyArr.PushBack(150);
	cout << copyArr.GetSize() << endl;
	cout << copyArr.GetCapacity() << endl;

	cout << endl;

	copyArr.PushBack(160);
	cout << copyArr.GetSize() << endl;
	cout << copyArr.GetCapacity() << endl;
	
	cout << endl;

	copyArr.PushBack(170);
	cout << copyArr.GetSize() << endl;
	cout << copyArr.GetCapacity() << endl;

	cout << endl;

	cout << "index 10: " << copyArr[10] << endl;
	cout << "index 11: " << copyArr[11] << endl;
	cout << "index 12: " << copyArr[12] << endl;
	cout << "index 13: " << copyArr[13] << endl;
	
	cout << endl;

	cout << "index 1: " << copyArr.Get(1) << endl;
	cout << "index 2: " << copyArr.Get(2) << endl;
	cout << "index 3: " << copyArr.Get(3) << endl;
	cout << "index 4: " << copyArr.Get(4) << endl;

	cout << endl;

	ArrayList<int> copyArr2(copyArr);
	result = copyArr == copyArr2;
	cout << "copyArr == copyArr2: " << boolalpha << result << endl;

	cout << endl;
	result = copyArr != copyArr2;
	cout << "copyArr != copyArr2: " << boolalpha << result << endl;

	return 0;
}