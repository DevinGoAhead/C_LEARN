#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//һЩ�����ض���
#define name_max 10//������Ϣ���������ַ�����
#define sex_max 8//�Ա���Ϣ���������ַ�����
#define addr_max 30//��ַ��Ϣ���������ַ�����
#define cont_max 6//ͨѶ¼��������ϵ�˵��������

//��ͨѶ¼���ܱ�Ŷ���Ϊö������,���Ӵ���ɶ���
enum OptionContact
{
	EXIST,
	ADD,
	MODIFY,
	DELETE,
	FIND,
	SORT,
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

//����ṹ������-ͨѶ¼
struct contact
{
	struct cont_info data[cont_max];//�������˱�����struct contact���͵�������
	int size;//��ǰ�ѱ������ϵ�˵�����
};

//��������
void AddContact(struct contact* stct_cont);
void ShowContact(const struct contact* stct_cont);
void FindContact(const struct contact* stct_cont);
void ModifyContact(struct contact* stct_cont);
void DeleteContact(struct contact* stct_cont);
void SortContact(struct contact* stct_cont);