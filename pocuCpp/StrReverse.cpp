#include <iostream>
#include <string>
using namespace std;

int main(void) {
	const size_t LENGTH = 256;
	char str[LENGTH];
	char tmp[LENGTH];

	cout << "input str reverse:";
	cin.getline(str, LENGTH);

	// 구현 2
	char* start = str;
	char* end = start + (strlen(start) - 1);

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		
		start++;
		end--;
	}
	cout << "reverse: " << str;

	// 구현 1
	/*char* p = str;
	const size_t len = strlen(p);

	for (size_t i = 0; i < len; i++)
	{
		tmp[i] = *(p + (len - 1) - i);
	}
	tmp[len] = '\0';

	cout << "reverse: " << tmp;*/

	return 0;
}