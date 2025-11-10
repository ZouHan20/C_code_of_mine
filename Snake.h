#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define KEY_PRESS(VK) ((GetAsyncKeyState(VK)&0x1)?1:0)
#define COLS 100//x，列
#define LINE 30//y，行
#define FOOD L'★'//食物
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<stdbool.h>
#include<time.h>
//创建蛇身结点链表
typedef struct snakenode
{
	int x;
	int y;
	struct snakenode* next;
}snode;
//状态枚举
enum statue
{
	ok=1,
	pause,
	normal_end,
	kill_by_wall,
	kill_by_self,
	end_normal
};
//方向枚举
enum direction
{
	up,
	down,
	left,
	right
 };
enum difficulty
{
	normal,
	hard
	//special
};
//创建蛇信息维护结构体.
typedef struct sneakinfo
{
	snode* sneakhead;
	snode* sneakfood;
	int sleeptime;
	int foodweight;
	int score;
	enum statue statue;
	enum direction direction;
	enum difficulty difficulty;
}sneakinfo,*psneakinfo;
void startgame(psneakinfo sneak);//总函数一：开始游戏
void rungame(psneakinfo sneak);//总函数二：运行游戏
void endgame(psneakinfo sneak);//总函数三：结束游戏
void welcome_to_game(sneakinfo* sneak);//打印欢迎界面
void Setpos(int x, int y);//定位函数
void hide_the_cursor();//隐藏光标
void change_the_con();//修改控制台属性
void gamemap();//打印地图
void print_help_information();	//打印帮助信息
void Initsneak(sneakinfo* sneak);//初始化蛇
void Createfood(sneakinfo* sneak);//创建食物
void _pause(sneakinfo* sneak);//暂停游戏
void movesneak(psneakinfo sneak);//游戏运行
int nextisfood(snode* nextnode, psneakinfo sneak);//下一个结点是食物
void eatfood(snode* nextnode, psneakinfo sneak);//吃食物
void nofood(snode* nextnode, psneakinfo sneak);//不是食物
void killbywall(psneakinfo sneak);//被墙壁杀死
void killbyself(psneakinfo sneak);//被自己杀死
void through_the_wall(psneakinfo sneak);//穿墙逻辑