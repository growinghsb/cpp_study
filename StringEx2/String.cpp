#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

namespace exam {
	String::String(const char str)
		: mLen(1)
	{
		mStr = new char[mLen + 1];
		mStr[0] = str;
		mStr[1] = '\0';
	}

	String::String(const char* str) {
		mLen = InputStrGetLen(str);
		mStr = new char[mLen + 1];
		strncpy(mStr, str, mLen + 1);
	}

	String::String(const String& str) 
		: mLen(str.mLen)
	{
		mStr = new char[mLen + 1];
		char* tmp = mStr;
		char* p = str.mStr;

		for (size_t i = 0; i < mLen; i++)
		{
			*tmp++ = *p++;
		}
		*tmp = '\0';
	}

	String::~String() {
		delete[] mStr;
	}

	void String::StrConcat(const char* str) {
		size_t inputStrLen = InputStrGetLen(str);
		size_t newLen = mLen + inputStrLen;

		char* tmp = new char[newLen + 1];
		strncpy(tmp, mStr, newLen + 1);

		delete[] mStr;
		mStr = tmp;

		for (size_t i = 0; i < inputStrLen; i++)
		{
			*(tmp + mLen + i) = *str++;
		}
		*(tmp + newLen) = '\0';
		mLen = newLen;
	}

	bool String::StrContains(const char* str) const {
		const char* p1 = mStr;
		const char* p2 = str;

		while (*p1 != '\0') {
			if (*p1 != *p2 && *p2 != '\0')
			{
				p1++;
				p2 = str;
				continue;
			}

			if (*p1 == ' ' && *p2 == ' ')
			{
				return true;
			}

			if (*p2 == '\0') {
				return true;
			}

			p1++;
			p2++;
		}
		return false;
	}

	bool String::operator==(const String& rhs) const {
		char* p1 = mStr;
		char* p2 = rhs.mStr;

		if (mLen != rhs.mLen)
		{
			return false;
		}

		while (*p1 != '\0') {
			if (*p1 != *p2)
			{
				return false;
			}
			p1++;
			p2++;
		}
		return true;
	}

	bool String::DictionaryOrder(const char* str) const {
		const char* p1 = mStr;
		const char* p2 = str;
		
		while (true) {
			size_t p1Val = *p1 | 0x20;
			size_t p2Val = *p2 | 0x20;
			if (p1Val != p2Val)
			{
				return p1Val > p2Val ? true : false;
			}
			p1++;
			p2++;
		}
	}

	size_t String::StrLen() const {
		return mLen;
	}

	void String::ShowStr() const {
		cout << mStr << endl;
	}

	size_t String::InputStrGetLen(const char* str) const {
		size_t count = 0;
		while (*str != '\0') {
			str++;
			count++;
		}
		return count;
	}
}