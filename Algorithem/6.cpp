/*
	문자와 숫자가 섞여 있는 문자열을 입력 받습니다. 
	
	그 중 숫자만 추출 해서 숫자만 나열 합니다. 

	이 때 첫 자리가 0이라면 이 0은 제외한 후 나열합니다. 

	출력할 땐 나열한 숫자를 첫 번째 줄에 출력하고
	이렇게 출력된 숫자의 약수를 두 번째 줄에 출력합니다. 

	입력) effsnfo0dfoif1lkfjinc2odcnso 
	출력) 12
		  6
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main6(void) {
	unsigned int const LENGTH = 50;
	char chArr[LENGTH + 1] = {0, };
	char* p = chArr;

	cin >> chArr;

	unsigned int result = 0;
	while (*p != '\0') {

		if (*p >= 48 && *p <= 57) { // 57 - 48 + 1 = 10 / 0 ~ 9
			result = result * 10 + (*p - 48);
		}
		p++;
	}

	unsigned int count = 0;
	for (unsigned int i = 1; i < result + 1; i++)
	{
		if (result % i == 0) {
			count++;
		}
	}

	cout << result << endl;
	cout << count;

	return 0;
}