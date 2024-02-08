#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW  3
#define COL  3
#define condition 3

//棋盘初始化
void initboard(char board[ROW][COL], int row, int col);
//显示棋盘
void displayboard(char board[ROW][COL], int row, int col);
//玩家下棋
void player(char board[ROW][COL], int row, int col);
//电脑下棋
void computer(char board[ROW][COL], int row, int col);
//判断棋盘是否已满
int is_full(char board[ROW][COL], int row, int col);
//判断是否有人获胜
//返回1			玩家获胜
//返回2			电脑获胜
//返回3			平局
//返回4			游戏继续
int is_win(char board[ROW][COL], int row, int col);