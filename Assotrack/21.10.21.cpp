#include <iostream>
using namespace std;

int main(void) {
	int sum = 1;
	int factorial = 4;

	for (size_t i = 0; i < factorial - 1; i++)
	{
		sum *= (i + 2);
	}
	cout << sum;
}