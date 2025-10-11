#define _CRT_SECURE_NO_WARNINGS 1
//扫雷游戏
#include "game.h"
void menu(void)
{
	printf("———————————————————————————————————————————————— 扫雷游戏—————————————————————————————————————————————————————————\n");
	printf("                                   ###################################\n");
	printf("                                   ###########[1]开始游戏  ###########\n");
	printf("                                   ###########[0]结束游戏  ###########\n");
	printf("                                   ###################################\n");
}
void game(void)
{
	char bomb[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};

	InitBoard(bomb, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'#');
	//初始化棋盘
	//print_Board(bomb, ROW, COL);
	print_Board(show, ROW, COL);
	//打印棋盘
	set_bomb(bomb,ROW,COL);
	//设置雷
	//count_of_bomb(show, ROW, COL);
	find_bomb(bomb, show, ROW, COL);
}
int main()
{
	printf("                                前言：输入坐标的时候格式是:第几行 空格 第几列\n");
	printf("                                坐标输入后回车，会告诉你这个格子周围8格有多少炸弹\n");
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	do
	{
		printf("                                                请输入\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("                                             游戏结束喽\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新输入");
			break;
		}
		}

	} while (input);
	return 0;
}
