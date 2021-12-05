class Test {
public:
	Test()
		: mPointerData(nullptr)
		, mPrimitiveData(5)
	{
		mPointerData = new int[5];
	}
	
	~Test() 
	{
		delete[] mPointerData;
	}

private:
	int* mPointerData;
	int mPrimitiveData;
};