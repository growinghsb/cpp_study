#include <iostream>

using namespace std;

int main(void) {
	const size_t LENGTH = 30;
	char input[LENGTH] = {};
	char* p = input;

	cin.getline(input, LENGTH, '\n');

	int count = 0;

	while (*p != '\0') {
		*p == 40 ? count++ : count--;
		
		if (count < 0) {
			cout << "NO";
			goto finish;
		}

		p++;
	}

	if (count != 0) {
		cout << "NO";
		goto finish;
	}
		
	cout << "YES";

finish:
	return 0;
}