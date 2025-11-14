#pragma once
#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int stanktype;
typedef struct stank
{
	stanktype* pa;
	int capacity;
	int top;//选择方案一：top指向有效数据的下一个结点
}stank;
//初始化栈
void Init_stank(stank* ST);
//销毁栈
void destory_stank(stank* ST);
//删除数据
void pop_stank(stank* ST);
//压栈
void push_stank(stank* ST, stanktype x);
//获取栈顶的元素
stanktype stanktop(stank* ST);
// 获取栈中有效元素个数 
int stanksize(stank* ST);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int stankempty(stank* ST);
