#include "stank.h"
int main()
{
	stank ST;
	Init_stank(&ST);
	push_stank(&ST, 1);
	push_stank(&ST, 2);
	push_stank(&ST, 3);
	push_stank(&ST, 4);
	//push_stank(&ST, 5);
	//push_stank(&ST, 6);
	while (!stankempty(&ST))
	{
		printf("%d-",stanktop(&ST));
		pop_stank(&ST);
	}
	destory_stank(&ST);
	return 0;
}
