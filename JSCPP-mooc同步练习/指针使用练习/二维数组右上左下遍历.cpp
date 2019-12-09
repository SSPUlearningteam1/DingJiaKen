//非常夸张的方法，太蠢了，所以我要放一份参考答案
#include <iostream>
using namespace std;

void print_diagonal_line(int *num, int n)
{
	if(n == 1)
		cout<<num[0]<<endl;
	else
		for(int i = 0; i < n; i++)
			cout<<num[i*100+(n-1-i)]<<endl; //此处手动寻址
}

int main()
{
	int row = 0;
	int col = 0;
	cin>>row>>col;
	
	int num[100][100] = {0};
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cin>>num[i][j];
		
	int n = 1;
	while(1)
	{
		print_diagonal_line(&num[0][0],n);
		if(n == row || n == col)
			break;
		else
			n++;
	}
	//第一阶段处理结束，得到最大正方形，且处理完正方形上半部分
	
	if(row > col)
	{
		for(int i = 1; i <= (row-col); i++)
			print_diagonal_line(&num[i][0],n);
	}
	else if(col > row)
	{
		for(int i = 1; i <= (col-row); i++)
			print_diagonal_line(&num[0][i],n);
	}
	//第二阶段处理结束，处理完长方形的部分
	
	if(n != 1)  //最小正方形不执行本部分
	{
		if(row > col)
		{
			int p = 0; //手动寻址变量
			p = (row-col)*100+101;
			while(1)
		    {
			    print_diagonal_line(&num[0][p],n-1);
			    if(n >= 0)
				{
					n--;
					p += 101;
				}
			    else
				    break;
		    }
		}
		else if(col > row)
		{
			int p = 0; //手动寻址变量
			p = (col-row)+101; 
			while(1)
		    {
			    print_diagonal_line(&num[0][p],n-1);  // 神奇的手动寻址
			    if(n >= 0)
				{
				    n--;
					p += 101;
				}
			    else
				    break;
		    }
		}
		else if(row == col)
		{
			int p = 0;
			p = 0 + 101;
			while(1)
			{
				print_diagonal_line(&num[0][p],n-1); // 神奇的手动寻址
				if(n >= 0)
				{
					n--;
					p += 101;
				}
				else
					break;
			}
		}
	}
	//第三阶段处理结束，处理完正方形下半部分
	
	return 0;
}
