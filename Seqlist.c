#include"Seqlist.h"
void SeqlistInit(SL*sl)
{
	assert(sl);
	sl->arr = NULL;
	sl->size = 0;
	sl->Space = 0;
}
void SeqlistDestory(SL* sl)
{
	assert(sl);
	if (sl->arr)
	{
		free(sl->arr);
	}
	sl->arr = NULL;
	sl->size = 0;
	sl->Space = 0;
}
void Inlarge_the_Space(SL* sl)
{
	assert(sl);
	if (sl->size == sl->Space){
		int Newspace = (sl->Space == 0 ? 4 : sl->Space * 2);
		TypeOfSeqlist * tmp = (TypeOfSeqlist *)realloc(sl->arr,Newspace*sizeof(TypeOfSeqlist));
		if (tmp == NULL){
			return;
		}
		else{
			sl->arr = tmp;
			sl->Space = Newspace;
		}
	}
}
//尾部插入
void push_in_the_back(SL* sl, TypeOfSeqlist x){
	assert(sl);
	Inlarge_the_Space(sl);
	sl->arr[sl->size++] = x;
	//print_seqlist(sl);
}
//头部插入
void push_in_the_front(SL* sl, TypeOfSeqlist x){
	Inlarge_the_Space(sl);
	for (int i=sl->size;i>0;i--){
		sl->arr[i] = sl->arr[i - 1];//arr[1]=arr[0];
	}
	sl->arr[0] = x;
	sl->size++;
	//print_seqlist(sl);
}
//指定位置插入
void push_in_the_decision(SL* sl, TypeOfSeqlist x, int pos){
	//sl->arr[pos]///size-1--->size///
	Inlarge_the_Space(sl);
	for (int i = 0; i < sl->size - pos - 1; i++)
	{
		sl->arr[sl->size - i] = sl->arr[sl->size - i - 1];
	}
	sl->size++;
	sl->arr[pos] = x;
	//print_seqlist(sl);
}
void delete_in_the_back(SL* sl){
	assert(sl);
	sl->size--;
	//print_seqlist(sl);
}
//头部删除
void delete_in_the_front(SL* sl){
	assert(sl);
	for (int i =sl->size; i>0; i--){
		sl->arr[sl->size-i] = sl->arr[sl->size-i+1];//0   1
	}
	sl->size--;
	//print_seqlist(sl);
}
//指定位置删除
void delete_in_the_decision(SL*sl,int pos){
	assert(sl);
	for (int i = pos; i < sl->size-1; i++) {
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
	//print_seqlist(sl);
}
void print_seqlist(SL*sl){
	assert(sl);
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->arr[i]);
	}
	printf("\n");
}