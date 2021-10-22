#include <iostream>

using namespace std;

int main9(void) {
	size_t num;

	cin >> num;

	for (size_t i = 1; i < num + 1; i++)
	{
		size_t count = 0;

		for (size_t j = 1; j < i + 1; j++)
		{
			if (i % j == 0) {
				count++;
			}
		}
		cout << count << ' ';
	}

	return 0;
}