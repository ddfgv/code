#include "game.h"




//棋盘初始化
void initboard(char board[ROW][COL], int row, int col)
{


	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//显示棋盘
void displayboard(char board[ROW][COL], int row, int col)
{
	printf("************************************\n");
	int i=0;
	for ( i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++)
		{			
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}			
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
	printf("************************************\n");
}
//玩家下棋
void player(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	do
	{
		printf("请选择你要下的位置（   ， ）");
		scanf_s("%d,%d", &i, &j);
		if (i > 0 && j > 0 && i < 4 && j < 4 && board[i - 1][j - 1] == ' ')
		{
			board[i - 1][j - 1] = '*';
			break;
		}
		else
		{
			printf("输入的坐标不合法，请重新输入\n");
		}
	} while (1);
}
//电脑下棋
void computer(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	do
	{
		srand(time(NULL));
		i = rand() % 3;
		j = rand() % 3;
		if (board[i][j] == ' ')
		{			
			board[i][j] = '#';
			break;
		}
	} while (1);
	printf("电脑下(%d,%d)\n",i+1,j+1);
}
//判断棋盘是否已满
int is_full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 4;
		}
	}
	return 3;
}
//判断游戏是否结束
int is_win(char board[ROW][COL], int row, int col)
{
	//判断是否平局
	if (is_full(board, ROW, COL) == 3)
		return 3;
	//判断行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == '#' && board[i][1] == '#' && board[i][2] == '#')
			return 2;
		if (board[i][0] == '*' && board[i][1] == '*' && board[i][2] == '*')
			return 1;
	}
	//判断列
	for (int i = 0; i < row; i++)
	{
		if (board[0][i] == '#' && board[1][i] == '#' && board[2][i] == '#')
			return 2;
		if (board[0][i] == '*' && board[1][i] == '*' && board[2][i] == '*')
			return 1;
	}
	//判断对角线
	
	if (board[0][0] == '#' && board[1][1] == '#' && board[2][2] == '#')
		return 2;
	if (board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#')
		return 2;
	if (board[0][0] == '*' && board[1][1] == '*' && board[2][2] == '*')
		return 1;
	if (board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#')
		return 1;
	return 4;
}
