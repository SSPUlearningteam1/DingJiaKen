#include <iostream>
using namespace std;
int main()
{
	char ch[20];
	cout<<"enter a sentence:"<<endl;
	cin.getline(ch,10,'o'); //ָ����ֹ��Ϊ'o'
	cout<<ch<<endl;
	return 0;
}