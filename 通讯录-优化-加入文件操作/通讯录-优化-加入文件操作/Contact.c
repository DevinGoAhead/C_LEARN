#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//只定位，不显示。——由于定位联系人函数许多功能都需要用到，因此单独抽离出来为LocateConcat-非功能函数
int LocateConcat(const struct contact* stct_cont, const char* name_dest)
{
	int i = 0;
	while (strcmp(stct_cont->data[i].name, name_dest)&&i< stct_cont->size)
		i++;
	if (i == stct_cont->size)
		return 0;
	else
		return i;
}

//打印单个联系人-非功能函数
void PrintContact_Single(const struct contact* stct_cont,int i)
{
	printf("%-14s", stct_cont->data[i].name);
	printf("%-14d", stct_cont->data[i].tel);
	printf("%-10s", stct_cont->data[i].sex);
	printf("%-8d", stct_cont->data[i].age);
	printf("%-15s", stct_cont->data[i].addr);
	printf("\n");
}

////初始化通讯录-功能函数-第一次优化
//void InitializeContact(struct contact* stct_cont)
//{
//	stct_cont->data = malloc(capcty_initial * sizeof(struct cont_info));// capcty_initial==3，data指向的新开辟的内存能保存3个联系人
//	stct_cont->capacity = capcty_initial;
//	stct_cont->size = 0;
//}

//加载文件内容-非功能函数-用于InitializeContact-第二次优化
void LoadContact(struct contact* stct_cont)
{
	FILE* pRead = fopen("contact.dat", "rb");
	if (pRead == NULL)//判断是否成功打开文件
	{
		printf("LoadContact::%s\n", strerror(errno));//用于与其他报错信息区分，更加精准判断是哪里报错
	}
	else
	{
		struct cont_info temp;//定义临时变量，存储读出的联系人
		while (fread(&temp, sizeof(struct cont_info), 1, pRead))//一次读出一个，读出失败即已将信息完全读出
		{
			CheckCapacity(stct_cont);//判断空间容量是否足够并根据需要开辟新的空间
			stct_cont->data[stct_cont->size] = temp;
			stct_cont->size++;
		}
	}
	fclose(pRead);
	pRead = NULL;
}

//初始化通讯录-功能函数-第二次优化
void InitializeContact(struct contact* stct_cont)
{
	stct_cont->data = malloc(capcty_initial * sizeof(struct cont_info));// capcty_initial==3，data指向的新开辟的内存能保存3个联系人
	stct_cont->capacity = capcty_initial;
	stct_cont->size = 0;
	LoadContact(stct_cont);
}


////添加联系人-功能函数-优化之前
//void AddContact(struct contact* stct_cont)
//{
//	if (cont_max == stct_cont->size)
//		printf("通讯录已满，无法继续添加");
//	else
//	{
//		printf("请输入姓名：");
//		scanf("%s", stct_cont->data[stct_cont->size].name);//name为数组，因此不需要加&
//		printf("请输入电话：");
//		scanf("%d", &(stct_cont->data[stct_cont->size].tel));//tel为整型，因此需要加&
//		printf("请输入性别：");
//		scanf("%s", stct_cont->data[stct_cont->size].sex);
//		printf("请输入年龄：");
//		scanf("%d", &(stct_cont->data[stct_cont->size].age));
//		printf("请输入地址：");
//		scanf("%s", stct_cont->data[stct_cont->size].addr);
//		stct_cont->size++;
//
//		printf("\n添加联系人成功...\n");
//	}
//}

//判断通讯录容量并扩容-非功能函数-用于AddContact-第一次优化
void CheckCapacity(struct contact* stct_cont)
{
	if (stct_cont->capacity == stct_cont->size)
	{
		printf("通讯录已满，将自动进行扩容...\n");
		printf("......\n");
		struct cont_info* data2 = realloc(stct_cont->data, (stct_cont->capacity + 2) * sizeof(struct cont_info));//stct_cont->capacity + 2 扩容2个
		if (data2 == NULL)//判断开辟空间是否成功
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			stct_cont->data = data2;//仍然使用初始指针维护新开辟的空间
			stct_cont->capacity +=2;
			printf("扩容成功...\n\n");
		}
	}
}

//添加联系人-功能函数-第一次优化
void AddContact(struct contact* stct_cont)
{
	CheckCapacity(stct_cont);

	printf("请输入姓名：");
	scanf("%s", stct_cont->data[stct_cont->size].name);//name为数组，因此不需要加&
	printf("请输入电话：");
	scanf("%d", &(stct_cont->data[stct_cont->size].tel));//tel为整型，因此需要加&
	printf("请输入性别：");
	scanf("%s", stct_cont->data[stct_cont->size].sex);
	printf("请输入年龄：");
	scanf("%d", &(stct_cont->data[stct_cont->size].age));
	printf("请输入地址：");
	scanf("%s", stct_cont->data[stct_cont->size].addr);
	
	stct_cont->size++;
	printf("\n添加联系人成功...\n");
}


//显示通讯录内容-功能函数
void ShowContact(const struct contact* stct_cont)//const修饰，避免结构体变量内容被修改
{
	int i = 0;
	
	/*打印标题*/
	printf("%-14s%-14s%-10s%-8s%-15s\n\n", "姓名", "电话", "性别", "年龄", "地址");
	
	/*打印内容信息*/
	while (i< stct_cont->size)
	{
		PrintContact_Single(stct_cont, i);
		i++;
	}
}

//查找联系人-先定位，再显示-功能函数
void FindContact(const struct contact* stct_cont)//const修饰，避免结构体变量内容被修改
{
	printf("请输入要查找的联系人姓名：");
	char name_dest[name_max];
	scanf("%s", name_dest);
	int ret=LocateConcat(stct_cont,name_dest);
	
	if (ret == 0)
		printf("未查找到该联系人\n");
	else
	{
		printf("\n该联系人信息如下：\n");
		printf("%-14s%-14s%-10s%-8s%-15s\n\n", "姓名", "电话", "性别", "年龄", "地址");
		PrintContact_Single(stct_cont, ret);
	}
}

//修改联系人-功能函数
void ModifyContact(struct contact* stct_cont)
{
	printf("请输入要修改的联系人姓名：");
	char name_dest[name_max];
	scanf("%s", name_dest);
	int ret = LocateConcat(stct_cont, name_dest);

	if (ret == 0)
		printf("未查找到该联系人\n");
	else
	{
		/*这里采用了与添加联系人时不同的方式，可对比选择*/
		printf("请依次输入更改后的联系人的姓名、电话、性别、年龄、地址，并以空格为间隔：\n");

		scanf("%s %d %s %d %s",
			stct_cont->data[ret].name,
			&(stct_cont->data[ret].tel),
			stct_cont->data[ret].sex,
			&(stct_cont->data[ret].age),
			stct_cont->data[ret].addr);
	}
}

//删除联系人-功能函数
void DeleteContact(struct contact* stct_cont)
{
	printf("请输入要删除的联系人姓名：");
	char name_dest[name_max];
	scanf("%s", name_dest);
	int ret = LocateConcat(stct_cont, name_dest);

	if (ret == 0)
		printf("未查找到该联系人\n");
	else
	{
		while (ret< stct_cont->size-1)
		{
			stct_cont->data[ret] = stct_cont->data[ret + 1];//将删除的目标之后的联系人的序号（下标）依次向前移一位
			ret++;
		}
		stct_cont->size--;//删除后size需要减1
		printf("\n删除联系人成功...\n");
	}
}

//联系人信息比较-按姓名-用于排序-非功能函数
cmp_str_name(const struct contact* e1, const struct contact* e2)
{
	return strcmp(e1->data->name, e2->data->name);
}

cmp_str_addr(const struct contact* e1, const struct contact* e2)
{
	return strcmp(e1->data->addr, e2->data->addr);
}

cmp_int_age(const struct contact* e1, const struct contact* e2)
{
	return e1->data->age - e2->data->age;
}


//对联系人排序-功能函数
void SortContact(struct contact* stct_cont)
{
	printf("\n*******************************************************\n");
	printf("************ 0 BY_NAME   1 BY_AGE   2 BY_ADDR  ********\n");
	printf("*******************************************************\n");
	
	int input_sort;
	
	printf("请根据功能选择对应的编号：");
	scanf("%d", &input_sort);
	printf("\n");
		
	//这里直接使用了qsort函数，也可以对qort重构，并将input_sort作为参数放进contact_qort中
	switch (input_sort)
	{
		case BY_NAME:
			qsort(stct_cont->data, stct_cont->size, sizeof(stct_cont->data[0]), cmp_str_name);
			break;
		case BY_AGE:
			qsort(stct_cont->data, stct_cont->size, sizeof(stct_cont->data[0]), cmp_int_age);
			break;
		case BY_ADDR:
			qsort(stct_cont->data, stct_cont->size, sizeof(stct_cont->data[0]), cmp_str_addr);
			break;
		default:
			printf("输入有误请重新进入排序功能\n");
			break;
	}
}

//释放开辟的那段用于存放联系人的内存-非功能函数
void DestroyContact(struct contact* stct_cont)
{
	free(stct_cont->data);//只有data指向的空间是新开辟的，而struct contact类型的 cont是变量，处于栈区，不需要释放
	stct_cont->data = NULL;
}
//将通讯录内容输出到文件-功能函数
void SaveContact(const struct contact* stct_cont)
{
	FILE* pWrite = fopen("contact.dat", "wb");//打开文件,选择只写二进制模式
	if (pWrite == NULL)//判断是否成功打开文件
	{
		printf("SaveContact::%s\n", strerror(errno));//用于与其他报错信息区分，更加精准判断是哪里报错
	}
	else
	{
		fwrite(stct_cont->data, sizeof(struct cont_info), stct_cont->size, pWrite);//将数据写入文件
		/*int i;
		for (i = 0; i < stct_cont->size; i++)
		{
			fwrite(stct_cont->data, sizeof(struct cont_info), 1, pWrite);
		}*/
		printf("保存到文件成功...\n");
	}
	fclose(pWrite);
	pWrite = NULL;
}
