#include <iostream>
#include "String.h"

using namespace ex;
using namespace std;

int main(void) {
	String str1('h', 10);
	String str2("Han SeungBeom");

	String::ShowStringCount();

	String str3("copy&past");
	String str4(str3);

	String::ShowStringCount();

	str1.ShowStr();
	cout << "str1 length: " << str1.StrLen() << endl;

	str2.ShowStr();
	cout << "str2 length: " << str2.StrLen() << endl;

	str4.ShowStr();
	cout << "str4 length: " << str4.StrLen() << endl;

	str2.AddString(str3);
	str2.ShowStr();
	cout << "str2 length: " << str2.StrLen() << endl;

	String cusStr1("Han ");
	String cusStr2("Seung ");

	String::ShowStringCount();

	String cusStr3("Beom ");

	cusStr1.AddString(cusStr2);
	cusStr1.ShowStr();
	
	cusStr2.AddString(cusStr3);
	cusStr2.ShowStr();

	cusStr1.CopyString(cusStr2);
	cusStr1.ShowStr();

	String::ShowStringCount();


}