//���������ˣ�д�����ˣ��������ˣ�������Ȼ��������Ȼ������WA��
/*
���������У�1��һ�����ݣ���������ͨ������2������0��ͨ����
3��һ�����㣬ͨ����4���������㣬ͨ��
5������ 1 0 1 0 1
        0 0 0 0 0
		1 0 0 0 1
		0 0 0 0 0
        1 0 1 0 1
�����������޷�ͨ������������

�����Ľ̳�ȥ�ˣ���д�ˡ�	
*/
#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100
int find_max_zero(int (*matrix)[MAX], int row, int col);

int main()
{
	int row = 0, col = 0;
	cin>>row>>col;
	
	int matrix[MAX][MAX] = {0};
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cin>>matrix[i][j];
		
	int max_zero = 0;
	max_zero = find_max_zero(&matrix[0],row,col);
	
	cout<<max_zero;
	
	return 0;
}

int find_max_zero(int (*matrix)[MAX], int row, int col)
{
	int max_zero = 0;
	int now_zero = 0;
	
	int mark_row = 0;
	int mark_col = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if( matrix[i][j] == 0 && (2 <= (matrix[i-1][j] != 0 || i-1 < 0) + (matrix[i+1][j] != 0 || i+1 > row-1) + (matrix[i][j-1] != 0 || j-1 < 0) + (matrix[i][j+1] != 0 || j+1 > col-1) + (matrix[i][j+1] != 0 || j+1 > col-1)) )
			{				
				if(matrix[i-1][j] != 0 || i-1 < 0)//��
				{
					for(mark_row = i; matrix[mark_row][j] == 0 && mark_row < row; mark_row++) ;
					
					if(matrix[i][j-1] != 0 || j-1 < 0)//��
					{
						for(mark_col = j+1; mark_col < col; mark_col++)
						{
                            int flag = 1;							
					        for(int u = i; u < mark_row; u++)
						    {
							    if(matrix[u][mark_col] != 0)
								{
									flag = 0;
									break;
								}
						    }
							
							if(flag == 0)
								break;
						}
					}
					else if(matrix[i][j+1] != 0 || j+1 > col-1)//��
					{
						for(mark_col = j-1; mark_col >= 0; mark_col--)
						{
                            int flag = 1;							
					        for(int u = i; u < mark_row; u++)
						    {
							    if(matrix[u][mark_col] != 0)
								{
									flag = 0;
									break;
								}
						    }
							
							if(flag == 0)
								break;
						}
					}
				}
				else if(matrix[i+1][j] != 0 || i+1 > row-1)//��
				{
					for(mark_row = i; matrix[mark_row][j] == 0 && mark_row >= 0; mark_row--) ;
					
					if(matrix[i][j-1] != 0 || j-1 < 0)//��
					{
						for(mark_col = j+1; mark_col < col; mark_col++)
						{
                            int flag = 1;							
					        for(int u = i; u > mark_row; u--)
						    {
							    if(matrix[u][mark_col] != 0)
								{
									flag = 0;
									break;
								}
						    }
							
							if(flag == 0)
								break;
						}
					}
					else if(matrix[i][j+1] != 0 || j+1 > col-1)//��
					{
						for(mark_col = j-1; mark_col >= 0; mark_col--)
						{
                            int flag = 1;							
					        for(int u = i; u > mark_row; u--)
						    {
							    if(matrix[u][mark_col] != 0)
								{
									flag = 0;
									break;
								}
						    }
							
							if(flag == 0)
								break;
						}
					}
				}
				
			    now_zero = abs(i-mark_row) * abs(j-mark_col);
				if(max_zero < now_zero)
				    max_zero = now_zero;
			}
			
	return max_zero;
}