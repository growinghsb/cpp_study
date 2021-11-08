#include <iostream>

using namespace std;

int main3(void) {
	int input;
	int sum = 1;
	cout << "정수 하나를 입력 하세요: ";
	cin >> input;

	cout << 1;
	for (int i = 2; i < input; ++i) {
		if (input % i == 0) {
			sum += i;
			cout << " + " << i;
			continue;
		}
	}
	cout << " = " << sum;
	return 0;
}