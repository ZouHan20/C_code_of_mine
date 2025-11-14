#include "stank.h"
void Init_stank(stank* ST)
{
	ST->capacity = 0;
	ST->pa = NULL;
	ST->top = 0;
}
void pop_stank(stank* ST)
{
	assert(ST);
	assert(ST->top>0);
	ST->top--;
}
void destory_stank(stank* ST)
{
	assert(ST);
	free(ST->pa);
	ST->pa = NULL;
	ST->capacity = 0;
	ST->top = 0;
}
void push_stank(stank* ST, stanktype x)
{
	if (ST->top == ST->capacity)
	{
		int newcapacity = (ST->capacity == 0 ? 4 : 2 * ST->capacity);
		stank* tmp = (stank*)realloc(ST->pa, newcapacity * sizeof(stanktype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ST->capacity = newcapacity;
		ST->pa = tmp;
	}
	ST->pa[ST->top] = x;
	ST->top++;
}
//获取栈顶的元素
stanktype stanktop(stank* ST)
{
	assert(ST);
	return ST->pa[ST->top - 1];
}
// 获取栈中有效元素个数 
int stanksize(stank* ST)
{
	assert(ST);
	return ST->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int stankempty(stank* ST)
{
	assert(ST);
	if (ST->capacity == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
