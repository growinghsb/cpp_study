#include <iostream>

using namespace std;

int main(void) {
	size_t const LENGTH = 50;
	char chArr[LENGTH] = {};
	char* p = chArr;

	cin >> chArr;

	size_t result = 0;
	while (*p != '\0') {

		if (*p >= 48 && *p <= 57) {
			result = result * 10 + (*p - 48);
		}
		p++;
	}

	size_t count = 0;
	for (size_t i = 1; i < result + 1; i++)
	{
		if (result % i == 0) {
			count++;
		}
	}

	cout << result << endl;
	cout << count;

	return 0;
}