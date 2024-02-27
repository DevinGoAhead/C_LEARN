#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

//һЩ�����ض���
#define name_max 10//������Ϣ���������ַ�����
#define sex_max 8//�Ա���Ϣ���������ַ�����
#define addr_max 30//��ַ��Ϣ���������ַ�����
//#define cont_max 6//ͨѶ¼��������ϵ�˵��������-�Ż�֮ǰ
#define capcty_initial 3//ͨѶ¼��ʼ�����ܹ�������ϵ�˵�����-��һ���Ż�

//��ͨѶ¼���ܱ�Ŷ���Ϊö������,���Ӵ���ɶ���
enum OptionContact
{
	EXIST,
	ADD,
	MODIFY,
	DELETE,
	FIND,
	SORT,
	SAVE,//�ڶ����Ż����뱣�湦��
	SHOW
};


//��ͨѶ¼�����ܱ�Ŷ���Ϊö������,���Ӵ���ɶ���
enum OptionContactSort
{
	BY_NAME,
	BY_AGE,
	BY_ADDR
};

//����ṹ������-��ϵ��
struct cont_info
{
	char name[name_max];
	int tel;
	char sex[sex_max];
	int age;
	char addr[addr_max];
};

////����ṹ������-ͨѶ¼-�Ż�֮ǰ
//struct contact
//{
//	struct cont_info data[cont_max];// �������˱�����struct contact���͵�������* /
//	struct cont_info* data;
//	int size;//��ǰ�ѱ������ϵ�˵�����
//};

//����ṹ������ - ͨѶ¼-��һ���Ż�
struct contact
{
	struct cont_info* data;//ָ��struct cont_info���ݵ�ָ�룬���潫�Ե���struct cont_infoΪ��λ��������
	int capacity;//��ǰͨѶ¼������
	int size;//��ǰ�ѱ������ϵ�˵�����
};

//��������
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