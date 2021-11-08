#include <iostream>

using namespace std;

int main1(void) {
	size_t n, m, sum = 0;
	cin >> n >> m;

	for (size_t i = 1; i < n + 1; i++)
	{
		if (i % m == 0) {
			sum += i;
			continue;
		}
	}
	cout << sum;
	return 0;
}