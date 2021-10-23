/*
	숫자를 하나 입력 받는다. 
	1 ~ 입력 받은 숫자 포함 사이에 있는 모든수들의 
	모든 약수를 구한다
	그리고 그 약수를 출력한다. 

	입력: 8
	출력: 1 2 2 3 2 4 2 4
*/

#include <iostream>
#include <cstring>

using namespace std;

int main09(void) {
	size_t num;
	cin >> num;

	int* p = new int[num];
	memset(p, 0, sizeof(int) * num);

	int* tmp;
	for (size_t i = 1; i < num + 1; i++)
	{
		tmp = p + i - 1;
		for (size_t j = i; j < num + 1; j += i)
		{
			*tmp += 1;
			tmp += i;
		}
	}

	for (size_t i = 0; i < num; i++)
	{
		cout << *(p + i) << ' ';
	}
	delete[] p;

	return 0;
}