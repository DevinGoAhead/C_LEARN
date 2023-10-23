#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitializationBoard(char arr[][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void DisplayBoard(char arr[][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		/*��ӡ������*/
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < COL - 1)
				printf("|");//���һ�в���ӡ������
		}
		printf("\n");
		/*��ӡ�ָ���*/
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				if (j < COL - 1)
					printf("������|");
				else
					printf("������");//���һ�У�����ӡ������
			}
			printf("\n");
		}
	}
}

void PlayerMove(char arr[][COL], int row, int col)
{
	printf("������1~%d֮������֣����磬����1 3��ʾ�ڵ�һ�е����е�λ��������\n",ROW);
	int Pinput_x = 0, Pinput_y = 0;
	while(1)
	{
		printf("\n�������>:");
		scanf("%d%d", &Pinput_x, &Pinput_y);
		if (Pinput_x > row || Pinput_y > col)
			printf(" ������������������>:\n");
		else
		{
			if (arr[Pinput_x-1][Pinput_y-1] != ' ')
				printf(" ��λ���ѱ�ռ�ã�����������>\n:");
			else
			{
				arr[Pinput_x-1][Pinput_y-1] = '#';
				break;
			}
		}
	}
}

void ComputerMove(char arr[][COL], int row, int col)
{
	printf("\n��������>:\n");
	/*arr[0][1] = '*';*/
	while(1)
	{
		int Cinput_x = rand() % ROW;
		int Cinput_y = rand() % COL;
		if (arr[Cinput_x][Cinput_y] == ' ')
		{
			arr[Cinput_x][Cinput_y] = '*';
			break;
		}
	}
}

int isFull(char arr[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] ==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char isWin(char arr[][COL], int row, int col)
{
	int i, j;

	/*���ж�*/
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if (arr[i][j] != arr[i][j + 1])
			{
				break;
			}
			if (j == col-2 && arr[i][j] != ' ')
			{
				return arr[i][j];
			}
		}
	}

	/*���ж�*/
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row - 1; j++)
		{
			if (arr[j][i] != arr[j+1][i])
			{
				break;
			}
			if (j == row-2 && arr[i][j] != ' ')
			{
				return arr[j][i];
			}
		}
	}

	/*�Խ����ж�1*/
	for (i = 0; i < row-1; i++)
	{
		if (arr[i][i] != arr[i+1][i+1])
		{
			break;
		}
		if (i == row-2 && arr[i][i] != ' ')
		{
			return arr[i][i];
		}
	}

	/*�Խ����ж�2*/
	for (i = row-1; i > 0; i--)
	{
		j = row-1-i;
		if (arr[i][j] != arr[i - 1][j + 1])
		{
			break;
		}
		if (i == 1 && arr[i][j] != ' ')
		{
			return arr[i][j];
		}
	}

	/*�ж�ƽ��*/
	if (isFull(arr,row,col) == 2)
		return 'Q';
	else
		return 'C';
}
