#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
int sum = 0;

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//初始化棋盘
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void print_Board(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	int k = 0;
	for (k = 0; k <= col; k++)
	{
		printf("%d ", k);
	}
	printf("\n");
	for (k = 1; k <= row; k++)
	{
		printf("%d ", k);
		int l = 0;
		for (l = 1; l <= col; l++)
		{
			printf("%c ", board[k][l]);
		}

		printf("\n");
	}
}
void set_bomb(char bomb[ROWS][COLS], int rows, int cols)
{
	int m = 10;
	for (m = 10; m >= 0; m--)
	{
		int x = rand() % rows + 1;
		int y = rand() % cols + 1;
		if (bomb[x][y] == '0')
		{
			bomb[x][y] = '1';
		}
	}
//	print_Board(bomb, ROW, COL);
}
int count_of_bomb(char mine[ROWS][COLS], int x, int y)
{
	int num = 0;
	int i = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				num++;
			}
		}
	}
	return num;
}
void automatically_fill_the_blank(char bomb[ROWS][COLS], char show[ROWS][COLS], int row, int col,int x,int y)
{
		if (count_of_bomb(bomb, x, y) != 0)
		{
			show[x][y] = count_of_bomb(bomb, x, y) + '0';
		}
		else if (count_of_bomb(bomb, x, y)==0 && x >=1 && x <= row && y >=1 && y <= col && show[x][y] != ' ')
		{
			show[x][y] = ' ';
			automatically_fill_the_blank(bomb, show, row, col, x-1, y);
			automatically_fill_the_blank(bomb, show, row, col, x+1, y);
			automatically_fill_the_blank(bomb, show, row, col, x, y-1);
			automatically_fill_the_blank(bomb, show, row, col, x, y+1);
			automatically_fill_the_blank(bomb, show, row, col, x-1, y-1);
			automatically_fill_the_blank(bomb, show, row, col, x-1, y+1);
			automatically_fill_the_blank(bomb, show, row, col, x+1, y-1);
			automatically_fill_the_blank(bomb, show, row, col, x+1, y+1);
			automatically_fill_the_blank(bomb, show, row, col, x, y );
		}
}
//int board_is_full(char show[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (show[i][j] == '*')
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
void cover_ainmation(char show[ROW][COL], int row, int col, int x,int y)
{
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			/*if (board_is_full(show,ROW,COL))
			{
				return;
			}*/
			system("cls");
			show[x][y] = '*';
			show[row - x+1][col - y] = '*';
			Sleep(30);
			print_Board(show, ROW, COL);
		}
	}
}
void find_bomb(char bomb[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int life = 1;
	printf("标记雷的注意事项：\n");
	printf("1,一次只能标记一个位置（确实有点麻烦，但是我还没有想好一次标记多个的代码怎么写）\n");
	printf("2,1.0版本的计数器因为递归的需要被破坏掉了，标记雷不可避免地成为取得游戏胜利的唯一手段\n");
	printf("3,所以和正常的扫雷规则有所不同,只有标记出所有的雷才算游戏胜利，中途标记错误直接判负\n");
	while (count < 10&&life==1)
	{
		int choice = 0;
		printf("标记雷还是排查雷？\n");
		printf("标记雷请按1，排查雷请按2\n");
		scanf("%d",&choice);
		if (choice == 1)
		{
			int q = 0;
			int w = 0;
			printf("请输入标记坐标：\n");
			scanf("%d %d", &q, &w);
			show[q][w] = 'B';
			system("cls");
			if (bomb[q][w] == '0')
			{
				printf("你被炸飞了！一路走好！\n");
				life = 0;
				printf("还来不来？回1继续，回0不玩了");
			}
			else if (bomb[q][w] == '1')
			{
				print_Board(show, ROW, COL);
				count++;
				printf("分数：（%d/10）", count);
			}
			//point_mine(bomb,show,ROW,COL,life,count);
		}
		else if (choice == 2)
		{
			printf("请输入排查坐标\n");
			scanf("%d  %d", &x, &y);
			if (x > 0 && x <= row && y > 0 && y <= col)
			{
				if (bomb[x][y] == '1')
				{
					system("cls");
					printf("你被炸飞了！一路走好！\n");
					print_Board(bomb, ROW, COL);
					printf("还来不来？回1继续，回0不玩了");
					break;
				}
				else if (bomb[x][y] == '0')
				{
					system("cls");
					automatically_fill_the_blank(bomb, show, row, col, x, y);
					print_Board(show, ROW, COL);
				}
				else
				{
					printf("坐标非法，重新输入");
				}
			}
		}
		else
		{
			printf("输入错误，请重新输入！");
		}
	}

	if (count == 10&&life==1)
	{
		int x = 0;
		int y = 0;
		cover_ainmation(show,ROW,COL,x,y);
		printf("游戏胜利\n");
	//	print_Board(bomb, ROW, COL);
	}

}