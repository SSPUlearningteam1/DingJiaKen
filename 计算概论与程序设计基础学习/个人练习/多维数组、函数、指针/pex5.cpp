#include <iostream>
using namespace std;
void change(int *);

int main()
{
	int num[10] = {0};
	change(num);
	
	cout<<"这是main中元素1到元素10 用[]计算: ";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	
	cout<<"这是main中元素1到元素10 用加法计算: ";
	for(int i = 0; i < 10; i++)
		cout<<*(num+i)<<" ";
	cout<<endl;
	
	cout<<"这是main函数溢出元素 元素11 用[]计算: ";
	cout<<num[10]<<endl;

	cout<<"这是main函数溢出元素 元素11 用加法计算: ";
	cout<<*(num+10)<<endl;
	
	return 0;
}

void change(int *num)
{
	for(int i = 0; i < 10; i++)
		num[i] = i;
	
	cout<<"这是change中元素1到元素10 用[]计算: ";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	
	
	cout<<"这是change中元素1到元素10 用[]计算: ";
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	cout<<endl;
	
	cout<<"这是change函数溢出函数，元素11 用[]计算: ";
	cout<<num[10]<<endl;
	
	cout<<"这是change函数溢出函数，元素11 用加法计算 :";
	cout<<*(num+10)<<endl;
	
}