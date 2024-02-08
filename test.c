#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("***********   1: play  *************\n");
	printf("***********   0: exit   ************\n");
	printf("************************************\n");
	printf("ѡ��1��ʼ��Ϸ��ѡ��0�˳���Ϸ\n");
	
}
//��Ϸʵ��
void game()
{
	char board[ROW][COL];
	//���̳�ʼ��
	initboard(board, ROW, COL);
	//��ʾ����
	displayboard(board, ROW, COL);
	//������Ϸ״̬
	int  ret = 0;
	while (1)
	{
		//�����
		player(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 4)
			break;
		//������
		computer(board, ROW, COL);
		displayboard(board, ROW, COL);
		if (ret != 4)
			break;
	}
	if (ret == 1)
	{
		printf("��һ�ʤ\n");
		displayboard(board, ROW, COL);
	}
	else if (ret == 2)
	{
		printf("���Ի�ʤ\n");
		displayboard(board, ROW, COL);
	}
	else
	{
		printf("ƽ��\n");
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
			printf("ѡ������������ѡ��\n");
			while (getchar() != '\n');
		}
	} while (answer  != '0');

	return 0;
}