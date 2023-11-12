#include <iostream>
#include <Windows.h>
#include "Helper.h"
#include "Map.h"
#include "Player.h"

bool TEST = true;
#include "1112.h"
using namespace std;


bool canMove = true;

void HandleMove()
{
	//한 번 누르면 한번만 움직임
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	if (!canMove)
	{
		return;
	}

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer(GPlayerX, GPlayerY + 1);
		break;
	default:
		break;

	}
}

int main()
{

	if (TEST)
	{
		test();
		return 1;
	}
	SetCursorOnOff(false);
	
	MovePlayer(3, 2);

	while (true)
	{
		//INPUT
		HandleKeyInput();

		//LOGIC
		HandleMove();

		//PRINT
		PrintMap2D();
	}
	return 0;
}