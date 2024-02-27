#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//一些常量重定义
#define name_max 10//姓名信息允许的最大字符数量
#define sex_max 8//性别信息允许的最大字符数量
#define addr_max 30//地址信息允许的最大字符数量
#define cont_max 6//通讯录允许保存联系人的最大数量

//将通讯录功能编号定义为枚举类型,增加代码可读性
enum OptionContact
{
	EXIST,
	ADD,
	MODIFY,
	DELETE,
	FIND,
	SORT,
	SHOW
};


//将通讯录排序功能编号定义为枚举类型,增加代码可读性
enum OptionContactSort
{
	BY_NAME,
	BY_AGE,
	BY_ADDR
};

//定义结构体类型-联系人
struct cont_info
{
	char name[name_max];
	int tel;
	char sex[sex_max];
	int age;
	char addr[addr_max];
};

//定义结构体类型-通讯录
struct contact
{
	struct cont_info data[cont_max];//将所有人保存在struct contact类型的数组中
	int size;//当前已保存的联系人的数量
};

//声明函数
void AddContact(struct contact* stct_cont);
void ShowContact(const struct contact* stct_cont);
void FindContact(const struct contact* stct_cont);
void ModifyContact(struct contact* stct_cont);
void DeleteContact(struct contact* stct_cont);
void SortContact(struct contact* stct_cont);