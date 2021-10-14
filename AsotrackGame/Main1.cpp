#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main1(void) {
	srand(static_cast<unsigned int>(time(NULL)));

	const size_t LOTTENUMBER = 45;
	size_t lotte[LOTTENUMBER] = {};

	for (size_t i = 0; i < LOTTENUMBER; i++)
	{
		lotte[i] = i + 1;
	}

	size_t idx1, idx2;

	for (size_t i = 0; i < 100; i++)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		size_t tmp = lotte[idx1];
		lotte[idx1] = lotte[idx2];
		lotte[idx2] = tmp;
	}

	for (size_t i = 0; i < 6; i++)
	{
		cout << i + 1 << "번: " << lotte[i] << "\t";
	}
	cout << "보너스: " << lotte[6];

	return 0;
}