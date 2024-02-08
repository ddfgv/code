#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("***********   1: play  *************\n");
	printf("***********   0: exit   ************\n");
	printf("************************************\n");
	printf("选择1开始游戏，选择0退出游戏\n");
	
}
//游戏实现
void game()
{
	char board[ROW][COL];
	//棋盘初始化
	initboard(board, ROW, COL);
	//显示棋盘
	displayboard(board, ROW, COL);
	//接受游戏状态
	int  ret = 0;
	while (1)
	{
		//玩家走
		player(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 4)
			break;
		//电脑走
		computer(board, ROW, COL);
		displayboard(board, ROW, COL);
		if (ret != 4)
			break;
	}
	if (ret == 1)
	{
		printf("玩家获胜\n");
		displayboard(board, ROW, COL);
	}
	else if (ret == 2)
	{
		printf("电脑获胜\n");
		displayboard(board, ROW, COL);
	}
	else
	{
		printf("平局\n");
		displayboard(board, ROW, COL);
	}
}
int main()
{
	char answer = '0';
	do
	{
		menu();
		scanf_s(" %c", &answer);
		switch (answer)
		{
		case '1':
			game();
		case '0':
			break;
		default:
			printf("选择有误，请重新选择\n");
			while (getchar() != '\n');
		}
	} while (answer  != '0');

	return 0;
}