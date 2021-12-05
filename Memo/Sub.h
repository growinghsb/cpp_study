#include<string>

using std::string;

class Super 
{
public :
	Super() {}

	Super(const string& str)
		: mStr(str)
	{
	
	}

private:
	string mStr;
};

class Sub : public Super
{
public:
	using Super::Super;

	Sub(int data)
		: mData(data)
	{
	
	}

private:
	int mData;
};

