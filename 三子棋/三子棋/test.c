#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("**********************************************************\n");
	printf("********1.进入游戏**********************0.退出游戏********\n");
	printf("**********************************************************\n\n\n\n");


}

void game()
{
	char arr[ROW][COL] = { 0 };
	char ret;
	InitializationBoard(arr, ROW, COL);
	DisplayBoard(arr, ROW, COL);
	while(1)
	{
		ComputerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		ret=isWin(arr, ROW, COL);
		if (ret != 'C')
			break;
		PlayerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		ret = isWin(arr, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '#')
		printf("玩家赢！\n");
	else if (ret == '*')
		printf("电脑赢！\n");
	else
		printf("平局！\n");
}
 
int main()
{
	int input = 1;
	
	do
	{
		menu();
		printf("\n请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("游戏开始\n");
			srand((unsigned int)time(NULL));
			game();
			break;
		default:
			printf("输入有误\n");
			break;
		}
	} while (input);

	return 0;
}