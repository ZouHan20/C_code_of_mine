#include"Snake.h"
//测试函数
void test()
{
	//创建一个蛇数据维护变量
	char choice = 'N';
	sneakinfo sneak = { 0 };
	do
	{
		//开始游戏总函数
		startgame(&sneak);
		//运行游戏总函数
		rungame(&sneak);
		//结束游戏总函数
		endgame(&sneak);
		Setpos(16, 12);
		printf("想要再来一局吗（N/Y）");
		Setpos(38, 12);
		scanf("%c", &choice);
		getchar();
	} while (choice=='Y'||choice=='y');
}
int main()
{
	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "");
	test();
	Setpos(0, 27);
	return 0;
}
