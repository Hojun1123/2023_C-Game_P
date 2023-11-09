#include "Player.h"
#include "Map.h"

int GPlayerX = 2;
int GPlayerY = 2;

void MovePlayer(int x, int y)
{
	//���� üũ
	if (x < 0 || x >= MAP_SIZE)
	{
		return;
	}
	if (y < 0 || y >= MAP_SIZE)
	{
		return;
	}

	//�� üũ
	if (GMap2D[y][x] == 1)
	{
		return;
	}

	// ���� ��ġ ����
	GMap2D[GPlayerY][GPlayerX] = 0;

	// �� ��ġ �̵�
	GPlayerX = x;
	GPlayerY = y;
	GMap2D[y][x] = 2;


}
