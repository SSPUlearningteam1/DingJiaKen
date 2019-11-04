//错误的示范,编译器不通过
/*
#include <iostream>
using namespace std;
int *getInt1()
{
	int value1 = 20;
	return &value1;
}
int main()
{
	int *p;
	p = getInt1();
	cout<<*p<<endl;
	return 0;
}
*/