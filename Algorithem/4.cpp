/*
	처음 입력은 총 몇 개의 입력을 받을 지 사이즈를 입력 받는다
	
	두 번째 입력 부터는 그 사이즈 만큼 나이를 입력 받는다

	예) 10
	    13 45 23 87 25 54 55 12 21 76

	그리고 이 중 가장 나이차이가 많이 나는 경우 몇 살의
	차이가 나는지 출력하는 프로그램을 작성하면 됩니다. 

	즉 가장 어린 나이는 12살이고, 가장 많은 나이는 87 이므로
	87 - 12 하면 75 라는 값이 출력 되면 됩니다.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main4(void) {
	size_t const LENGTH = 100;
	size_t arr[LENGTH] = {};
	size_t size;

	cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	size_t min = arr[0];
	size_t max = arr[0];

	for (size_t i = 1; i < size; i++) {
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