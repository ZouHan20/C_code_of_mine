#include"Snake.h"
//修改控制台属性
void change_the_con()
{
	system("mode con cols=100lines=30");//30行，100列
	system("title 贪吃蛇");
}
//隐藏光标
void hide_the_cursor()
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput,&CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput ,&CursorInfo);
}
//定位函数
void Setpos(int x,int y)//x列  y行
{
	COORD POS = { x,y };
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(houtput, POS);
}
////打印欢迎界面
void welcome_to_game(sneakinfo* sneak)
{
	Setpos(36, 13);
	wprintf(L"%ls", L"◆欢迎来到贪吃蛇游戏◆");
	Setpos(73, 27);
	system("pause");
	system("cls");
	Setpos(36, 10);
	wprintf(L"%ls", L"◆更新日志◆");
	Setpos(30, 11);
	printf("11月2日2025年下午：开始制作");
	Setpos(28, 12);
	printf("11月6日2025年凌晨:基础工作完成");
	Setpos(19, 13);
	printf("11月6日2025年下午:添加了难度初步选项，增加穿墙功能");
	Setpos(73, 27);
	system("pause");
	system("cls");
	Setpos(36, 12);
	wprintf(L"%ls", L"◆按↑↓←→键移动◆");
	Setpos(36, 14);
	wprintf(L"%ls", L"◆按F3 ,F4键加减速◆");
	Setpos(36, 16);
	wprintf(L"%ls", L"◆按空格键暂停游戏◆");
	Setpos(36, 18);
	wprintf(L"%ls", L"◆按Esc键结束游戏 ◆");
	Setpos(26, 20);
	wprintf(L"%ls", L"◆hard难度撞墙即死 normal难度撞墙不会死  ◆");
	system("cls");
	Setpos(30, 12);
	wprintf(L"◆请选则难度normal请按N，hard请按H◆");
	char choice = 0;
	Setpos(67, 12);
	scanf("%c", &choice);
	Setpos(67, 12);
	printf(" ");
	getchar();
	if (choice == 'N' || choice == 'n')
	{
		sneak->difficulty = normal;
	}
	else if(choice == 'H' || choice == 'h')
	{
		sneak->difficulty = hard;
	}
	Setpos(73, 27);
	system("pause");
	system("cls");

}
//打印地图
void gamemap()
{
	for (int i = 0; i < 25; i++)
	{
		wprintf(L"■");
	}
	Setpos(0, 25);
	for (int i = 0; i < 25; i++)
	{
		wprintf(L"■");
	}
	for (int i = 1; i < 25; i++)
	{
		Setpos(0, i);
		wprintf(L"■");
	}
	for (int i = 1; i < 25; i++)
	{
		Setpos(48, i);
		wprintf(L"■");
	}
}
//打印帮助信息
void print_help_information()
{
	Setpos(54, 16);
	wprintf(L"◆帮助信息◆");
	Setpos(54, 18);
	wprintf(L"%ls", L"按↑↓←→键移动");
	Setpos(54, 19);
	wprintf(L"%ls", L"按F3,F4键加减速,按F6放飞自我，F7恢复");
	Setpos(54, 20);
	wprintf(L"%ls", L"按空格键暂停游戏");
	Setpos(54, 21);
	wprintf(L"%ls", L"按Esc键结束游戏");
	Setpos(54, 22);
	wprintf(L"%ls", L"加速可以获得更多的分数");
	Setpos(54, 23);
	wprintf(L"%ls", L"制作人CSDN@小此方");
}
void Initsneak(sneakinfo* sneak)
{
	sneak->sneakhead = NULL;
	snode* newnode = NULL;
	for (int j = 0; j < 5; j++)
	{
		newnode = (snode*)malloc(sizeof(snode));
		if (newnode == NULL)
		{
			perror("malloc::newnode");
			return;
		}
		newnode->next = NULL;
		newnode->x = 20 + 2 * j;
		newnode->y = 10;
		if (sneak->sneakhead ==NULL)
		{
			sneak->sneakhead = newnode;
		}
		else
		{
			newnode->next = sneak->sneakhead;
			sneak->sneakhead = newnode;
		}
	}
	int i = 5;
	snode* cur = sneak->sneakhead;
	while(i)
	{
		Setpos(cur->x ,cur->y);
		wprintf(L"●");
		cur = cur->next;
		i--;
	}
	//信息初始化
	sneak->sleeptime = 200;
	sneak->foodweight = 50;
	sneak->score = 0;
	sneak->statue = ok;
	sneak->direction = right;
}
void Createfood(sneakinfo* sneak)
{
	snode* food = malloc(sizeof(snode));
	if (food == NULL)
	{
		perror("malloc_food");
		return;
	}
	again:
	do {
		food->x = rand() % 46+2;
		food->y = rand() % 24+1;
	} while (food->x % 2 != 0);//奇数进循环，偶数出循环
	snode* cur = sneak->sneakhead;
	while (cur)
	{
		if ((cur->x == food->x ) && (cur->y == food->y))
		{
			goto again;
		}
		cur = cur->next;
	}
	food->next = NULL;
	Setpos(food->x, food->y);
//	printf("food->x : %d, ");
	wprintf(L"%lc",FOOD);
	sneak->sneakfood = food;
}
//总函数一：开始游戏
void startgame(psneakinfo sneak)
{
	//准备工作；
	//修改控制台属性
	change_the_con();
	//隐藏光标
	hide_the_cursor();
	//打印欢迎界面
	welcome_to_game(sneak);
	//打印地图
	gamemap();
	//初始化蛇
	Initsneak(sneak);
	//创造食物
	Createfood(sneak);
}
//暂停函数
void _pause(sneakinfo* sneak)
{
	
	while (1)
	{
		Sleep(3000);
		if (KEY_PRESS(VK_SPACE))
		{
			sneak->statue = ok;
			break;
		}
	}
}
int nextisfood(snode* nextnode, psneakinfo sneak)
{
	if (nextnode->x == sneak->sneakfood->x && nextnode->y == sneak->sneakfood->y)
		return 1;
	else
		return 0;
}
void eatfood(snode* nextnode,psneakinfo sneak)
{
	//头插接入
	sneak->sneakfood ->next = sneak->sneakhead;
	sneak->sneakhead  = sneak->sneakfood;
	free(nextnode);
	nextnode = NULL;
	snode* cur = sneak->sneakhead;
	while (cur)
	{
		Setpos(cur->x, cur->y);
		wprintf(L"●");
		cur = cur->next;
	}
	sneak->score += sneak->foodweight;
	Createfood(sneak);
}
void nofood(snode* nextnode, psneakinfo sneak)
{
	nextnode->next = sneak->sneakhead;
	sneak->sneakhead = nextnode;
	snode* cur = sneak->sneakhead;
	while (cur->next->next)
	{
		Setpos(cur->x, cur->y);
		wprintf(L"●");
		cur = cur->next;
	}
	Setpos(cur->x, cur->y);
	wprintf(L"●");
	Setpos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}
void killbywall(psneakinfo sneak)
{
	if (sneak->sneakhead->x == 0 || sneak->sneakhead->x == 48 || sneak->sneakhead->y == 0 || sneak->sneakhead->y == 25)
	{
		sneak->statue = kill_by_wall;
	}
}
void through_the_wall(psneakinfo sneak)
{
	if (sneak->sneakhead->x == 0)
	{
		sneak->sneakhead->x = 46;
	}
	if (sneak->sneakhead->x == 48)
	{
		sneak->sneakhead->x = 2;
	}
	if (sneak->sneakhead->y == 0)
	{
		sneak->sneakhead->y = 24;
	}
	if (sneak->sneakhead->y == 25)
	{
		sneak->sneakhead->y = 1;
	}
}
void killbyself(psneakinfo sneak)
{
	snode* cur = sneak->sneakhead->next;
	while (cur)
	{
		if (sneak->sneakhead->x== cur->x && sneak->sneakhead->y== cur->y)
		{
			sneak->statue = kill_by_self;
			break;
		}
		cur = cur->next;
	}
}
void movesneak(psneakinfo sneak)
{
	snode* nextnode = malloc(sizeof(snode));
	if (nextnode == NULL)
	{
		perror("malloc::nextnode");
		return;
	}
	switch (sneak->direction)
	{
	case up:
	{
		nextnode->x = sneak->sneakhead->x;
		nextnode->y = sneak->sneakhead->y - 1;
		break;
	}
	case down:
	{
		nextnode->x = sneak->sneakhead->x;
		nextnode->y = sneak->sneakhead->y + 1;
		break;
	}
	case left:
	{
		nextnode->x = sneak->sneakhead->x - 2;
		nextnode->y = sneak->sneakhead->y;
		break;
	}
	case right:
	{
		nextnode->x = sneak->sneakhead->x + 2;
		nextnode->y = sneak->sneakhead->y;
		break;
	}
	}
	if (nextisfood(nextnode,sneak))
	{
		eatfood(nextnode, sneak);
	}
	else
	{
		nofood(nextnode,sneak);
	}
	if (sneak->difficulty == normal)
	{
		through_the_wall(sneak);
	}
	if (sneak->difficulty == hard)
	{
		killbywall(sneak);
	}
	killbyself(sneak);
}
void rungame(psneakinfo sneak)
{
	//打印帮助信息
	print_help_information();
	do
	{
		//打印动态帮助信息
		Setpos(54, 8);
		printf("#目前总得分: %d #",sneak->score );
		Setpos(54, 10);
		printf("当前食物分数：%5d\n", sneak->foodweight);
		//上下左右暂停退出加速减速
		if (KEY_PRESS(VK_UP) && sneak->direction != down)
		{
			sneak->direction = up;
		}
		if (KEY_PRESS(VK_DOWN) && sneak->direction != up)
		{
			sneak->direction = down;
		}
		if (KEY_PRESS(VK_LEFT) && sneak->direction != right)
		{
			sneak->direction = left;
		}
		if (KEY_PRESS(VK_RIGHT) && sneak->direction != left)
		{
			sneak->direction = right;
		}
		if (KEY_PRESS(VK_SPACE))
		{
			sneak->statue = pause;
			_pause(sneak);
		}
		if (KEY_PRESS(VK_F3))//加速
		{
			if (sneak->foodweight >= 10 && sneak->foodweight < 100)
			{
				sneak->sleeptime -= 20;
				sneak->foodweight += 10;
			}
		}
		if (KEY_PRESS(VK_F4))//减速
		{
			if (sneak->foodweight > 10 && sneak->foodweight <= 100)
			{
				sneak->sleeptime += 20;
				sneak->foodweight -= 10;
			}
		}
		if (KEY_PRESS(VK_F6))
		{
			sneak->sleeptime = 1;
			sneak->foodweight = 9999;
		}
		if (KEY_PRESS(VK_F7))
		{
			sneak->sleeptime = 200;
		}
		if (KEY_PRESS(VK_ESCAPE))
		{
			sneak->statue = normal_end;
			break;
		}
		movesneak(sneak);
		Sleep(sneak->sleeptime);
	} while (sneak->statue==ok);
}
void endgame(psneakinfo sneak)
{
	if (sneak->statue == normal_end)
	{
		Setpos(19,12);
		printf("正常退出游戏");
	}
	if (sneak->statue == kill_by_self)
	{
		Setpos(16, 12);
		printf("你死了，凶手是你自己");
	}
	if (sneak->statue == kill_by_wall)
	{
		Setpos(16, 12);
		printf("你死了，凶手是墙壁");
	}
	snode* cur = sneak->sneakhead;
	while (cur)
	{
		snode* del = cur;
		cur = cur->next;
		free(del);
	}
}