#include <iostream>

#include "Arr.h"

using namespace std;

void ScaleUp(arr_t* arr);

void InitArr(arr_t* arr, const unsigned int initSize) {
	arr->iSize = initSize;
	arr->iCount = 0;
	arr->pInt = (int*)malloc(sizeof(int) * initSize);
}

void Clear(arr_t* arr) {
	arr->iSize = 0;
	arr->iCount = 0;
	free(arr->pInt);
}

void AddBack(arr_t* arr, const int value) {
	if (arr->iSize == arr->iCount) {
		ScaleUp(arr);
	}

	*(arr->pInt + arr->iCount) = value;
	arr->iCount++;
}

void AddIndex(arr_t* arr, const int value, const unsigned int index)
{
	if (index >= arr->iCount) {
		cout << "잘못된 위치 입니다." << endl;
		return;
	}

	if (arr->iSize == arr->iCount) {
		ScaleUp(arr);
	}

	*(arr->pInt + arr->iCount) = *(arr->pInt + index - 1);
	*(arr->pInt + index - 1) = value;
	arr->iCount++;
}

void RemoveIndex(arr_t* arr, const unsigned int index)
{
	if (index >= arr->iCount) {
		cout << "잘못된 위치 입니다." << endl;
		return;
	}

	arr->iCount--;
	*(arr->pInt + index - 1) = *(arr->pInt + arr->iCount);
}

void Sort(const int* arr, unsigned int count, void(*pOrder)(const int* pData, const unsigned int count))
{
	pOrder(arr, count);
}






void print(const arr_t* arr)
{
	for (unsigned int i = 0; i < arr->iCount; i++)
	{
		cout << *(arr->pInt + i) << endl;
	}
}

void ScaleUp(arr_t* arr)
{
	arr->iSize *= 2;

	int* p = (int*)malloc(sizeof(int) * arr->iSize);
	int* tmp = p;

	for (unsigned int i = 0; i < arr->iCount; i++)
	{
		*tmp = *(arr->pInt + i);
		tmp++;
	}

	free(arr->pInt);
	arr->pInt = p;

	cout << "scale up complite" << endl;
}
