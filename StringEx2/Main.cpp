#include <iostream>
#include "String.h"

using namespace std;
using namespace exam;

int main() {
	String str1("apple");
	String str2('a');

	cout << "str1 length: " << str1.StrLen() << endl;
	cout << "str2 length: " << str2.StrLen() << endl;

	str1.StrConcat(" banana");
	cout << "str1 length: " << str1.StrLen() << endl;
	str1.ShowStr();

	bool result = str1 == str2;
	cout << result << endl;

	String str3("apple banana");
	result = str1 == str3;
	cout << result << endl;

	cout << endl;

	String str4("Han seungbeom Good Programmer");
	bool b1 = str4.StrContains("Han"); // 1
	bool b2 = str4.StrContains("seung"); // 1
	bool b3 = str4.StrContains("Beom"); // 0
	bool b4 = str4.StrContains("good"); // 0
	bool b5 = str4.StrContains("Program"); // 1
	bool b6 = str4.StrContains("Good"); // 1

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b4 << endl;
	cout << b5 << endl;
	cout << b6 << endl;

	cout << endl;

	String str5("pitch");
	bool orderRe = str5.DictionaryOrder("peple");
	cout << orderRe << endl; // 0

	String str6(str5);
	cout << str6.StrLen() << endl;
	str6.ShowStr();
}