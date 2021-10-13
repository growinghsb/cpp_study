#pragma once

namespace exam {
	class String {
		char* mStr;
		size_t mLen;

		size_t InputStrGetLen(const char* str) const;

	public :
		String(const char str);
		String(const char* str);
		String(const String& str);
		~String();

		size_t StrLen() const;
		void StrConcat(const char* str);
		bool StrContains(const char* str) const;
		bool operator==(const String& rhs) const;
		bool DictionaryOrder(const char* str) const;
		void ShowStr() const;
	};
}