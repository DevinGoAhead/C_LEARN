#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

using namespace wxy;

//void test1()
//{
//	String s0;//测试无参构造函数
//	
//	char chc = 'a';
//	char ch[] = { 'a','s','d','f' };
//	char ch_0[] = { 'a','s','d','f','\0' };
//	char sch[] = "asdf";
//	//char* pch = "asdf";
//	const char* pch = "asdf";
//	String s1(ch);
//	String s2(ch);
//	String s3(ch_0);
//	String s4(sch);
//	String s5(sch);
//	//String s6("hello");
//
//	for (int i = 0; i < 5; ++i)
//	{
//		std::cout << s6[i];
//	}
//	std::cout << std::endl;
//
//}

//void test2() 
//{
//	string sss = "abcdefg";
//	sss.erase(2, 3);
//	cout << sss << endl;
//	int a = 0;
//	return;
//}

void test3()
{
	//测试构造、拷贝构造、=重载函数
	const char* con_c_str = "const C-string";
	char c_str[] = "C-string";

	String s1;
	cout << s1.Empty() << endl;
	cout << s1 << endl;;
	String s2("String");
	cout << s2.Empty() << endl;
	String s3(con_c_str);
	String s4(c_str);
	s1 = s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	//测试resize 
	s1.ReSize(2);
	cout << s1 << endl;
	s1.ReSize(0);
	cout << s1 << endl;
	s2.ReSize(10);
	cout << s2 << endl;
	s2.ReSize(3);
	cout << s2 << endl;
	s2.ReSize(9, 'a');
	cout << s2 << endl;

	//测试插入
 	s3.PushBack('p');
	cout << s3 << endl;
	s3.Append("append");
	cout << s3 << endl;
	s3 += "ABC";
	s3 += s4;
	s3 += 'D';
	cout << s3 << endl;
	//const char ch = 'W';

	s3 = "Again";
	s3.Insert(2, 'c');
	s3.Insert(4, "C-String");
	cout << s3 << endl;
	s3.Insert(0, s2); 
	cout << s3 << endl;
	s3.Erase(3,4);
	cout << s3 << endl;
	s3.Erase(0, 2);
	cout << s3 << endl;
	String s5("ain");
	cout << s3.Find('a',2) << endl;
	cout << s3.Find("Str") << endl;
	cout << s3.Find(s4,3) << endl;
	cout << (s3 > s4) << endl;
	cout << (s3 >= s4) << endl;
	cout << (s3 < s4) << endl;
	s3 = s4;
	cout << (s3 <= s4) << endl;
	cout << (s3 == s4) << endl;
}

int main()
{
	//test1();
	//test2();
	test3();
	

	return 0;
}