#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW  3
#define COL  3
#define condition 3

//���̳�ʼ��
void initboard(char board[ROW][COL], int row, int col);
//��ʾ����
void displayboard(char board[ROW][COL], int row, int col);
//�������
void player(char board[ROW][COL], int row, int col);
//��������
void computer(char board[ROW][COL], int row, int col);
//�ж������Ƿ�����
int is_full(char board[ROW][COL], int row, int col);
//�ж��Ƿ����˻�ʤ
//����1			��һ�ʤ
//����2			���Ի�ʤ
//����3			ƽ��
//����4			��Ϸ����
int is_win(char board[ROW][COL], int row, int col);