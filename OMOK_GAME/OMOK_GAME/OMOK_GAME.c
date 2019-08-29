#include <stdio.h>
#include <windows.h>
#include <conio.h>
#pragma warning (disable : 4996)

#define LEFT_UP 1
#define RIGHT_UP 2
#define LEFT_DOWN 3
#define RIGHT_DOWN 4
#define LINE_UP 5
#define LINE_DOWN 6
#define LINE_LEFT 7
#define LINE_RIGHT 8
#define CENTER 0
#define BLACK 9
#define WHITE 10
#define SPACE 32

#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80

//맵
void ShowMap(int Map[15][15], int BlackStone, int WhiteStone)
{
	system("cls");
	int x, y;
	for (x = 0; x < 15; ++x)
	{
		printf("\t");
		for (y = 0; y < 15; ++y)
		{

			switch (Map[x][y])
			{
			case LEFT_UP:
				printf("┌");
				break;
			case RIGHT_UP:
				printf("┐");
				break;
			case LEFT_DOWN:
				printf("└");
				break;
			case RIGHT_DOWN:
				printf("┘");
				break;
			case LINE_UP:
				printf("┬");
				break;
			case LINE_DOWN:
				printf("┴");
				break;
			case LINE_LEFT:
				printf("├");
				break;
			case LINE_RIGHT:
				printf("┤");
				break;
			case CENTER:
				printf("┼");
				break;
			case BLACK:
				printf("○");
				break;
			case WHITE:
				printf("●");
				break;
			}
		}
		printf("\n");
	}
	printf("검정돌의 현재 갯수 : %d\n\n", WhiteStone);
	printf("흰색돌의 현재 갯수 : %d\n", BlackStone);
}

void main()
{
	int Map[15][15] = {
		1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
		3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4
	};
	int x = 0, y = 0;
	int i = 0, j = 0;
	int Stone = 9;
	int NextTemp = 1;
	int Move = 0;
	int BlackStone = 0;
	int WhiteStone = 0;
	ShowMap(Map, BlackStone, WhiteStone);
	while (1)
	{
		Move = getch();
		if (Move == 224)
			continue;
		else if (Move == 32)
		{
			//가로세로 확인
			for (i = 0; i < 15; ++i)
			{
				for (j = 0; j < 15; ++j)
				{
					if (Map[i][j] == 9 && Map[i][j + 1] == 9 && Map[i][j + 2] == 9 && Map[i][j + 3] == 9 && Map[i][j + 4] == 9)
					{
						printf("\t\t\t\t!!!검은돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 9 && Map[j + 1][i] == 9 && Map[j + 2][i] == 9 && Map[j + 3][i] == 9 && Map[j + 4][i] == 9)
					{
						printf("\t\t\t\t!!!검은돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[i][j] == 10 && Map[i][j + 1] == 10 && Map[i][j + 2] == 10 && Map[i][j + 3] == 10 && Map[i][j + 4] == 10)
					{
						printf("\t\t\t\t!!!흰돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 10 && Map[j + 1][i] == 10 && Map[j + 2][i] == 10 && Map[j + 3][i] == 10 && Map[j + 4][i] == 10)
					{
						printf("\t\t\t\t!!!흰돌 승리!!!\n");
						getchar();
						exit(0);
					}
				}
			}

			//대각선 확인
			for (i = 0; i < 15; ++i)
			{
				for (j = 0; j < 15; ++j)
				{
					if (Map[i][j] == 9 && Map[i + 1][j + 1] == 9 && Map[i + 2][j + 2] == 9 && Map[i + 3][j + 3] == 9 && Map[i + 4][j + 4] == 9)
					{
						printf("\t\t\t\t!!!검은돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 9 && Map[j - 1][i + 1] == 9 && Map[j - 2][i + 2] == 9 && Map[j - 3][i + 3] == 9 && Map[j - 4][i + 4] == 9)
					{
						printf("\t\t\t\t!!!검은돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[i][j] == 10 && Map[i + 1][j + 1] == 10 && Map[i + 2][j + 2] == 10 && Map[i + 3][j + 3] == 10 && Map[i + 4][j + 4] == 10)
					{
						printf("\t\t\t\t!!!흰돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 10 && Map[j - 1][i + 1] == 10 && Map[j - 2][i + 2] == 10 && Map[j - 3][i + 3] == 10 && Map[j - 4][i + 4] == 10)
					{
						printf("\t\t\t\t!!!흰돌 승리!!!\n");
						getchar();
						exit(0);
					}

				}
			}


			//현 위치에 돌이 있다면 돌을 놓을수 없게함
			if (NextTemp == BLACK || NextTemp == WHITE)
				continue;

			// 돌을 두고 색을 바꿈(턴을 바꾸는것)
			if (Stone == BLACK)
			{
				Stone = WHITE;
				++WhiteStone;
			}
			else
			{
				Stone = BLACK;
				++BlackStone;
			}
			x = 0, y = 0;
			NextTemp = 1;
		}
		//방향이동
		switch (Move)
		{
		case UP:
			if (x > 0)
			{
				Map[x][y] = NextTemp;
				NextTemp = Map[x - 1][y];
				x--;
				Map[x][y] = Stone;
				ShowMap(Map, BlackStone, WhiteStone);
				continue;
			}
			break;
		case DOWN:
			if (x < 14)
			{
				Map[x][y] = NextTemp;
				NextTemp = Map[x + 1][y];
				x++;
				Map[x][y] = Stone;
				ShowMap(Map, BlackStone, WhiteStone);
				continue;
			}
			break;
		case RIGHT:
			if (y < 14)
			{
				Map[x][y] = NextTemp;
				NextTemp = Map[x][y + 1];
				y++;
				Map[x][y] = Stone;
				ShowMap(Map, BlackStone, WhiteStone);
				continue;
			}
			break;
		case LEFT:
			if (y > 0)
			{
				Map[x][y] = NextTemp;
				NextTemp = Map[x][y - 1];
				y--;
				Map[x][y] = Stone;
				ShowMap(Map, BlackStone, WhiteStone);
				continue;
			}
		}
	}
}