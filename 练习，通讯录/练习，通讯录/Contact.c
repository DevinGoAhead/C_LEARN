#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//ֻ��λ������ʾ���������ڶ�λ��ϵ�˺�����๦�ܶ���Ҫ�õ�����˵����������ΪLocateConcat-�ǹ��ܺ���
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

//��ӡ������ϵ��-�ǹ��ܺ���
PrintContact_Single(const struct contact* stct_cont,int i)
{
	printf("%-14s", stct_cont->data[i].name);
	printf("%-14d", stct_cont->data[i].tel);
	printf("%-10s", stct_cont->data[i].sex);
	printf("%-8d", stct_cont->data[i].age);
	printf("%-15s", stct_cont->data[i].addr);
	printf("\n");
}

//�����ϵ��-���ܺ���
void AddContact(struct contact* stct_cont)
{
	if (cont_max == stct_cont->size)
		printf("ͨѶ¼�������޷��������");
	else
	{
		printf("������������");
		scanf("%s", stct_cont->data[stct_cont->size].name);//nameΪ���飬��˲���Ҫ��&
		printf("������绰��");
		scanf("%d", &(stct_cont->data[stct_cont->size].tel));//telΪ���ͣ������Ҫ��&
		printf("�������Ա�");
		scanf("%s", stct_cont->data[stct_cont->size].sex);
		printf("���������䣺");
		scanf("%d", &(stct_cont->data[stct_cont->size].age));
		printf("�������ַ��");
		scanf("%s", stct_cont->data[stct_cont->size].addr);
		stct_cont->size++;

		printf("\n�����ϵ�˳ɹ�...\n");
	}

}

//��ʾͨѶ¼����-���ܺ���
void ShowContact(const struct contact* stct_cont)//const���Σ�����ṹ��������ݱ��޸�
{
	int i = 0;
	
	/*��ӡ����*/
	printf("%-14s%-14s%-10s%-8s%-15s\n\n", "����", "�绰", "�Ա�", "����", "��ַ");
	
	/*��ӡ������Ϣ*/
	while (i< stct_cont->size)
	{
		PrintContact_Single(stct_cont, i);
		i++;
	}
}

//������ϵ��-�ȶ�λ������ʾ-���ܺ���
void FindContact(const struct contact* stct_cont)//const���Σ�����ṹ��������ݱ��޸�
{
	printf("������Ҫ���ҵ���ϵ��������");
	char name_dest[name_max];
	scanf("%s", name_dest);
	int ret=LocateConcat(stct_cont,name_dest);
	
	if (ret == 0)
		printf("δ���ҵ�����ϵ��\n");
	else
	{
		printf("\n����ϵ����Ϣ���£�\n");
		printf("%-14s%-14s%-10s%-8s%-15s\n\n", "����", "�绰", "�Ա�", "����", "��ַ");
		PrintContact_Single(stct_cont, ret);
	}
}

//�޸���ϵ��
void ModifyContact(struct contact* stct_cont)
{
	printf("������Ҫ�޸ĵ���ϵ��������");
	char name_dest[name_max];
	scanf("%s", name_dest);
	int ret = LocateConcat(stct_cont, name_dest);

	if (ret == 0)
		printf("δ���ҵ�����ϵ��\n");
	else
	{
		/*����������������ϵ��ʱ��ͬ�ķ�ʽ���ɶԱ�ѡ��*/
		printf("������������ĺ����ϵ�˵��������绰���Ա����䡢��ַ�����Կո�Ϊ�����\n");

		scanf("%s %d %s %d %s",
			stct_cont->data[ret].name,
			&(stct_cont->data[ret].tel),
			stct_cont->data[ret].sex,
			&(stct_cont->data[ret].age),
			stct_cont->data[ret].addr);
	}
}

//ɾ����ϵ��
void DeleteContact(struct contact* stct_cont)
{
	printf("������Ҫɾ������ϵ��������");
	char name_dest[name_max];
	scanf("%s", name_dest);
	int ret = LocateConcat(stct_cont, name_dest);

	if (ret == 0)
		printf("δ���ҵ�����ϵ��\n");
	else
	{
		while (ret< stct_cont->size-1)
		{
			stct_cont->data[ret] = stct_cont->data[ret + 1];//��ɾ����Ŀ��֮�����ϵ�˵���ţ��±꣩������ǰ��һλ
			ret++;
		}
		stct_cont->size--;//ɾ����size��Ҫ��1
		printf("\nɾ����ϵ�˳ɹ�...\n");
	}
}

//��ϵ����Ϣ�Ƚ�-������-��������-�ǹ��ܺ���
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


//����ϵ������-���ܺ���
void SortContact(struct contact* stct_cont)
{
	printf("\n*******************************************************\n");
	printf("************ 0 BY_NAME   1 BY_AGE   2 BY_ADDR  ********\n");
	printf("*******************************************************\n");
	
	int input_sort;
	
	printf("����ݹ���ѡ���Ӧ�ı�ţ�");
	scanf("%d", &input_sort);
	printf("\n");
		
	//����ֱ��ʹ����qsort������Ҳ���Զ�qort�ع�������input_sort��Ϊ�����Ž�contact_qort��
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
			printf("�������������½���������\n");
			break;
	}
}