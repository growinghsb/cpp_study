/*
	N �ڸ� �ڿ����� �Է� �Ǹ� �Է� �� �ڿ����� 
	�ڸ��� �� ���� ���� ���� �ڸ����� ����ϴ� ���α׷� �ۼ�
	���� ���� ���ڰ� �������� �� �� ���� ū ���� ����Ѵ�.

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
