#include <iostream>
using namespace std;
void change_1(int *, int);
void change_2(int *, int, int);

int main()
{
	int n = 0;  //行
	int m = 0;  //列
	
	int i = 0, j = 0;
	int num[3][4] = {0};
	n = 3; m = 4;  //如果数组长度填选变量那么数组初始化会出现未定义行为
	               //例如int num[n][m] = {0};只有部分元素被初始化为0
	               //这里举个例子，模拟输入n = 3,m = 4的情况
				   
	cout<<"第一次遍历一个二维数组："<<endl;
	for(i = 0; i < n; i++)  //遍历
	{
		for(j = 0; j < m; j++)
			cout<<num[i][j]<<" ";
        cout<<endl;
	}
	
	change_1(&num[0][0], m);  //一维指针，也可以写作num[0]
	
	cout<<"第二次遍历一个二维数组："<<endl;
	for(i = 0; i < n; i++)  //遍历
	{
		for(j = 0; j < m; j++)
			cout<<num[i][j]<<" ";
        cout<<endl;
	}
	
	change_2(num[0], n, m);
	
	cout<<"第三次遍历一个二维数组："<<endl;
	for(i = 0; i < n; i++)  //遍历
	{
		for(j = 0; j < m; j++)
			cout<<num[i][j]<<" ";
        cout<<endl;
	}
	
}

void change_1(int *num, int m)  //因为列数未知，*num不能写作其他形式
{
	//手动寻址
	num[m-1] = 1;
	num[m-1 + 1*m] = 1;
	num[m-1 + 2*m] = 1;
}

void change_2(int *num, int n, int m)
{
	//手动寻址
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			num[i*m + j] = 2;
}