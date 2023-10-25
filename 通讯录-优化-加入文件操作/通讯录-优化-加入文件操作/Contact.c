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
void PrintContact_Single(const struct contact* stct_cont,int i)
{
	printf("%-14s", stct_cont->data[i].name);
	printf("%-14d", stct_cont->data[i].tel);
	printf("%-10s", stct_cont->data[i].sex);
	printf("%-8d", stct_cont->data[i].age);
	printf("%-15s", stct_cont->data[i].addr);
	printf("\n");
}

////��ʼ��ͨѶ¼-���ܺ���-��һ���Ż�
//void InitializeContact(struct contact* stct_cont)
//{
//	stct_cont->data = malloc(capcty_initial * sizeof(struct cont_info));// capcty_initial==3��dataָ����¿��ٵ��ڴ��ܱ���3����ϵ��
//	stct_cont->capacity = capcty_initial;
//	stct_cont->size = 0;
//}

//�����ļ�����-�ǹ��ܺ���-����InitializeContact-�ڶ����Ż�
void LoadContact(struct contact* stct_cont)
{
	FILE* pRead = fopen("contact.dat", "rb");
	if (pRead == NULL)//�ж��Ƿ�ɹ����ļ�
	{
		printf("LoadContact::%s\n", strerror(errno));//����������������Ϣ���֣����Ӿ�׼�ж������ﱨ��
	}
	else
	{
		struct cont_info temp;//������ʱ�������洢��������ϵ��
		while (fread(&temp, sizeof(struct cont_info), 1, pRead))//һ�ζ���һ��������ʧ�ܼ��ѽ���Ϣ��ȫ����
		{
			CheckCapacity(stct_cont);//�жϿռ������Ƿ��㹻��������Ҫ�����µĿռ�
			stct_cont->data[stct_cont->size] = temp;
			stct_cont->size++;
		}
	}
	fclose(pRead);
	pRead = NULL;
}

//��ʼ��ͨѶ¼-���ܺ���-�ڶ����Ż�
void InitializeContact(struct contact* stct_cont)
{
	stct_cont->data = malloc(capcty_initial * sizeof(struct cont_info));// capcty_initial==3��dataָ����¿��ٵ��ڴ��ܱ���3����ϵ��
	stct_cont->capacity = capcty_initial;
	stct_cont->size = 0;
	LoadContact(stct_cont);
}


////�����ϵ��-���ܺ���-�Ż�֮ǰ
//void AddContact(struct contact* stct_cont)
//{
//	if (cont_max == stct_cont->size)
//		printf("ͨѶ¼�������޷��������");
//	else
//	{
//		printf("������������");
//		scanf("%s", stct_cont->data[stct_cont->size].name);//nameΪ���飬��˲���Ҫ��&
//		printf("������绰��");
//		scanf("%d", &(stct_cont->data[stct_cont->size].tel));//telΪ���ͣ������Ҫ��&
//		printf("�������Ա�");
//		scanf("%s", stct_cont->data[stct_cont->size].sex);
//		printf("���������䣺");
//		scanf("%d", &(stct_cont->data[stct_cont->size].age));
//		printf("�������ַ��");
//		scanf("%s", stct_cont->data[stct_cont->size].addr);
//		stct_cont->size++;
//
//		printf("\n�����ϵ�˳ɹ�...\n");
//	}
//}

//�ж�ͨѶ¼����������-�ǹ��ܺ���-����AddContact-��һ���Ż�
void CheckCapacity(struct contact* stct_cont)
{
	if (stct_cont->capacity == stct_cont->size)
	{
		printf("ͨѶ¼���������Զ���������...\n");
		printf("......\n");
		struct cont_info* data2 = realloc(stct_cont->data, (stct_cont->capacity + 2) * sizeof(struct cont_info));//stct_cont->capacity + 2 ����2��
		if (data2 == NULL)//�жϿ��ٿռ��Ƿ�ɹ�
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			stct_cont->data = data2;//��Ȼʹ�ó�ʼָ��ά���¿��ٵĿռ�
			stct_cont->capacity +=2;
			printf("���ݳɹ�...\n\n");
		}
	}
}

//�����ϵ��-���ܺ���-��һ���Ż�
void AddContact(struct contact* stct_cont)
{
	CheckCapacity(stct_cont);

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

//�޸���ϵ��-���ܺ���
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

//ɾ����ϵ��-���ܺ���
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

//�ͷſ��ٵ��Ƕ����ڴ����ϵ�˵��ڴ�-�ǹ��ܺ���
void DestroyContact(struct contact* stct_cont)
{
	free(stct_cont->data);//ֻ��dataָ��Ŀռ����¿��ٵģ���struct contact���͵� cont�Ǳ���������ջ��������Ҫ�ͷ�
	stct_cont->data = NULL;
}
//��ͨѶ¼����������ļ�-���ܺ���
void SaveContact(const struct contact* stct_cont)
{
	FILE* pWrite = fopen("contact.dat", "wb");//���ļ�,ѡ��ֻд������ģʽ
	if (pWrite == NULL)//�ж��Ƿ�ɹ����ļ�
	{
		printf("SaveContact::%s\n", strerror(errno));//����������������Ϣ���֣����Ӿ�׼�ж������ﱨ��
	}
	else
	{
		fwrite(stct_cont->data, sizeof(struct cont_info), stct_cont->size, pWrite);//������д���ļ�
		/*int i;
		for (i = 0; i < stct_cont->size; i++)
		{
			fwrite(stct_cont->data, sizeof(struct cont_info), 1, pWrite);
		}*/
		printf("���浽�ļ��ɹ�...\n");
	}
	fclose(pWrite);
	pWrite = NULL;
}
