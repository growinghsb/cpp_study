#include <iostream>

using namespace std;

int main4(void) {
	size_t const LENGTH = 100;
	size_t size;
	size_t arr[LENGTH] = {};

	cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	size_t min = arr[0];
	size_t max = arr[0];

	for (size_t i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			continue;
		}

		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max - min << endl;
	return 0;
}