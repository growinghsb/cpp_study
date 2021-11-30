#include<iostream>

using std::cout;
using std::wcout;
using std::endl;

int  MyStrlen(const wchar_t* str);
void MyStrcpy(wchar_t* target, const wchar_t* source);
void MyStrConcat(wchar_t* target, const wchar_t* source);
int  MyStrcmp(const wchar_t* first, const wchar_t* second);

int main1129()
{
	setlocale(LC_ALL, "ko_KR.utf8");

	const wchar_t* strP = L"abcde�ѽ¹�";
	wchar_t strArr1[] = L"abcde�ѽ¹�";
	int countP = MyStrlen(strP);
	int countA = MyStrlen(strArr1);
	wcout << L"abcde�ѽ¹�: " << countP << L"��" << endl << endl;

	wchar_t strArr2[100] = L"abcde�ѽ¹�";
	MyStrConcat(strArr2, L"zxcv�ѽ¹�");
	wcout << L"abcde�ѽ¹� + zxcv�ѽ¹�: " << strArr2 << endl << endl;

	wchar_t strArr3[100] = {};
	wcout << L"copy ��: " << strArr3 << endl << endl;
	MyStrcpy(strArr3, L"asdf�ѽ¹���������");
	wcout << L"copy ��: " << strArr3 << endl << endl;

	const wchar_t* standard = L"asdf�ѽ¹�";

	const wchar_t* different = L"asdg�ѽ¹�";
	int result1 = MyStrcmp(standard, different);
	int result11 = wcscmp(standard, different);
	wcout << L"(�ҹ��� �ٸ�)Mystrcmp: " << result1 << " / wcscmp: " << result11 << endl << endl;

	const wchar_t* biggerAndSmaller = L"asdF�ѽ¹�";
	int result2 = MyStrcmp(standard, biggerAndSmaller);
	int result22 = wcscmp(standard, biggerAndSmaller);
	wcout << L"(�빮�� �ٸ�)Mystrcmp: " << result2 << " / wcscmp: " << result22 << endl << endl;

	const wchar_t* same = L"asdf�ѽ¹�";
	int result3 = MyStrcmp(standard, same);
	int result33 = wcscmp(standard, same);
	wcout << L"(����)Mystrcmp: " << result3 << " / wcscmp: " << result33 << endl << endl;

	const wchar_t* longStr = L"asdf�ѽ¹��ѽ¹�";
	int result4 = MyStrcmp(standard, longStr);
	int result44 = wcscmp(standard, longStr);
	wcout << L"(�� ��)Mystrcmp: " << result4 << " / wcscmp: " << result44 << endl << endl;

	const wchar_t* shortStr = L"asdf��";
	int result5 = MyStrcmp(standard, shortStr);
	int result55 = wcscmp(standard, shortStr);
	wcout << L"(�� ª��)Mystrcmp: " << result5 << " / wcscmp: " << result55 << endl << endl;

	return 0;
}

int MyStrlen(const wchar_t* str)
{
	int count = 0;

	while (*str++ != '\0')
	{
		++count;
	}

	return count;
}

void MyStrcpy(wchar_t* target, const wchar_t* source)
{
	while (*source != '\0')
	{
		*target++ = *source++;
	}
}

void MyStrConcat(wchar_t* target, const wchar_t* source)
{
	wchar_t* p = target + MyStrlen(target);

	while (*source != '\0')
	{
		*p++ = *source++;
	}
}

int MyStrcmp(const wchar_t* first, const wchar_t* second)
{
	/*
		* �� ���� *
		 ���ĺ� ����
		 ��ҹ���
		 ����
	*/

	while (*first != '\0' && *second != '\0')
	{
		if (*first > *second)
		{
			return 1;
		}
		
		if (*first < *second)
		{
			return -1;
		}

		++first;
		++second;
	}

	if (*first == *second)
	{
		return 0;
	}

	return *first > *second ? 1 : -1;
}
