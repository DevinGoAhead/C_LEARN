#pragma once

#include<iostream>

class Date
{
public:
	int& GetMonthDay(const int& year, const int& month);//��ȡ��Ӧ�·ݵĺϷ�����
	Date(const int year = 1970, const int month = 1, const int day = 1);//���캯��
	Date(const Date& date);//�������캯��
	Date* operator&();
	const Date* operator&()const;

	//��ֵ����������
	Date& operator = (const Date& right);//(=)
	Date& operator ++ ();//(ǰ��++)
	Date& operator -- ();//(ǰ��--)
	Date operator ++ (int);//(����++)
	Date operator -- (int);//(����--)
	Date& operator += (const int n);//(+=)
	Date& operator -= (const int n);//(-=)
	Date operator + (const int n)const;//(+)
	Date operator - (const int n)const;//(-)
	int operator - (const Date& right)const;//(left-right)

	//��ϵ����������
	bool operator<(const Date& right)const;//(< )
	bool operator==(const Date& right)const;//(==)
	bool operator!=(const Date& right)const;//(!=)
	bool operator> (const Date& right)const;//(>)
	
	//��ӡ
	void DatePrint()const;

private:
	int _year;
	int _month;
	int _day;
};
