#include "game.h"




//���̳�ʼ��
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
//��ʾ����
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
//�������
void player(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	do
	{
		printf("��ѡ����Ҫ�µ�λ�ã�   �� ��");
		scanf_s("%d,%d", &i, &j);
		if (i > 0 && j > 0 && i < 4 && j < 4 && board[i - 1][j - 1] == ' ')
		{
			board[i - 1][j - 1] = '*';
			break;
		}
		else
		{
			printf("��������겻�Ϸ�������������\n");
		}
	} while (1);
}
//��������
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
	printf("������(%d,%d)\n",i+1,j+1);
}
//�ж������Ƿ�����
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
//�ж���Ϸ�Ƿ����
int is_win(char board[ROW][COL], int row, int col)
{
	//�ж��Ƿ�ƽ��
	if (is_full(board, ROW, COL) == 3)
		return 3;
	//�ж���
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == '#' && board[i][1] == '#' && board[i][2] == '#')
			return 2;
		if (board[i][0] == '*' && board[i][1] == '*' && board[i][2] == '*')
			return 1;
	}
	//�ж���
	for (int i = 0; i < row; i++)
	{
		if (board[0][i] == '#' && board[1][i] == '#' && board[2][i] == '#')
			return 2;
		if (board[0][i] == '*' && board[1][i] == '*' && board[2][i] == '*')
			return 1;
	}
	//�ж϶Խ���
	
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
