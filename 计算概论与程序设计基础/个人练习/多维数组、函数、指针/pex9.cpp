#include <iostream>
using namespace std;
void change_1(int *);
void change_2(int (*)[4]);

int main()
{
	int num[3][4] = {0};
	change_1(&num[0][0]);  //一维指针，指向一个数组元素
	                       //&num[x][0]也可以写作num[x]
						   
	change_2(&num[0]);     //二维指针，指向一个一维数组
	                       //&num[a]也可以写作num
	
	for(int i = 0; i < 3; i++)
	{
		cout<<"遍历二维数组: ";
		for(int j = 0; j < 4; j++)
            cout<<num[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}

void change_1(int *num) //一级指针做形参，可以直接操作一个元素
{                       //也可以遍历一个一维数组
            *num = 1;   //形参也可以写作int num[]
			num[1] = 1;
}

void change_2(int (*num)[4])  //指定形参为数组指针，指针基类型为
{                             //有4个元素的一维数组
	num[1][1] = 1;            //形参也可以写作int num[][4]
}
