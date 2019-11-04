#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};
	int(*p)[4],i,j; //填空:完成变量p的定义
	p = a;
	cin>>i>>j;  //i<3代表行号，j<4代表列表
	cout<<setw(4)<<*(*(p+i)+j);
	return 0;
}