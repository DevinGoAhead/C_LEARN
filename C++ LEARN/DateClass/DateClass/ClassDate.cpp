#include"ClassDate.h"

//获取月份的合法天数
int& Date::GetMonthDay(const int& year, const int& month)
{
	int Day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0)//if (year % 4 == 0 || year % 400 == 0 && year % 100 != 0)对4和400的判断要括号起来
		Day[2] = 29;//闰年29天
	return Day[month];
}

//构造函数
Date::Date(const int year, const int month, const int day)//缺省参数在声明给就可以了
{
	if (year >= 0 && 
	   (month <= 12 && month > 0) &&
	   day <= GetMonthDay(year,month) && day>0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Illegal Date" << endl;
		exit(-1);
	}

}

//拷贝构造函数
Date::Date(const Date &src)
{
	_year = src._year;
	_month = src._month;
	_day = src._day;
}

//取地址重载
Date* Date::operator&()
{
	//cout << "Date* Date::operator&()" << endl;//用于测试是否被调用
	return this;
}

//取地址重载const
const Date* Date::operator&()const
{
	//cout << "const Date* Date::operator&()" << endl;//用于测试是否被调用
	return this;
}

//赋值操作符重载(=)
Date& Date::operator = (const Date& right)
{
	if(this != &right)//检查是否是自己给自己赋值
	{
		_year = right._year;
		_month = right._month;
		_day = right._day;
		return *this;
	}
}

//赋值操作重载（前置++）
Date& Date::operator ++ ()
{
	//这里也可以直接调用+=1
	if (++_day > GetMonthDay(_year, _month))//判断++_day是否非法，如果非法应向_month进位
	{
		_day = 1;//进位后_day应为1
		if (++_month > 12)//判断_month被进位后是否非法，如果非法应向_year进位
		{
			_month = 1;//进位后_month应为1
			++_year;
		}
	}
	return *this;
}

//赋值操作重载（前置--）
Date& Date::operator -- ()
{
	//这里也可以直接调用-=1
	if (--_day ==0)//判断--_day是否非法，如果非法应从_month借位
	{
		if (--_month == 0)//判断_month被借位后是否非法，如果非法应从_year借位
		{
			_month = 1;//_month借位后应为1
			if (--_year < 0)//判断_year被借位后是否非法，如果非法应报错退出
			{
				cout << "Illegal Date"<<endl;
				exit(-1);
			}
		}
		_day = GetMonthDay(_year, _month);//只要能运行到这里，_month及_year都是经过计算且合法的,_day借位后应为1
	}
	return *this;
}

//赋值操作符重载(后置++)
Date Date::operator ++ (int)//ret是在函数内部定义的，离开函数后ret将被回收，因此不能使用引用返回
{
	Date ret=*this;//使用拷贝this的方式创建临时Date类
	++*this;//调用前置++自增,这里也可以直接调用+=1
	return ret;//返回未自增之前的Date类
}

//赋值操作符重载(后置--)
Date Date::operator -- (int)//ret是在函数内部定义的，离开函数后ret将被回收，因此不能使用引用返回
{
	Date ret=*this;//使用拷贝this的方式创建临时Date类
	--*this;//调用前置--自减,这里也可以直接调用-=1
	return ret;//返回未自减之前的Date类
}

//赋值操作符重载(+=)
Date& Date::operator += (const int n)
{
	if (n < 0)
	{
		*this -= -n;//如果+=一个负值
		return *this;
	}
	_day += n;
	while (_day > GetMonthDay(_year, _month))//判断_day是否非法
	{
		_day -= GetMonthDay(_year, _month);//一次一次按月减去，直到_day合法
		if (++_month > 12)//判断_month被进位后是否非法，如果非法应向_year进位
		{
			_month = 1;//进位后_month应为1
			++_year;
		}
	}
	return *this;
}

//赋值操作符重载(-=)
Date& Date::operator -= (const int n)
{
	if (n < 0)
	{
		*this += -n;//如果+=一个负值
		return *this;
	}
	_day -= n;
	while (_day <= 0)//判断_day是否非法
	{
		_day += GetMonthDay(_year, _month);//一次一次向月借位，直到_day合法
		if (--_month == 0)//判断_month被借位后是否非法，如果非法应从_year借位
		{
			_month = 12;//_month借位后应为1
			if (--_year < 0)//判断_year被借位后是否非法，如果非法应报错退出
			{
				cout << "Illegal Date" << endl;
				exit(-1);
			}
		}
	}
	return *this;
}

//赋值操作符重载(+)
Date Date::operator + (const int n)const//ret是在函数内部定义的，离开函数后ret将被回收，因此不能使用引用返回
{
	Date ret = *this;//this不能发生改变
	ret += n;//调用+=重载
	return ret;
}

//赋值操作符重载(-)
Date Date::operator - (int n)const //ret是在函数内部定义的，离开函数后ret将被回收，因此不能使用引用返回
{
	Date ret = *this;//this不能发生改变
	ret -= n;//调用-=重载
	return ret;
}

//赋值操作符重载(left-right)
/*如果按照常规思路使用两个日期直接相减，将会面临判断月或年是否闰年的复杂问题，下面将采用反向的一种思路*/
int Date::operator - (const Date& right)const
{
	Date dateMax(*this);//假设this大
	Date dateMin(right);//假设right小
	int flag = 1;//用于判断最终的差值的正负
	if (*this < right)//判断假设是否成立
	{
		dateMax=right;
		dateMin=*this;
		flag = -1;
	}
	
	int day = 0;
	while (dateMin < dateMax)
	{
		++dateMin;
		++day;
	}
	return day * flag;
}

//关系操作符重载(<)
bool Date::operator<(const Date& right)const
{
	if (_year > right._year)
		return false;
	else if (_year == right._year &&
		_month > right._month)
		return false;
	else if (_year == right._year &&
		_month == right._month &&
		_day > right._day)
		return false;
	else
		return true;
}

//关系操作符重载(==)
bool Date::operator==(const Date& right)const
{
	if (_year == right._year &&
		_month == right._month &&
		_day == right._day)
		return true;
	else
		return false;
}

//关系操作符重载(!=)
bool Date::operator!=(const Date& right)const
{
	return !operator==(right);
}

//关系操作符重载(>)
bool Date::operator>(const Date& right)const
{
	return !(operator==(right) || operator<(right));
}

//打印
void Date::DatePrint()const
{
	cout << _year << "-"<<_month <<"-" <<_day << endl;
}