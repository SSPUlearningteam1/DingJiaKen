//闰年问题-判断闰年
#include <iostream>
using namespace std;
int main()
{
	int year = 0;
	cout<<"请输入一个年份:"<<endl;
	cin>>year;
	if((year%4==0&&year%100!=0)||year%400==0)
	
		cout<<'\n'<<"闰年"<<endl;
	
	else
		cout<<'\n'<<"非闰年"<<endl;
	return 0;
}