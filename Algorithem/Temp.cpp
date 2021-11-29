#include <iostream>
#include <ctime>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

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
	int num;
	cin >> num;

	for (int i = 2; i <= num; i++)
	{
		if (num == 1)
		{
			break;
		}
		
		if (num % i == 0)
		{
			cout << i << " ";
			num /= i;
			i--;
		}
	}
	return 0;
}