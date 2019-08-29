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
#define YELLOWSTONE 9
#define BLUESTONE 10
#define SPACE 32

#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80

enum {
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VIOLET,      /* 13 : 보라 */
	YELLOW,      /* 14 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

void CursorView(char show);
void gotoxy(int x, int y);
void SetColor(int color);
void ShowMap(int Map[15][15], int BlackStone, int BlueStone);

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
	int YellowStone = 0;
	int BlueStone = 0;
	ShowMap(Map, YellowStone, BlueStone);
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
						SetColor(YELLOW);
						gotoxy(45, 5);
						printf("!!!노란돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 9 && Map[j + 1][i] == 9 && Map[j + 2][i] == 9 && Map[j + 3][i] == 9 && Map[j + 4][i] == 9)
					{
						SetColor(YELLOW);
						gotoxy(45, 5);
						printf("!!!노란돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[i][j] == 10 && Map[i][j + 1] == 10 && Map[i][j + 2] == 10 && Map[i][j + 3] == 10 && Map[i][j + 4] == 10)
					{
						SetColor(BLUE);
						gotoxy(45, 5);
						printf("!!!파란돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 10 && Map[j + 1][i] == 10 && Map[j + 2][i] == 10 && Map[j + 3][i] == 10 && Map[j + 4][i] == 10)
					{
						SetColor(BLUE);
						gotoxy(45, 5);
						printf("!!!파란돌 승리!!!\n");
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
						SetColor(YELLOW);
						gotoxy(45, 5);
						printf("!!!노란돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 9 && Map[j - 1][i + 1] == 9 && Map[j - 2][i + 2] == 9 && Map[j - 3][i + 3] == 9 && Map[j - 4][i + 4] == 9)
					{
						SetColor(YELLOW);
						gotoxy(45, 5);
						printf("!!!노란돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[i][j] == 10 && Map[i + 1][j + 1] == 10 && Map[i + 2][j + 2] == 10 && Map[i + 3][j + 3] == 10 && Map[i + 4][j + 4] == 10)
					{
						SetColor(BLUE);
						gotoxy(45, 5);
						printf("!!!파란돌 승리!!!\n");
						getchar();
						exit(0);
					}
					else if (Map[j][i] == 10 && Map[j - 1][i + 1] == 10 && Map[j - 2][i + 2] == 10 && Map[j - 3][i + 3] == 10 && Map[j - 4][i + 4] == 10)
					{
						SetColor(BLUE);
						gotoxy(45, 5);
						printf("!!!파란돌 승리!!!\n");
						getchar();
						exit(0);
					}

				}
			}


			//현 위치에 돌이 있다면 돌을 놓을수 없게함
			if (NextTemp == YELLOWSTONE || NextTemp == BLUESTONE)
				continue;

			// 돌을 두고 색을 바꿈(턴을 바꾸는것)
			if (Stone == YELLOWSTONE)
			{
				Stone = BLUESTONE;
				++BlueStone;
			}
			else
			{
				Stone = YELLOWSTONE;
				++YellowStone;
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
				ShowMap(Map, YellowStone, BlueStone);
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
				ShowMap(Map, YellowStone, BlueStone);
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
				gotoxy(x, y);
				ShowMap(Map, YellowStone, BlueStone);
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
				ShowMap(Map, YellowStone, BlueStone);
				continue;
			}
		}
	}
}



void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowMap(int Map[15][15], int YellowStone, int BlueStone)
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
				SetColor(RED);
				printf("┌");
				break;
			case RIGHT_UP:
				SetColor(RED);
				printf("┐");

				break;
			case LEFT_DOWN:
				SetColor(RED);
				printf("└");

				break;
			case RIGHT_DOWN:
				SetColor(RED);
				printf("┘");

				break;
			case LINE_UP:
				SetColor(RED);
				printf("┬");

				break;
			case LINE_DOWN:
				SetColor(RED);
				printf("┴");

				break;
			case LINE_LEFT:
				SetColor(RED);
				printf("├");

				break;
			case LINE_RIGHT:
				SetColor(RED);
				printf("┤");

				break;
			case CENTER:
				SetColor(RED);
				printf("┼");

				break;
			case YELLOWSTONE:
				SetColor(YELLOW);
				printf("●");

				break;
			case BLUESTONE:
				SetColor(BLUE);
				printf("●");

				break;
			}
		}
		printf("\n");
	}
	SetColor(GREEN);
	gotoxy(45, 1);
	printf("노란돌의 현재 갯수 : %d\n\n", BlueStone);
	gotoxy(45, 3);
	printf("파란돌의 현재 갯수 : %d\n", YellowStone);


}