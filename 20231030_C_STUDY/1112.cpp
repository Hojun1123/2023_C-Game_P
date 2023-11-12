#include "1112.h"
#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

int StrLen(const char* str)
{
	int count = 0;
	while (str[count] != '\0')
	{
		count += 1;
	}
	return count;
}

char* StrCpy(char* dest, const char* src)
{
	/*
	char* ret = dest;
	while (*src != 0)
	{
		*dest++ = *src++;
	}
	return ret;
	*/

	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	//dest[i] = '\0';
	return dest;
}

void PrintByCopy(StatInfo player)
{

}
void PrintByPointer(StatInfo *player)
{

}
void PrintByRef(StatInfo &player)
{
	cout << "ref : " << player.attack << endl;
}

void refStudy()
{
	StatInfo player = { 100, 10, 1 };
	PrintByCopy(player);
	PrintByPointer(&player);
	PrintByRef(player);
}

int test()
{
	refStudy();

	const int BUF_SIZE = 100;

	char* ptr0;
	const char* ptr1;
	char const* ptr2;
	const char* const ptr3 = "HELLO";

	//const char* a = "hello";
	char str[] = "hello";
	cout << str << endl;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World123";

	int len = StrLen(a);
	cout << len << endl;
	cout << StrCpy(a, b) << " " << b << endl;


	return 0;
}