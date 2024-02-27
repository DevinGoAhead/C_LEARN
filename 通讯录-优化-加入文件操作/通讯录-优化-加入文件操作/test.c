#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"
//�˵�����
void menu()
{
	printf("\n*******************************************************\n");
	printf("***************   1 ADD       2 MODIFY  ***************\n");
	printf("***************   3 DELETE    4 FIND    ***************\n");
	printf("***************   5 SORT      6 SAVE    ***************\n");
	printf("***************   7 SHOW      0 EXIST   ***************\n");
	printf("*******************************************************\n");
}

int main()
{
	struct contact cont;//����ͨѶ¼�ṹ�����
	//memset(&cont, 0, sizeof(cont));//��ʼ��ͨѶ¼�ṹ�����-�Ż�֮ǰ
	InitializeContact(&cont);//��ʼ��ͨѶ¼-��һ���Ż�
	
	int input = 0;
	
	do
	{
		menu();//���ù��ܲ˵�����
		
		/*��ʾ�û����룬ѡ����*/
		printf("����ݹ���ѡ���Ӧ�ı�ţ�");
		scanf("%d", &input);
		printf("\n");
		
		/*�ж��û������ţ��������Ӧ�Ĺ���*/
		switch (input)
		{
		case EXIST:
			SaveContact(&cont);//�˳��Զ�����-�ڶ����Ż�
			DestroyContact(&cont);//�ͷ��ڴ�-��һ���Ż�
			printf("�˳���Ϸ...\n");
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
		case SAVE:
			SaveContact(&cont);
			break;
		case SHOW:
			ShowContact(&cont);
			break;
		default:
			printf("������������������\n");
			break;
		}
	} while (input);

	return 0;
}