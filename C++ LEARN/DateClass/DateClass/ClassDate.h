#pragma once

#include<iostream>

class Date
{
public:
	int& GetMonthDay(const int& year, const int& month);//获取对应月份的合法天数
	Date(const int year = 1970, const int month = 1, const int day = 1);//构造函数
	Date(const Date& date);//拷贝构造函数
	Date* operator&();
	const Date* operator&()const;

	//赋值操作符重载
	Date& operator = (const Date& right);//(=)
	Date& operator ++ ();//(前置++)
	Date& operator -- ();//(前置--)
	Date operator ++ (int);//(后置++)
	Date operator -- (int);//(后置--)
	Date& operator += (const int n);//(+=)
	Date& operator -= (const int n);//(-=)
	Date operator + (const int n)const;//(+)
	Date operator - (const int n)const;//(-)
	int operator - (const Date& right)const;//(left-right)

	//关系操作符重载
	bool operator<(const Date& right)const;//(< )
	bool operator==(const Date& right)const;//(==)
	bool operator!=(const Date& right)const;//(!=)
	bool operator> (const Date& right)const;//(>)
	
	//打印
	void DatePrint()const;

private:
	int _year;
	int _month;
	int _day;
};
