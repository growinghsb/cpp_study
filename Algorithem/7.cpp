/*
입력:
문자열을 입력 받는다. 
공백 포함 100 글자가 넘지 않도록 한다. 
알파벳 대, 소문자, 공백을 입력 받는다.

출력: 
입력 받은 문자열에서 공백을 제거하고 대문자를 소문자로 변경한다.
완성된 문자열을 출력한다.

예시:
입력 - B  e  A     uT   I    FU  L
출력 - beautiful
*/

#include <iostream>

using namespace std;

int main7(void) {
	size_t const LENGTH = 100;
	char input[LENGTH] = {};
	char* bp = input;
	char* cp = input;

	cin.getline(input, LENGTH - 1, '\n');

	while (*bp != '\0') {
		if (*cp == ' ') {
			cp++;
			continue;
		}

		*bp = *cp;
		*bp = *bp | 0x20; // 대문자를 소문자로 바꾸는 비트마스킹? 비트 연산?
		/*
			*bp = A = 65 = 0100 0001(64 + 1 = 65)
			0x20 = 32 = 0010 0000

			65 = 0100 0001
			32 = 0010 0000
			     0110 0001
			1 + 32 + 64 = 97 = 'a'				
		*/

		bp++;
		cp++;
	}
	cout << input;
	return 0;
}