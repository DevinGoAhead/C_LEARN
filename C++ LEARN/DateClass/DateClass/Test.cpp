#include"ClassDate.h"

void DateTest()
{
	Date d1(2024, 10, 31);
	&d1;
	const Date d2(2024,12,31);
	/*Date*  pd2=&d2;*/
	const int i = 0;
	int d = i;
	/*int* pi = &i;*/
	Date d3(2024, 1, 2);

	//Date d4(2024, 1, 1);
	//
	////«∞÷√
	//(++d1).DatePrint();
	//(++d2).DatePrint();
	//(--d3).DatePrint();
	//(--d4).DatePrint();

	////∫Û÷√
	//(d1++).DatePrint();
	//(d2++).DatePrint();
	//(d3--).DatePrint();
	//(d4--).DatePrint();

	////-= +=
	//(d1 += 10).DatePrint();
	//(d1 -= 20).DatePrint();

	////+ -
	//(d1 -= -1).DatePrint();
	//(d2 -= 10000).DatePrint();
	//(d3 += 10000).DatePrint();
	//(d4 += 1).DatePrint();

	//cout << d3 - d4 << endl;
	//cout << d4 - d3 << endl;

}

int main()
{
	DateTest();
	return 0;
}