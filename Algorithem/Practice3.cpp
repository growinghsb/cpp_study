#include <iostream>

using namespace std;

int main3(void) {
	int input;
	int sum = 1;
	cout << "���� �ϳ��� �Է� �ϼ���: ";
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