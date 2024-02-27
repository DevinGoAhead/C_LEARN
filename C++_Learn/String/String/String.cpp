#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

using namespace wxy;

//扩容
void String::ApplyCapacity()
{
	_capacity *= 2;
	char* pTemp = new char[_capacity+1];
	strcpy(pTemp,_pStr);
	delete _pStr;
	_pStr = pTemp;
}

//构造函数
String::String(const char* pStr)
{
	if (pStr == nullptr)//不允许传递空指针
	{
		assert(false);//提示报错代码位置
		return;
	}
	else
	{
		_size = strlen(pStr);
		_capacity = DEFAULT_CAPACITY;//默认的初始显示空间
		while (_capacity < _size)//判断初始空间是否满足要求
		{
			_capacity *= 2;
		}

		_pStr = new char[_capacity + 1];//总是要预留一个给\0
		strcpy(_pStr, pStr);//将形参指针指向的内容拷贝到类中
	}
}

//拷贝构造
String::String(const String& str)
{
	_size = str._size;
	_capacity = str._capacity;
	_pStr = new char[_capacity + 1];//注意这里不能仅仅拷贝指针值，应该按照深拷贝的思路，重新开辟内存空间
	strcpy(_pStr, str._pStr);//将形参指针指向的内容拷贝到类中
}

// = 重载，C-String
String& String::operator=(const char* pStr)
{
	int len = strlen(pStr);
	if (len > _capacity)
		Reserve(len);
	_size = len;
	strcpy(_pStr, pStr);

	return *this;
}


// = 重载，String对象
String& String::operator=(String& str)
{
	_size = str._size;
	_capacity = str._capacity;
	_pStr = new char[_capacity + 1];
	strcpy(_pStr, str._pStr);

	return *this;
}

//返回size值
const size_t String::Size()const
{
	return _size;
}

//返回_capacity值
const size_t String::Capacity()const
{
	return _capacity;
}

//是否为空，空：true  非空：false
bool String::Empty()const
{
	return _size == 0;
}

//截断为n 或 至n填充为\0
void String::ReSize(size_t n)
{
	if(n < _size)
	{
		_size = n;
		(*this)[_size] = '\0';
	}

	while (n > _size)
	{
		(*this).PushBack('\0');
	}
}

//截断为n 或 至n填充为ch
void String::ReSize(size_t n, char ch)
{
	if (n < _size)
	{
		_size = n;
		(*this)[_size] = '\0';
	}

	while (n > _size)
	{
		(*this).PushBack(ch);
	}
}

//扩容至n
void String::Reserve(size_t n)
{
	if(n > _capacity)
	{
		_capacity = n;
		char* pTemp = new char[_capacity+1];
		strcpy(pTemp,_pStr);
		delete _pStr;
		_pStr = pTemp;
	}
}

//操作符重载[],可读可写
char& String::operator[](size_t pos)//返回引用值可修改
{
	return *(_pStr + pos);
}

//[]重载,只读(当字符串被const修饰时)
const char& String::operator[](size_t pos)const
{
	return *(_pStr + pos);
}

//指向字符串第一个字符的迭代器
Iterator String::Begin()
{
	return _pStr;
}

//指向字符串最后一个字符后面的内存
Iterator String::End()
{
	return (_pStr + _size);
}

//尾插字符
void String::PushBack(char ch)
{
	//空字符串
	if(_size == 0)
	{
		(*this)[_size] = ch;
		++_size;
	}

	//非空字符串
	else
	{
		if (_size == _capacity)
			ApplyCapacity();
		(*this)[_size] = ch;
		++_size;
	}
	(*this)[_size] = '\0';
}

//尾插C-string
void String::Append(const char* pStr)
{
	for (int i =0;i<strlen(pStr);++i)
	{
		PushBack(pStr[i]);
	}
}

//尾插String对象
void String::Append(const String& str)
{
	Append(str._pStr);
}

//+=重载(字符)
void String::operator+=(const char ch)
{
		PushBack(ch);
}

//+=重载(C字符串)
void String::operator+=(const char* pStr)
{
	for (int i = 0; i < strlen(pStr); ++i)
	{
		(*this).PushBack(pStr[i]);
	}
}

//+=重载(String对象)
void String::operator+=(const String& str)
{
	Append(str._pStr);
}

//指定位置插入字符
String& String::Insert(size_t pos, const char ch)
{
	assert(pos < _size);
	if (_size == _capacity)
		ApplyCapacity();
	for (int i = _size; i >= pos; --i)
	{
		(*this)[i+1] = (*this)[i];
	}
	++_size;
	(*this)[pos] = ch;
	return *this;
}

//指定位置插入C字符串
String& String::Insert(size_t pos, const char* pStr)
{
	assert(pos < _size);
	int len = strlen(pStr);
	int lenSum = _size - 1+len;
	if (lenSum > _capacity)
		Reserve(lenSum);
	for (int i = _size; i >= (int)pos; --i)
	{
		(*this)[i+len] = (*this)[i];
	}
	_size += len;
	strncpy((_pStr+pos),pStr,len);
	return *this;
}

//在指定位置插入String对象
String& String::Insert(size_t pos, const String& str)
{
	return Insert(pos,str._pStr);
}

//自pos位置开始（包含pos），向后删除len个字符
void String::Erase(size_t pos, size_t len)
{
	assert(pos <= _size);
	if (pos + len > _size)
	{
		_size = pos + 1;
		(*this)[pos] = '\0';
	}
	else
	{
		size_t curr = pos + len;
		while (curr < _size)
		{
			(*this)[pos] = (*this)[curr];
			++pos;
			++curr;
		}
		(*this)[curr] = '\0';
		_size = curr;
	}
}

//返回一个指向相同内容的C型字符串的指针
const char* String::CStr()const
{
	char* pStr = new char[_size];
	strcpy(pStr,_pStr);
	return pStr;
}

//自pos位置开始匹配字符ch，返回第一个匹配的位置
size_t String::Find(char ch, size_t pos)
{
	assert(pos < _size);
	for (size_t i = 0; i < _size; ++i)
	{
		if ((*this)[i] == ch)
			return  i;
	}
	return Npos;
}

//自pos位置开始匹配C字符串pStr，返回第一个匹配项的首字符的位置
size_t String::Find(char* pStr, size_t pos)
{
	assert(pos < _size);
	char* flag = strstr(_pStr, pStr);
	if (flag == NULL || flag == _pStr)
		return Npos;
	else
		return (size_t)(flag - _pStr);
}

//自pos位置开始匹配字符String对象Str，返回第一个匹配项的首字符的位置
size_t String::Find(String str, size_t pos)
{
	return Find(str._pStr, pos);
}

//>重载，C-String
bool String::operator>(const char*pStr)const
{
	return strcmp(_pStr,pStr) > 0;
}

//=重载，C-String
bool  String::operator == (const char* pStr)const
{
	return strcmp(_pStr,pStr) == 0;
}

//>=重载，C-String
bool  String::operator >= (const char* pStr)const
{
	return strcmp(_pStr, pStr) >= 0;
}

//<重载，C-String
bool  String::operator < (const char* pStr)const
{
	return strcmp(_pStr, pStr) < 0;
}

//<=重载，C-String
bool  String::operator <= (const char* pStr)const
{
	return strcmp(_pStr, pStr) <= 0;
}

//>重载，String对象
bool String::operator>(const String& str)const
{
	return strcmp(_pStr, str._pStr) > 0;
}

//=重载，String对象
bool  String::operator == (const String& str)const
{
	return strcmp(_pStr, str._pStr) == 0;
}

//>=重载，String对象
bool  String::operator >= (const String& str)const
{
	return strcmp(_pStr, str._pStr) >= 0;
}

//<重载，String对象
bool  String::operator < (const String& str)const
{
	return strcmp(_pStr, str._pStr) < 0;
}

//<=重载，String对象
bool  String::operator <= (const String& str)const
{
	return strcmp(_pStr, str._pStr) <= 0;
}

// <<重载，C-String
ostream& operator<<(ostream& os, const wxy::String& str)
{
	for (int i = 0; i < str.Size(); ++i)
	{
		os << str[i];
	}
	return os;
}

//// >> 重载
//std::istream& operator>>(std::istream& is, String& str)
//{
//	for (int i = 0; i < str.Size(); ++i)
//	{
//		std::cin >> str[i];
//	}
//}

//析构
String::~String()
{
	delete _pStr;
	_pStr = nullptr;
	_size = 0;
	_capacity = 0;
}