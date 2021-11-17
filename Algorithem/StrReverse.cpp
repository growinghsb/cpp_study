#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void GetLength(const char* chArr, unsigned int* outLength);
void Reverse(char* chArr, const unsigned int length);
void PrintStr(const char* chArr);

int main()
{
	const unsigned int ARR_LENGTH = 100;
	char chArr[ARR_LENGTH] = {};

	cin.getline(chArr, ARR_LENGTH);

	unsigned int strLen = 0;
	GetLength(chArr, &strLen);

	Reverse(chArr, strLen);
	PrintStr(chArr);

	return 0;
}

void GetLength(const char* chArr, unsigned int* outLength)
{
	unsigned int count = 0;

	for (unsigned int i = 0; *(chArr + i) != '\0'; ++i)
	{
		++count;
	}
	*outLength = count;
}

void Reverse(char* chArr, const unsigned int length)
{
	char* start = chArr;
	char* end = chArr + length - 1;

	while (start < end) {

		char tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
	}
}

void PrintStr(const char* chArr)
{
	for (unsigned int i = 0; *(chArr + i) != '\0'; ++i)
	{
		cout << *(chArr + i);
	}
}
