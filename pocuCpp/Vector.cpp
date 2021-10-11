#include "Vector.h"

namespace sample {

	Vector::Vector()
		: Vector(0, 0)
	{
	}

	Vector::Vector(int x, int y)
		: mX(x), mY(y) 
	{
	}
	
	int Vector::GetX() const 
	{
		return mX;
	}

	void Vector::SetX(int x) 
	{
		mX = x;
	}

	int Vector::GetY() const
	{
		return mY;
	}

	void Vector::SetY(int y)
	{
		mY = y;
	}

	bool Vector::operator==(const Vector& rhs) const
	{
		return (mX == rhs.mX && mY == rhs.mY);
	}
}
