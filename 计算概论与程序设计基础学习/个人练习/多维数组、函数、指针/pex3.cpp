#include <iostream>
using namespace std;
void change(int []);

int main()
{
	int num[10] = {0};
	change(num);
	
	cout<<"����main��Ԫ��1��Ԫ��10 :";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	
	cout<<"\n"<<"����main�������Ԫ�أ�Ԫ��11 :"<<num[10];
	return 0;
}

void change(int num[])
{
	for(int i = 0; i < 10; i++)
		num[i] = i;
	
	cout<<"����change�������������Ԫ��11 :";
	cout<<num[10]<<endl;
	
}