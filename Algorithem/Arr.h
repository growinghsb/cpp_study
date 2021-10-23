#pragma once

typedef struct Arr {
	unsigned int iSize;
	unsigned int iCount;
	int* pInt;
}arr_t;

void InitArr(arr_t* arr, const unsigned int initSize); // 초기값 설정
void Clear(arr_t* arr); // 객체 삭제
void AddBack(arr_t* arr, const int value); // 맨 뒤에 값 추가
void AddIndex(arr_t* arr, const int value, const unsigned int index);
//void ScaleUp(arr_t* arr); // 데이터 복사 및 메모리 재할당
void RemoveIndex(arr_t* arr, const unsigned int index); // 전달 받은 인덱스번호의 값을 지운다.
void Sort(const arr_t* arr, const bool asc);
// void Asc(const arr_t arr);
// void Desc(const arr_t arr);
// void Swap(const arr_t* arr, const unsigned int j);
void print(const arr_t* arr); // 배열 값 전체 출력

