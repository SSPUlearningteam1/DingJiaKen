//用异或运算交换两变量的值
#include <iostream>
using namespace std;
int main()
{
	int a = 1, b = 2;
	cout<<a<<" "<<b<<endl;
	a = a^b;
	b = b^a;
	a = a^b;
	cout<<a<<" "<<b<<endl;
	return 0;
}