#include "Helper.h"
#include <windows.h>

MoveDir GMoveDir;

void HandleKeyInput()
{
	//GetAsyncKeyState: 비동기 처리, 호출된 시점에서 키상 태를 조사하여 return, 0x8000 : 이전에 누른적이 없고 호출시점에 눌린 상태
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
	// short 타입 x, y
	COORD pos = { (SHORT)x, (SHORT)y };
	// 전역 scope 접근, (범위 지정 연산자)
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