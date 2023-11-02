#include <iostream>
using namespace std;

enum PlayerType
{
	PT_None,
	PT_Knight,
	PT_Archer,
	PT_Mage,
};

enum MonsterType
{
	MT_None,
	MT_Slime,
	MT_Orc,
	MT_Skeleton,
};

PlayerType playerType;
MonsterType monsterType;


struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

StatInfo playerStat;
StatInfo monsterStat;

void EnterLobby();
void EnterField();
void SelectPlayer();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();

/*
int main()
{
	srand(time(0));
	EnterLobby();

	return 0;
}
*/
void EnterLobby()
{

	while (true)
	{
		cout << "-------------------" << endl;
		cout << "���� �κ��Դϴ�..!" << endl;
		cout << "-------------------" << endl;

		SelectPlayer();

		cout << "-------------------" << endl;
		cout << "(1) �ʵ� ���� (2) ���� ����" << endl;
		cout << "-------------------" << endl;

		int input;
		cin >> input;
		
		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}

	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "-------------------" << endl;
		cout << "������ �����ϼ���!" << endl;
		cout << "(1) ��� (2) �ü� (3) ����" << endl;

		int choice;
		cin >> choice;
		if (choice == PT_Knight)
		{
			cout << "��� ������ ..." << endl;
			playerStat.hp = 150;
			playerStat.attack = 10;
			playerStat.defence = 5;
			break;
		}
		else if (choice == PT_Archer)
		{
			cout << "�ü� ������ ..." << endl;
			playerStat.hp = 100;
			playerStat.attack = 15;
			playerStat.defence = 3;
			break;
		}
		else if (choice == PT_Mage)
		{
			cout << "���� ������ ..." << endl;
			playerStat.hp = 80;
			playerStat.attack = 25;
			playerStat.defence = 0;
			break;
		}
		else
		{

		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "-------------------" << endl;
		cout << "�ʵ忡 �����߽��ϴ�!" << endl;
		cout << "[Player] HP : " << playerStat.hp << " / ATT : " << playerStat.attack << " / DEF : " << playerStat.defence << endl;

		// ���� ����
		CreateRandomMonster();

		cout << "-------------------" << endl;
		cout << "(1) ���� (2) ����" << endl;
		cout << "> " << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (playerStat.hp == 0)
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	int randomChoice = 1 + (rand() % 3);

	switch (randomChoice)
	{
	case MT_Slime:
		cout << "������ ������...! (HP:30 / ATT:2 / DEF:0)" << endl;
		monsterStat.hp = 30;
		monsterStat.attack = 2;
		monsterStat.defence = 0;
		break;
	case MT_Orc:
		cout << "��ũ ������...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterStat.hp = 40;
		monsterStat.attack = 10;
		monsterStat.defence = 3;
		break;
	case MT_Skeleton:
		cout << "���̷��� ������...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterStat.hp = 80;
		monsterStat.attack = 15;
		monsterStat.defence = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		//����
		int damage = playerStat.attack - monsterStat.defence;
		if (damage < 0)
		{
			damage = 0;
		}

		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
		{
			monsterStat.hp = 0;
		}

		cout << "���� ���� ü�� : " << monsterStat.hp << endl;

		if (monsterStat.hp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�!" << endl;
			WaitForNextKey();
			return;
		}

		//�ݰ�
		damage = monsterStat.attack - playerStat.defence;
		if (damage < 0)
		{
			damage = 0;
		}

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
		{
			playerStat.hp = 0;
		}

		cout << "�÷��̾� ���� ü�� : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "����� ����߽��ϴ�... GAME OVER" << endl;
			return;
		}
	}
}

void WaitForNextKey()
{
	cout << "����Ϸ��� 1�� �����ּ���" << endl;
	cout << "> ";

	int input;
	cin >> input;

	system("cls");
}