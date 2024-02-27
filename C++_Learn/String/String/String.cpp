#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

using namespace wxy;

//����
void String::ApplyCapacity()
{
	_capacity *= 2;
	char* pTemp = new char[_capacity+1];
	strcpy(pTemp,_pStr);
	delete _pStr;
	_pStr = pTemp;
}

//���캯��
String::String(const char* pStr)
{
	if (pStr == nullptr)//�������ݿ�ָ��
	{
		assert(false);//��ʾ�������λ��
		return;
	}
	else
	{
		_size = strlen(pStr);
		_capacity = DEFAULT_CAPACITY;//Ĭ�ϵĳ�ʼ��ʾ�ռ�
		while (_capacity < _size)//�жϳ�ʼ�ռ��Ƿ�����Ҫ��
		{
			_capacity *= 2;
		}

		_pStr = new char[_capacity + 1];//����ҪԤ��һ����\0
		strcpy(_pStr, pStr);//���β�ָ��ָ������ݿ���������
	}
}

//��������
String::String(const String& str)
{
	_size = str._size;
	_capacity = str._capacity;
	_pStr = new char[_capacity + 1];//ע�����ﲻ�ܽ�������ָ��ֵ��Ӧ�ð��������˼·�����¿����ڴ�ռ�
	strcpy(_pStr, str._pStr);//���β�ָ��ָ������ݿ���������
}

// = ���أ�C-String
String& String::operator=(const char* pStr)
{
	int len = strlen(pStr);
	if (len > _capacity)
		Reserve(len);
	_size = len;
	strcpy(_pStr, pStr);

	return *this;
}


// = ���أ�String����
String& String::operator=(String& str)
{
	_size = str._size;
	_capacity = str._capacity;
	_pStr = new char[_capacity + 1];
	strcpy(_pStr, str._pStr);

	return *this;
}

//����sizeֵ
const size_t String::Size()const
{
	return _size;
}

//����_capacityֵ
const size_t String::Capacity()const
{
	return _capacity;
}

//�Ƿ�Ϊ�գ��գ�true  �ǿգ�false
bool String::Empty()const
{
	return _size == 0;
}

//�ض�Ϊn �� ��n���Ϊ\0
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

//�ض�Ϊn �� ��n���Ϊch
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

//������n
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

//����������[],�ɶ���д
char& String::operator[](size_t pos)//��������ֵ���޸�
{
	return *(_pStr + pos);
}

//[]����,ֻ��(���ַ�����const����ʱ)
const char& String::operator[](size_t pos)const
{
	return *(_pStr + pos);
}

//ָ���ַ�����һ���ַ��ĵ�����
Iterator String::Begin()
{
	return _pStr;
}

//ָ���ַ������һ���ַ�������ڴ�
Iterator String::End()
{
	return (_pStr + _size);
}

//β���ַ�
void String::PushBack(char ch)
{
	//���ַ���
	if(_size == 0)
	{
		(*this)[_size] = ch;
		++_size;
	}

	//�ǿ��ַ���
	else
	{
		if (_size == _capacity)
			ApplyCapacity();
		(*this)[_size] = ch;
		++_size;
	}
	(*this)[_size] = '\0';
}

//β��C-string
void String::Append(const char* pStr)
{
	for (int i =0;i<strlen(pStr);++i)
	{
		PushBack(pStr[i]);
	}
}

//β��String����
void String::Append(const String& str)
{
	Append(str._pStr);
}

//+=����(�ַ�)
void String::operator+=(const char ch)
{
		PushBack(ch);
}

//+=����(C�ַ���)
void String::operator+=(const char* pStr)
{
	for (int i = 0; i < strlen(pStr); ++i)
	{
		(*this).PushBack(pStr[i]);
	}
}

//+=����(String����)
void String::operator+=(const String& str)
{
	Append(str._pStr);
}

//ָ��λ�ò����ַ�
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

//ָ��λ�ò���C�ַ���
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

//��ָ��λ�ò���String����
String& String::Insert(size_t pos, const String& str)
{
	return Insert(pos,str._pStr);
}

//��posλ�ÿ�ʼ������pos�������ɾ��len���ַ�
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

//����һ��ָ����ͬ���ݵ�C���ַ�����ָ��
const char* String::CStr()const
{
	char* pStr = new char[_size];
	strcpy(pStr,_pStr);
	return pStr;
}

//��posλ�ÿ�ʼƥ���ַ�ch�����ص�һ��ƥ���λ��
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

//��posλ�ÿ�ʼƥ��C�ַ���pStr�����ص�һ��ƥ��������ַ���λ��
size_t String::Find(char* pStr, size_t pos)
{
	assert(pos < _size);
	char* flag = strstr(_pStr, pStr);
	if (flag == NULL || flag == _pStr)
		return Npos;
	else
		return (size_t)(flag - _pStr);
}

//��posλ�ÿ�ʼƥ���ַ�String����Str�����ص�һ��ƥ��������ַ���λ��
size_t String::Find(String str, size_t pos)
{
	return Find(str._pStr, pos);
}

//>���أ�C-String
bool String::operator>(const char*pStr)const
{
	return strcmp(_pStr,pStr) > 0;
}

//=���أ�C-String
bool  String::operator == (const char* pStr)const
{
	return strcmp(_pStr,pStr) == 0;
}

//>=���أ�C-String
bool  String::operator >= (const char* pStr)const
{
	return strcmp(_pStr, pStr) >= 0;
}

//<���أ�C-String
bool  String::operator < (const char* pStr)const
{
	return strcmp(_pStr, pStr) < 0;
}

//<=���أ�C-String
bool  String::operator <= (const char* pStr)const
{
	return strcmp(_pStr, pStr) <= 0;
}

//>���أ�String����
bool String::operator>(const String& str)const
{
	return strcmp(_pStr, str._pStr) > 0;
}

//=���أ�String����
bool  String::operator == (const String& str)const
{
	return strcmp(_pStr, str._pStr) == 0;
}

//>=���أ�String����
bool  String::operator >= (const String& str)const
{
	return strcmp(_pStr, str._pStr) >= 0;
}

//<���أ�String����
bool  String::operator < (const String& str)const
{
	return strcmp(_pStr, str._pStr) < 0;
}

//<=���أ�String����
bool  String::operator <= (const String& str)const
{
	return strcmp(_pStr, str._pStr) <= 0;
}

// <<���أ�C-String
ostream& operator<<(ostream& os, const wxy::String& str)
{
	for (int i = 0; i < str.Size(); ++i)
	{
		os << str[i];
	}
	return os;
}

//// >> ����
//std::istream& operator>>(std::istream& is, String& str)
//{
//	for (int i = 0; i < str.Size(); ++i)
//	{
//		std::cin >> str[i];
//	}
//}

//����
String::~String()
{
	delete _pStr;
	_pStr = nullptr;
	_size = 0;
	_capacity = 0;
}