//��������-�ж�����
#include <iostream>
using namespace std;
int main()
{
	int year = 0;
	cout<<"������һ�����:"<<endl;
	cin>>year;
	if((year%4==0&&year%100!=0)||year%400==0)
	
		cout<<'\n'<<"����"<<endl;
	
	else
		cout<<'\n'<<"������"<<endl;
	return 0;
}