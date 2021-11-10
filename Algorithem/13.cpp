/*
	N 자리 자연수가 입력 되면 입력 된 자연수의 
	자릿수 중 가장 많이 사용된 자릿수를 출력하는 프로그램 작성
	많이 사용된 숫자가 여러개면 그 중 가장 큰 값을 출력한다.

	ex)		1230565625
	result) 5
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main13() 
{
	int arr[10] = {};
	char chArr[101] = {};

	cin >> chArr;

	char* p = chArr;
	while (*p != '\0')
	{
		++arr[*p - 48];
		++p;
	}

	int max = 0;
	for (int i = 1; i < 10; i++)
	{
		if (arr[max] <= arr[i]) 
		{
			max = i;
		}	
	}
	cout << max;

	return 0;
}
