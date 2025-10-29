#pragma once
#define name_MAX 20
#define sex_MAX 10
typedef struct member
{
	char name[name_MAX];
	char sex[sex_MAX];
	int dps;
	int live;
}M;
//重命名
typedef struct Seqlist Contact;
//通讯录增加数据
void Add_code_in_the_Contact(Contact * con );
//通讯录删除数据
void Delete_code_in_the_contact(Contact * con);
//通讯录的修改
void Change_code_of_contact(Contact* con);
//通讯录查找
void search_the_member_by_name(Contact* con);
//展示通讯录数据
void show_the_Contact(Contact* con);
//通讯录初始化
void Contact_Init(Contact* con);
//通讯录销毁
void Destory_Contact(Contact* con);