#pragma once

typedef struct Arr {
	unsigned int iSize;
	unsigned int iCount;
	int* pInt;
}arr_t;

void InitArr(arr_t* arr, const unsigned int initSize); // �ʱⰪ ����
void Clear(arr_t* arr); // ��ü ����
void AddBack(arr_t* arr, const int value); // �� �ڿ� �� �߰�
void AddIndex(arr_t* arr, const int value, const unsigned int index);
//void ScaleUp(arr_t* arr); // ������ ���� �� �޸� ���Ҵ�
void RemoveIndex(arr_t* arr, const unsigned int index); // ���� ���� �ε�����ȣ�� ���� �����.
void Sort(const arr_t* arr, const bool asc);
// void Asc(const arr_t arr);
// void Desc(const arr_t arr);
// void Swap(const arr_t* arr, const unsigned int j);
void print(const arr_t* arr); // �迭 �� ��ü ���

