#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"Arknight.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//顺序表的创建和声明
typedef struct member TypeOfSeqlist;
typedef struct Seqlist{
	TypeOfSeqlist * arr;
	int size;
	int Space;
}SL;
//顺序表的初始化
void SeqlistInit(SL* sl);
//顺序表的销毁
void SeqlistDestory(SL* sl);
//尾部插入
void push_in_the_back(SL* sl, TypeOfSeqlist x);
//头部插入
void push_in_the_front(SL* sl, TypeOfSeqlist x);
//指定位置插入
void push_in_the_decision(SL* sl, TypeOfSeqlist x, int pos);
//按照干员名字查找
// 
//尾部删除
void delete_in_the_back(SL* sl);
//头部删除
void delete_in_the_front(SL* sl);
//指定位置删除
void delete_in_the_decision(SL* sl,int pos);
//顺序表的打印
void print_seqlist(SL* sl);