#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("**********************************************************\n");
	printf("********1.������Ϸ**********************0.�˳���Ϸ********\n");
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
		printf("���Ӯ��\n");
	else if (ret == '*')
		printf("����Ӯ��\n");
	else
		printf("ƽ�֣�\n");
}
 
int main()
{
	int input = 1;
	
	do
	{
		menu();
		printf("\n������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			printf("��Ϸ��ʼ\n");
			srand((unsigned int)time(NULL));
			game();
			break;
		default:
			printf("��������\n");
			break;
		}
	} while (input);

	return 0;
}