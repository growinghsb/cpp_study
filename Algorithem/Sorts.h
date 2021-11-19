#pragma once

#include <iostream>

using std::cout;
using std::endl;

void ArraySetting(int* arr, const int length);

void BubbleSort(int* arr, const int length);
void SelectionSort(int* arr, const int length);
void InsertionSort(int* arr, const int length);

void QuickSortRecursive(int* arr, const int length);
void QuickDivide(int* arr, int start, int end);

void QuickSortLoop(int* arr, const int length);

void Swap(int* v1, int* v2);
void PrintArray(int* arr, const int length, const char* algorithemName);