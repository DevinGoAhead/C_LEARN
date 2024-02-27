#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"
//菜单函数
void menu()
{
	printf("\n*******************************************************\n");
	printf("***************   1 ADD       2 MODIFY  ***************\n");
	printf("***************   3 DELETE    4 FIND    ***************\n");
	printf("***************   5 SORT      6 SHOW    ***************\n");
	printf("***************         0 EXIST         ***************\n");
	printf("*******************************************************\n");
}

int main()
{
	struct contact cont;//声明通讯录结构体变量
	/*struct contact* p = &cont;为什么不可以给结构体变量指针赋值呢*/
	memset(&cont, 0, sizeof(cont));//初始化通讯录结构体变量
	
	int input = 0;
	
	do
	{
		menu();//调用功能菜单函数
		
		/*提示用户输入，选择功能*/
		printf("请根据功能选择对应的编号：");
		scanf("%d", &input);
		printf("\n");
		
		/*判断用户输入编号，并进入对应的功能*/
		switch (input)
		{
		case EXIST:
			printf("退出游戏...\n");
			break;
		case ADD:
			AddContact(&cont);
			break;
		case MODIFY:
			ModifyContact(&cont);
			break;
		case DELETE:
			DeleteContact(&cont);
			break;
		case FIND:
			FindContact(&cont);
			break;
		case SORT:
			SortContact(&cont);
			break;
		case SHOW:
			ShowContact(&cont);
			break;
		default:
			printf("输入有误请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}