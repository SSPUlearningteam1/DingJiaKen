//�ǳ����ŵķ�����̫���ˣ�������Ҫ��һ�ݲο���
#include <iostream>
using namespace std;

void print_diagonal_line(int *num, int n)
{
	if(n == 1)
		cout<<num[0]<<endl;
	else
		for(int i = 0; i < n; i++)
			cout<<num[i*100+(n-1-i)]<<endl; //�˴��ֶ�Ѱַ
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
	//��һ�׶δ���������õ���������Σ��Ҵ������������ϰ벿��
	
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
	//�ڶ��׶δ�������������곤���εĲ���
	
	if(n != 1)  //��С�����β�ִ�б�����
	{
		if(row > col)
		{
			int p = 0; //�ֶ�Ѱַ����
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
			int p = 0; //�ֶ�Ѱַ����
			p = (col-row)+101; 
			while(1)
		    {
			    print_diagonal_line(&num[0][p],n-1);  // ������ֶ�Ѱַ
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
				print_diagonal_line(&num[0][p],n-1); // ������ֶ�Ѱַ
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
	//�����׶δ���������������������°벿��
	
	return 0;
}
