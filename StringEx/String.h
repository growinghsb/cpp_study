#pragma once

namespace ex {
	class String {
		static size_t totalString;

		char* mStr;
		size_t mLen;

	public:
		String(const char c, const size_t len);
		String(const char* s);
		String(const String& str);
		~String();

		void AddString(const String& s);
		void CopyString(const String& s);
		size_t StrLen(void) const;
		void ShowStr(void) const;
		static void ShowStringCount(void);
	};
}