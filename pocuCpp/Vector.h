#pragma once

#include <iostream>

namespace sample {
	class Vector
	{
	public:
		Vector();
		Vector(int x, int y);

		int GetX() const;
		void SetX(int x);

		int GetY() const;
		void SetY(int y);

		bool operator==(const Vector& rhs) const;

		Vector operator*(const Vector& rhs) const;
		Vector operator*(int muliplier) const;
		friend Vector operator*(int muliplier, const Vector& v);

		Vector operator*=(const Vector& rhs);
		Vector operator*=(int multiplier);

		friend std::ostream operator<<(std::ostream& os, const Vector& vector);

	private:
		int mX;
		int mY;
	};
}