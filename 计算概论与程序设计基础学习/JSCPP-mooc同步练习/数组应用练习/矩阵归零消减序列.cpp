#include <iostream>
using namespace std;
int rezero(int *, int);

int main()
{
	int n = 3;
	cin>>n;
	
	int sum = 0;
	int matrix_origin[n][n];  //建立初始n*n矩阵
	for( int k = 0; k < n; k++)  //计算n个矩阵
	    {
	        for(int i = 0; i < n; i++)
		        for(int j = 0; j < n; j++)
			        cin>>matrix_origin[i][j];
		
		    sum = rezero(&matrix_origin[0][0],n);
		    cout<<sum<<endl;
	    }
	
	return 0;
}

int rezero(int *matrix, int n)  //二维数组长度不可知，选择使用一维数组指针
{                               //操作二维数组，操作方法是手动寻址

	int i = 0, j = 0;
	int min = matrix[0];  //用于储存行/列的最小值
	for(i = 0; i < n; i++, min = matrix[i*n])  //每行
	{
		for(j = 0; j < n; j++)
			if(min > matrix[i*n+j])
				min = matrix[i*n+j]; //找到、指向该行最小值
			
		for(j = 0; j < n; j++)
			matrix[i*n+j] -= min;  //每一个元素该行减去最小值
	}
	
	min = matrix[0];  //归零
	for(j = 0; j < n; j++, min = matrix[j])  //每列
	{
		for(i = 0; i < n; i++)
			if(min > matrix[i*n+j])
				min = matrix[i*n+j];

        for(i = 0; i < n; i++)
            matrix[i*n+j] -= min;			
	}

    //经过以上操作，满足归零条件
	
	int matrix_new[n-1][n-1];  //未定长度数组初始化是未定义行为，无用，故省去
	int *p_for_new = &matrix_new[0][0];
	for(i = 0; i < n; i++)
	{
		if(i == 1)
			continue;
		else
		for(j = 0; j < n; j++)
		{
			if(j == 1)
				continue;
			else
			{
				*p_for_new = matrix[i*n+j];
				p_for_new++;
			}
		}
	}
	//创造新数组
	
	return (n-1 > 1)?(matrix[n+1] + rezero(&matrix_new[0][0],n-1)):(matrix[n+1]);  //递归、边界
}