#pragma once
class Super
{
public:
	Super(int i) : mData(i) {};

	int getData() const { return mData; }

private:
	int mData;
};

class Sub : public Super
{
public:
	Sub() : Super(10) 
	{
		mData = 3;
	};
	

private:
	int mData = 5;
};

