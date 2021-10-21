#include <iostream>

using namespace std;

int main7(void) {
	size_t const LENGTH = 100;
	char input[LENGTH] = {};
	char* bp = input;
	char* cp = input;

	cin.getline(input, LENGTH, '\n');

	while (*bp != '\0') {
		if (*cp == ' ') {
			cp++;
			continue;
		}

		*bp = *cp;
		*bp = *bp | 0x20;

		bp++;
		cp++;
	}
	cout << input;
	return 0;
}