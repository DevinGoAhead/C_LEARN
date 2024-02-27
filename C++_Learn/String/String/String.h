#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

const int DEFAULT_CAPACITY = 5;
const size_t Npos = -1;
typedef char* Iterator;//��ʱ��Ϊ��������ָ��������ͬ

namespace wxy
{
	class String
	{
	public:
		void ApplyCapacity();//����

		String(const char* pStr = "");//���캯��
		String(const String& str);//��������

		String& operator=(const char* pStr);// = ���أ�C-String
		String& operator=(String& str);// = ���أ�String ����
		
		const size_t Size()const;//����_sizeֵ
		const size_t Capacity()const;//����_capacityֵ
		bool Empty()const;//�ж��Ƿ�Ϊ��
		void ReSize(size_t n);//�ض�Ϊn �� ��n���Ϊ\0
		void ReSize(size_t n,char ch);//�ض�Ϊn �� ��n���Ϊ�ַ�ch
		void Reserve(size_t n);//������n

		char& operator[](size_t pos);//[]����,�ɶ���д
		const char& operator[](size_t pos)const;//[]����,ֻ��

		Iterator Begin();//ָ���ַ�����һ���ַ��ĵ�����
		Iterator End();//ָ���ַ������һ���ַ�������ڴ�

		void PushBack(char ch);//β���ַ�
		void Append(const char* pStr);//β��C-string
		void Append(const String& str);//β���ַ���
		void operator+=(const char ch);//+=���ַ���
		void operator+=(const char* pStr);//+=����(C�ַ���)
		void operator+=(const String& str);//+=����(String����)
		String& Insert(size_t pos, const char ch);//ָ��λ�ò����ַ�
		String& Insert(size_t pos, const char* pStr);//ָ��λ�ò���C�ַ���
		String& Insert(size_t pos, const String& str);//��ָ��λ�ò���String����
		void Erase(size_t pos = 0, size_t len = Npos);//��posλ�ÿ�ʼ������pos�������ɾ��len���ַ�
		
		const char* CStr()const;//����һ��ָ����ͬ���ݵ�C���ַ�����ָ��
		size_t Find(char ch, size_t pos = 0);//��posλ�ÿ�ʼƥ���ַ�ch�����ص�һ��ƥ���λ��
		size_t Find(char* pStr, size_t pos = 0);//��posλ�ÿ�ʼƥ��C�ַ���pStr�����ص�һ��ƥ��������ַ���λ��
		size_t Find(String str, size_t pos = 0);//��posλ�ÿ�ʼƥ���ַ�String����str�����ص�һ��ƥ��������ַ���λ��

		
		bool operator > (const char* pStr)const;//>���أ�C-String
		bool operator == (const char* pStr)const;//=���أ�C-String
		bool operator >= (const char* pStr)const;//>=���أ�C-String
		bool operator < (const char* pStr)const;//<���أ�C-String
		bool operator <= (const char* pStr)const;//<=���أ�C-String

		bool operator > (const String& str)const;//>���أ�String����
		bool operator == (const String& str)const;//=���أ�String����
		bool operator >= (const String& str)const;//>=���أ�String����
		bool operator < (const String& str)const;//<���أ�String����
		bool operator <= (const String& str)const;//<=���أ�String����

		~String();//����

	private:
		char* _pStr;
		int _size;
		int _capacity;
	};
}

/*�ǳ�Ա����*/
ostream& operator<<(ostream& os, const wxy::String& str);// << ����
//std::istream& operator>>(std::istream& is, wxy::String& str);// >> ����

