//正确的定义方法
#include <iostream>
using namespace std;
int main()
{
	char a[10] = {"loveChina"};
	for (int i  = 0; i < 10; i++)
		cout<<a[i];
	    cout<<'\n'<<sizeof(a)<<endl;//本篇代码有改动
	return 0;
}