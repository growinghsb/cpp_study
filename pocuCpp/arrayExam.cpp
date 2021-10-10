#include <iostream>

using namespace std;

void arrInMax();
static void add(int, size_t);
static void printArr();
static bool search(int);

static const size_t LENGTH = 128;
static int arr[LENGTH] = { 4,3,18,1,5,9,10,3,15,3, INT32_MAX, };
static size_t pointer;

int mainArr(void) {
	//arrInMax();
	add(100, 5);
	printArr();

	cout << endl;

	cout << search(1) << endl; // true
	cout << search(77) << endl; // false
	cout << search(18) << endl; // true
	cout << search(9) << endl; // true
	cout << search(50) << endl; // false
	return 0;
}

void add(int num, size_t index) {
	int* p = arr;
	for (size_t i = 0; i < LENGTH; i++)
	{
		if (*p == INT32_MAX) {
			pointer = i;
			break;
		}
		p++;
	}

	if (index > pointer) {
		cout << index << ": 유효하지 않은 index" << endl;
		return;
	}

	size_t count = pointer - index;
	for (size_t i = 0; i < count + 1; i++)
	{
		arr[pointer + 1 - i] = arr[pointer - i];
	}
	arr[index] = num;
	pointer++;
}

bool search(int num) {
	for (size_t i = 0; i < LENGTH; i++)
	{
		if (arr[i] == INT32_MAX) {
			return false;
		}
		
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
}

void printArr() {
	for (size_t i = 0; i < pointer; i++)
	{
		cout << arr[i] << " ";
	}
}

void arrInMax() {

	size_t len = sizeof(arr) / sizeof(int);

	int max = arr[0];

	for (size_t i = 1; i < len; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	cout << max;
}