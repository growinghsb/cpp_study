#pragma once

#include<iostream>
#include "Date.h"

using namespace std;

namespace exam {
	Date::Date(const size_t year, const size_t month, const size_t day)
		: mYear(year), mMonth(month), mDay(day)
	{

	}

	void Date::AddYear(const size_t value) {
		mYear += value;
	}

	void Date::AddMonth(const size_t value) {

		if (mMonth + value > 12)
		{
			AddYear(1);
			mMonth = (mMonth + value) - 12;
			return;
		}
		mMonth += value;
	}



	void Date::AddDay(const size_t value) {
		if (IsFlatMoon())
		{
			if (mDay + value > 30)
			{
				AddMonth(1);
				mDay = (mDay + value) - 30;
				return;
			}
			mDay += value;
			return;
		}

		if (mDay + value > 31)
		{
			AddMonth(1);
			mDay = (mDay + value) - 31;
			return;
		}
		mDay += value;
	}

	void Date::ShowDate() const {
		cout << mYear << "³â " << mMonth << "¿ù " << mDay << "ÀÏ" << endl;
	}	

	bool Date::IsFlatMoon() const {
		size_t len = sizeof(mFlatMoon) / sizeof(int*);

		for (size_t i = 0; i < len; i++)
		{
			if (mMonth == mFlatMoon[i])
			{
				return true;
			}
		}
		return false;
	}
}