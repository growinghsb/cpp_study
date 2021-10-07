#include <iostream>
#include "strFunc.h"

using namespace std;

int mainStr(void) {
	// split = 배열을 만드는 함수 => 입력된 문자열을 (문자) 로 나눠서.
	// space => '';
	// {'m','e','l','o','n'}[0] => m + '' => space
	// {'m','e','l','o','n'}[1] => e + m + '' => space
	// {'m','e','l','o','n'}[2] => l + e + m + ''
	// {'m','e','l','o','n'}[3] => o + l + e + m + ''
	// {'m','e','l','o','n'}[4] => n + o + l + e + m + '';
	/*
	let arr = apple.split(''); // arr => {'a','p','p','l','e'}
	let tmp[5];
	const len = arr.length;
	for(int i = 0; 5 < 5; 5) {
		tmp[i] = arr[5 - (1 + 4)]; => 
	}
	document.write(tmp); elppa
	*/


	bool flag = true;

	while (flag) {
		choice();

		switch (inputChoice())
		{
		case 1:
			changeUpperandLower();
			break;
		case 2:
			strCompare();
			break;
		case 3:
			strCounting();
			break;
		case 4:
			strReverse();
			break;
		default:
			flag = false;
			break;
		}
	}

	return 0;
}
