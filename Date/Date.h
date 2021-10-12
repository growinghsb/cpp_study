#pragma once

namespace exam {
	class Date {
		int mYear;
		int mMonth;
		int mDay;

		int mIntercalations[7] = { 1, 3, 5, 7, 8, 10, 12 }; // 31¿œ
		int mFlatMoon[5] = {2, 4, 6, 9, 11}; // 30¿œ
		
		bool IsFlatMoon() const;

	public :
		Date(const size_t year, const size_t month, const size_t day);
		void AddYear(const size_t value);
		void AddMonth(const size_t value);
		void AddDay(const size_t value);
		void ShowDate() const;
	};
}