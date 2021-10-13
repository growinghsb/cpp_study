#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

namespace ex {
	// static member
	size_t String::totalString = 0;
	void String::ShowStringCount(void) {
		cout << totalString << endl;
	}

	//non-static member
	String::String(const char c, const size_t len)
		: mLen(len + 1)
	{
		mStr = new char[mLen];
		char* p = mStr;

		for (size_t i = 0; i < len; i++)
		{
			*p++ = c;
		}
		*p = '\0';

		totalString++;
	}

	String::String(const char* s) {
		mLen = strlen(s) + 1;
		mStr = new char[mLen];
		strncpy(mStr, s, mLen);

		totalString++;
	}

	String::String(const String& str)
		: mLen(str.mLen)
	{
		mStr = new char[mLen];
		strncpy(mStr, str.mStr, mLen);

		totalString++;
	}

	String::~String() {
		delete[] mStr;

		totalString--;
	}

	void String::AddString(const String& s) {
		size_t newLen = mLen + s.mLen - 1;
		char* p = new char[newLen];

		strncpy(p, mStr, newLen);
		delete[] mStr;
		mStr = p;

		for (size_t i = 0; i < s.mLen; i++)
		{
			*(p + (mLen - 1) + i) = s.mStr[i];
		}
		mLen = newLen;
	}

	void String::CopyString(const String& s) {
		char* p = new char[s.mLen];
		strncpy(p, s.mStr, s.mLen);

		delete[] mStr;
		mStr = p;
		mLen = s.mLen;
	}

	size_t String::StrLen(void) const {
		return mLen;
	}

	void String::ShowStr(void) const {
		cout << mStr << endl;
	}
}
