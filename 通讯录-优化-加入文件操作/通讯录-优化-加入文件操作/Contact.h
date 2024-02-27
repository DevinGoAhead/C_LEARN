#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

//一些常量重定义
#define name_max 10//姓名信息允许的最大字符数量
#define sex_max 8//性别信息允许的最大字符数量
#define addr_max 30//地址信息允许的最大字符数量
//#define cont_max 6//通讯录允许保存联系人的最大数量-优化之前
#define capcty_initial 3//通讯录初始容量能够保存联系人的数量-第一次优化

//将通讯录功能编号定义为枚举类型,增加代码可读性
enum OptionContact
{
	EXIST,
	ADD,
	MODIFY,
	DELETE,
	FIND,
	SORT,
	SAVE,//第二次优化加入保存功能
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

////定义结构体类型-通讯录-优化之前
//struct contact
//{
//	struct cont_info data[cont_max];// 将所有人保存在struct contact类型的数组中* /
//	struct cont_info* data;
//	int size;//当前已保存的联系人的数量
//};

//定义结构体类型 - 通讯录-第一次优化
struct contact
{
	struct cont_info* data;//指向struct cont_info数据的指针，后面将以单个struct cont_info为单位进行扩容
	int capacity;//当前通讯录的容量
	int size;//当前已保存的联系人的数量
};

//声明函数
void InitializeContact(struct contact* stct_cont);
int LocateConcat(const struct contact* stct_cont, const char* name_dest);
void PrintContact_Single(const struct contact* stct_cont, int i);
void LoadContact(struct contact* stct_cont);
void CheckCapacity(struct contact* stct_cont);

void AddContact(struct contact* stct_cont);
void ShowContact(const struct contact* stct_cont);
void FindContact(const struct contact* stct_cont);
void ModifyContact(struct contact* stct_cont);
void DeleteContact(struct contact* stct_cont);
void SortContact(struct contact* stct_cont);
void DestroyContact(struct contact* stct_cont);
void SaveContact(const struct contact* stct_cont);