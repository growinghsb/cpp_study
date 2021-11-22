#include <iostream>
#include <ctime>

using std::cout;

static void Swap(int* v1, int* v2)
{
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

static void QuickSort(int* _pArray, int _iStart, int _iEnd, int _iWay)
{
	if (_iStart >= _iEnd)
		return;

	int iPivot = _iStart;
	int iLeft = _iStart + 1;
	int iRight = _iEnd;

	if (_iWay == 1)
	{
		while (iLeft <= iRight)
		{
			while (_pArray[iLeft] <= _pArray[iPivot] && iLeft < _iEnd) {
				++iLeft;
			}
			while (_pArray[iRight] >= _pArray[iPivot] && iRight > _iStart)--iRight;
			if (iLeft < iRight)
			{
				Swap(&_pArray[iLeft], &_pArray[iRight]);
			}
			else
			{
				Swap(&_pArray[iPivot], &_pArray[iRight]);
			}
		}
		QuickSort(_pArray, _iStart, iRight, _iWay);
		QuickSort(_pArray, iLeft, _iEnd, _iWay);
	}
}

void InsertSort(int* _pArr, int _iLen, int _iWay)
{
	//오름차순
	if (_iWay == 1)
	{
		for (int i = 1; i < _iLen; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (_pArr[i] < _pArr[j])
				{
					int iTemp = _pArr[i]; //원래 위치에 있던 값을 저장
					for (int w = i; w > j; w--)
					{
						_pArr[w] = _pArr[w - 1];
					}
					_pArr[j] = iTemp;
					break;
				}
			}
		}
	}
}

int mainTemp()
{
	srand((unsigned int)time(0));

	/*int tmp[100] = {};
	for (unsigned int i = 0; i < 100; ++i)
	{
		*(tmp + i) = rand() % 1000;
	}*/

	//QuickSort(tmp, 0, 4, 1);

	int tmp[] = { 1,2,1,4,5 };
	InsertSort(tmp, 5, 1);

	for (unsigned int i = 0; i < 5; ++i)
	{
		cout << *(tmp + i) << " ";
	}

	return 0;
}