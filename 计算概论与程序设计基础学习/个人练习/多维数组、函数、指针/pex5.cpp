#include <iostream>
using namespace std;
void change(int *);

int main()
{
	int num[10] = {0};
	change(num);
	
	cout<<"����main��Ԫ��1��Ԫ��10 ��[]����: ";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	
	cout<<"����main��Ԫ��1��Ԫ��10 �üӷ�����: ";
	for(int i = 0; i < 10; i++)
		cout<<*(num+i)<<" ";
	cout<<endl;
	
	cout<<"����main�������Ԫ�� Ԫ��11 ��[]����: ";
	cout<<num[10]<<endl;

	cout<<"����main�������Ԫ�� Ԫ��11 �üӷ�����: ";
	cout<<*(num+10)<<endl;
	
	return 0;
}

void change(int *num)
{
	for(int i = 0; i < 10; i++)
		num[i] = i;
	
	cout<<"����change��Ԫ��1��Ԫ��10 ��[]����: ";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	
	
	cout<<"����change��Ԫ��1��Ԫ��10 ��[]����: ";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	
	cout<<"����change�������������Ԫ��11 ��[]����: ";
	cout<<num[10]<<endl;
	
	cout<<"����change�������������Ԫ��11 �üӷ����� :";
	cout<<*(num+10)<<endl;
	
}