#include <iostream>

void GetMinMax(unsigned int length, int* arr, int* min, int* max);

int main()
{
	int minMaxArr[] = { 10, 3, 47, 5, 8, 2, 32, 16, 9 };

	int min = 0;
	int max = 0;

	GetMinMax(sizeof(minMaxArr) / sizeof(int), minMaxArr, &min, &max);

	std::cout << min << ", " << max << std::endl;

	return 0;
}

void GetMinMax(unsigned int length, int* arr, int* minOut, int* maxOut)
{
	int min = 0;
	int max = 0;

	min = *(arr + 0);
	max = *(arr + 0);

	for (unsigned int i = 1; i < length; i++)
	{
		if (*(arr + i) < min)
		{
			min = *(arr + i);
			continue;
		}

		if (*(arr + i) > max)
		{
			max = *(arr + i);
		}
	}
	*minOut = min;
	*maxOut = max;
}
