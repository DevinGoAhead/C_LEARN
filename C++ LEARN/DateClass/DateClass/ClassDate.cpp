#include"ClassDate.h"

//��ȡ�·ݵĺϷ�����
int& Date::GetMonthDay(const int& year, const int& month)
{
	int Day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0)//if (year % 4 == 0 || year % 400 == 0 && year % 100 != 0)��4��400���ж�Ҫ��������
		Day[2] = 29;//����29��
	return Day[month];
}

//���캯��
Date::Date(const int year, const int month, const int day)//ȱʡ�������������Ϳ�����
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

//�������캯��
Date::Date(const Date &src)
{
	_year = src._year;
	_month = src._month;
	_day = src._day;
}

//ȡ��ַ����
Date* Date::operator&()
{
	//cout << "Date* Date::operator&()" << endl;//���ڲ����Ƿ񱻵���
	return this;
}

//ȡ��ַ����const
const Date* Date::operator&()const
{
	//cout << "const Date* Date::operator&()" << endl;//���ڲ����Ƿ񱻵���
	return this;
}

//��ֵ����������(=)
Date& Date::operator = (const Date& right)
{
	if(this != &right)//����Ƿ����Լ����Լ���ֵ
	{
		_year = right._year;
		_month = right._month;
		_day = right._day;
		return *this;
	}
}

//��ֵ�������أ�ǰ��++��
Date& Date::operator ++ ()
{
	//����Ҳ����ֱ�ӵ���+=1
	if (++_day > GetMonthDay(_year, _month))//�ж�++_day�Ƿ�Ƿ�������Ƿ�Ӧ��_month��λ
	{
		_day = 1;//��λ��_dayӦΪ1
		if (++_month > 12)//�ж�_month����λ���Ƿ�Ƿ�������Ƿ�Ӧ��_year��λ
		{
			_month = 1;//��λ��_monthӦΪ1
			++_year;
		}
	}
	return *this;
}

//��ֵ�������أ�ǰ��--��
Date& Date::operator -- ()
{
	//����Ҳ����ֱ�ӵ���-=1
	if (--_day ==0)//�ж�--_day�Ƿ�Ƿ�������Ƿ�Ӧ��_month��λ
	{
		if (--_month == 0)//�ж�_month����λ���Ƿ�Ƿ�������Ƿ�Ӧ��_year��λ
		{
			_month = 1;//_month��λ��ӦΪ1
			if (--_year < 0)//�ж�_year����λ���Ƿ�Ƿ�������Ƿ�Ӧ�����˳�
			{
				cout << "Illegal Date"<<endl;
				exit(-1);
			}
		}
		_day = GetMonthDay(_year, _month);//ֻҪ�����е����_month��_year���Ǿ��������ҺϷ���,_day��λ��ӦΪ1
	}
	return *this;
}

//��ֵ����������(����++)
Date Date::operator ++ (int)//ret���ں����ڲ�����ģ��뿪������ret�������գ���˲���ʹ�����÷���
{
	Date ret=*this;//ʹ�ÿ���this�ķ�ʽ������ʱDate��
	++*this;//����ǰ��++����,����Ҳ����ֱ�ӵ���+=1
	return ret;//����δ����֮ǰ��Date��
}

//��ֵ����������(����--)
Date Date::operator -- (int)//ret���ں����ڲ�����ģ��뿪������ret�������գ���˲���ʹ�����÷���
{
	Date ret=*this;//ʹ�ÿ���this�ķ�ʽ������ʱDate��
	--*this;//����ǰ��--�Լ�,����Ҳ����ֱ�ӵ���-=1
	return ret;//����δ�Լ�֮ǰ��Date��
}

//��ֵ����������(+=)
Date& Date::operator += (const int n)
{
	if (n < 0)
	{
		*this -= -n;//���+=һ����ֵ
		return *this;
	}
	_day += n;
	while (_day > GetMonthDay(_year, _month))//�ж�_day�Ƿ�Ƿ�
	{
		_day -= GetMonthDay(_year, _month);//һ��һ�ΰ��¼�ȥ��ֱ��_day�Ϸ�
		if (++_month > 12)//�ж�_month����λ���Ƿ�Ƿ�������Ƿ�Ӧ��_year��λ
		{
			_month = 1;//��λ��_monthӦΪ1
			++_year;
		}
	}
	return *this;
}

//��ֵ����������(-=)
Date& Date::operator -= (const int n)
{
	if (n < 0)
	{
		*this += -n;//���+=һ����ֵ
		return *this;
	}
	_day -= n;
	while (_day <= 0)//�ж�_day�Ƿ�Ƿ�
	{
		_day += GetMonthDay(_year, _month);//һ��һ�����½�λ��ֱ��_day�Ϸ�
		if (--_month == 0)//�ж�_month����λ���Ƿ�Ƿ�������Ƿ�Ӧ��_year��λ
		{
			_month = 12;//_month��λ��ӦΪ1
			if (--_year < 0)//�ж�_year����λ���Ƿ�Ƿ�������Ƿ�Ӧ�����˳�
			{
				cout << "Illegal Date" << endl;
				exit(-1);
			}
		}
	}
	return *this;
}

//��ֵ����������(+)
Date Date::operator + (const int n)const//ret���ں����ڲ�����ģ��뿪������ret�������գ���˲���ʹ�����÷���
{
	Date ret = *this;//this���ܷ����ı�
	ret += n;//����+=����
	return ret;
}

//��ֵ����������(-)
Date Date::operator - (int n)const //ret���ں����ڲ�����ģ��뿪������ret�������գ���˲���ʹ�����÷���
{
	Date ret = *this;//this���ܷ����ı�
	ret -= n;//����-=����
	return ret;
}

//��ֵ����������(left-right)
/*������ճ���˼·ʹ����������ֱ����������������ж��»����Ƿ�����ĸ������⣬���潫���÷����һ��˼·*/
int Date::operator - (const Date& right)const
{
	Date dateMax(*this);//����this��
	Date dateMin(right);//����rightС
	int flag = 1;//�����ж����յĲ�ֵ������
	if (*this < right)//�жϼ����Ƿ����
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

//��ϵ����������(<)
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

//��ϵ����������(==)
bool Date::operator==(const Date& right)const
{
	if (_year == right._year &&
		_month == right._month &&
		_day == right._day)
		return true;
	else
		return false;
}

//��ϵ����������(!=)
bool Date::operator!=(const Date& right)const
{
	return !operator==(right);
}

//��ϵ����������(>)
bool Date::operator>(const Date& right)const
{
	return !(operator==(right) || operator<(right));
}

//��ӡ
void Date::DatePrint()const
{
	cout << _year << "-"<<_month <<"-" <<_day << endl;
}