/*
괄호들을 입력 받는다. 
입력 받은 괄호가 올바른 괄호쌍을 이루는지
아니면 잘못된 괄호 쌍을 이루는지를 파악해
YES or NO 를 출력하는 프로그램이다. 

()()()(()) = YES
(())))(( = NO
()()(())( = NO 
*/

#include <iostream>

using namespace std;

int main8(void) {
	const size_t LENGTH = 30;
	char input[LENGTH] = {};
	char* p = input;

	cin.getline(input, LENGTH, '\n');

	int count = 0;

	while (*p != '\0') {
		*p == 40 ? count++ : count--;
		
		if (count < 0) {
			cout << "NO";
			goto finish;
		}

		p++;
	}

	if (count != 0) {
		cout << "NO";
		goto finish;
	}
		
	cout << "YES";

finish:
	return 0;
}