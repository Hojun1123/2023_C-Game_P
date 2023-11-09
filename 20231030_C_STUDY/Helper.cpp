#include "Helper.h"
#include <windows.h>

MoveDir GMoveDir;

void HandleKeyInput()
{
	//GetAsyncKeyState: �񵿱� ó��, ȣ��� �������� Ű�� �¸� �����Ͽ� return, 0x8000 : ������ �������� ���� ȣ������� ���� ����
	//https://learn.microsoft.com/ko-kr/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN
	if (::GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		GMoveDir = MD_LEFT;
	}
	else if(::GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		GMoveDir = MD_RIGHT;
	}
	else if (::GetAsyncKeyState(VK_UP) & 0x8000)
	{
		GMoveDir = MD_UP;
	}
	else if (::GetAsyncKeyState(VK_DOWN) & 0X8000)
	{
		GMoveDir = MD_DOWN;
	}
	else
	{
		GMoveDir = MD_NONE;
	}
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	// short Ÿ�� x, y
	COORD pos = { (SHORT)x, (SHORT)y };
	// ���� scope ����, (���� ���� ������)
	::SetConsoleCursorPosition(output, pos);
}

void SetCursorOnOff(bool visible)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = visible;
	::SetConsoleCursorInfo(output, &cursorInfo);
}