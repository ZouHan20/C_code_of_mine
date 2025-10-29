#include"Seqlist.h"
void Contact_Init(Contact* con){
	SeqlistInit(con);
}
void Destory_Contact(Contact* con){
    SeqlistDestory(con);
}
void Add_code_in_the_Contact(Contact* con){//增加数据
	M member;
	printf("please input NAME of this person:");
	scanf("%s", member.name);
	printf("please input SEX of this person:");
	scanf("%s", member.sex);
	printf("please input dps of this person:");
	scanf("%d", &member.dps);
	printf("please input live of this person:");
	scanf("%d", &member.live);
	push_in_the_back(con, member);
	show_the_Contact(con);
}
int find_the_menber(Contact* con, char name[]){
	int i = 0;
	for (i = 0; i<con->size; i++){
		if (strcmp(con->arr[i].name, name) == 0){
			return i;
		}
	}
	return -1;
}
void search_the_member_by_name(Contact*con)
{
	char name[name_MAX];
	printf("请输入想要查找的干员名称：");
	scanf("%s", &name);
	int find = find_the_menber(con, name);
	if (find < 0) {
		printf("要查找的数据不存在！");
	}
	else {
		//show_the_Contact(con);
		printf("%s ", con->arr[find].name);
		printf("%s ", con->arr[find].sex);
		printf("%d ", con->arr[find].dps);
		printf("%d ", con->arr[find].live);
		printf("\n");
	}
}
void Delete_code_in_the_contact(Contact* con){//删除数据
	char name[name_MAX];
	printf("请输入想要删除的干员名称：");
	scanf("%s",&name);
	int find = find_the_menber(con,name);
	if (find < 0){
		printf("要删除的数据不存在！");
	}
	else{
		delete_in_the_decision(con, find);
		printf("数据删除成功\n");
	}
	show_the_Contact(con);
}
void Change_code_of_contact(Contact* con)//修改
{
	char name[name_MAX];
	printf("请输入想要修改的干员名称：");
	scanf("%s", &name);
	int find = find_the_menber(con, name);
	if (find < 0) {
		printf("要修改的数据不存在！");
	}
	else {
		printf("please input newNAME of this person:");
		scanf("%s", &con->arr[find].name);
		printf("please input SEX of this person:");
		scanf("%s", &con->arr[find].sex);
		printf("please input dps of this person:");
		scanf("%d", &con->arr[find].dps);
		printf("please input live of this person:");
		scanf("%d", &con->arr[find].live);
		printf("修改成功\n");
	}
	show_the_Contact(con);
}
void show_the_Contact(Contact* con)//打印数据
{
	for (int i = 0; i < con->size; i++)
	{
		printf("%s ", con->arr[i].name);
		printf("%s ", con->arr[i].sex);
		printf("%d ", con->arr[i].dps);
		printf("%d ", con->arr[i].live);
		printf("\n");
	}
}