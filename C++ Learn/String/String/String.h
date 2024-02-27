#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

const int DEFAULT_CAPACITY = 5;
const size_t Npos = -1;
typedef char* Iterator;//暂时认为迭代器与指针性质相同

namespace wxy
{
	class String
	{
	public:
		void ApplyCapacity();//扩容

		String(const char* pStr = "");//构造函数
		String(const String& str);//拷贝构造

		String& operator=(const char* pStr);// = 重载，C-String
		String& operator=(String& str);// = 重载，String 对象
		
		const size_t Size()const;//返回_size值
		const size_t Capacity()const;//返回_capacity值
		bool Empty()const;//判断是否为空
		void ReSize(size_t n);//截断为n 或 至n填充为\0
		void ReSize(size_t n,char ch);//截断为n 或 至n填充为字符ch
		void Reserve(size_t n);//扩容至n

		char& operator[](size_t pos);//[]重载,可读可写
		const char& operator[](size_t pos)const;//[]重载,只读

		Iterator Begin();//指向字符串第一个字符的迭代器
		Iterator End();//指向字符串最后一个字符后面的内存

		void PushBack(char ch);//尾插字符
		void Append(const char* pStr);//尾插C-string
		void Append(const String& str);//尾插字符串
		void operator+=(const char ch);//+=（字符）
		void operator+=(const char* pStr);//+=重载(C字符串)
		void operator+=(const String& str);//+=重载(String对象)
		String& Insert(size_t pos, const char ch);//指定位置插入字符
		String& Insert(size_t pos, const char* pStr);//指定位置插入C字符串
		String& Insert(size_t pos, const String& str);//在指定位置插入String对象
		void Erase(size_t pos = 0, size_t len = Npos);//自pos位置开始（包含pos），向后删除len个字符
		
		const char* CStr()const;//返回一个指向相同内容的C型字符串的指针
		size_t Find(char ch, size_t pos = 0);//自pos位置开始匹配字符ch，返回第一个匹配的位置
		size_t Find(char* pStr, size_t pos = 0);//自pos位置开始匹配C字符串pStr，返回第一个匹配项的首字符的位置
		size_t Find(String str, size_t pos = 0);//自pos位置开始匹配字符String对象str，返回第一个匹配项的首字符的位置

		
		bool operator > (const char* pStr)const;//>重载，C-String
		bool operator == (const char* pStr)const;//=重载，C-String
		bool operator >= (const char* pStr)const;//>=重载，C-String
		bool operator < (const char* pStr)const;//<重载，C-String
		bool operator <= (const char* pStr)const;//<=重载，C-String

		bool operator > (const String& str)const;//>重载，String对象
		bool operator == (const String& str)const;//=重载，String对象
		bool operator >= (const String& str)const;//>=重载，String对象
		bool operator < (const String& str)const;//<重载，String对象
		bool operator <= (const String& str)const;//<=重载，String对象

		~String();//析构

	private:
		char* _pStr;
		int _size;
		int _capacity;
	};
}

/*非成员函数*/
ostream& operator<<(ostream& os, const wxy::String& str);// << 重载
//std::istream& operator>>(std::istream& is, wxy::String& str);// >> 重载

