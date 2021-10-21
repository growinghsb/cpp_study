#include <iostream>

using namespace std;

int main(void) {
	size_t const LENGTH = 50;
	char chArr[LENGTH] = {};
	char* p = chArr;

	cin >> chArr;

	size_t index = 0;
	while (*p != '\0') {
		size_t tmp = *p - 48;

		if (tmp > 0 && tmp < 10) {
			chArr[index] = tmp + 48;
			index++;
		}

		if (tmp == 0 && index != 0) {
			chArr[index] = tmp + 48;
			index++;
		}

		p++;
	}


	size_t sum = 0;
	for (size_t i = 0; i < index; i++)
	{
		size_t digit = 1;

		for (size_t j = i; j < index - 1; j++) {
			digit *= 10;
		}

		sum += (chArr[i] - 48) * digit;
	}

	size_t count = 0;
	for (size_t i = 1; i < sum + 1; i++)
	{
		if (sum % i == 0) {
			count++;
		}
	}

	cout << sum << endl;
	cout << count;
	return 0;
}