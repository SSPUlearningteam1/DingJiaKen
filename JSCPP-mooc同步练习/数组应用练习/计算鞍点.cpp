#include <iostream>
using namespace std;
int main()
{
    int flag = 0;
	int i = 0, j = 0;
	int matrix[5][5];
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			cin>>matrix[i][j];
	
	const int *p_row_max = NULL;
	const int *p_column_min = NULL;
	int mark_row = 0;
	int mark_column = 0;
	for(i = 0; i < 5; i++)
	{
		p_row_max = &matrix[i][0];  //指向每行第一列元素
		mark_column = 0;   //记录为第一列
		for(j = 0; j < 5; j++)
			if(*p_row_max < matrix[i][j])
			{
				p_row_max = &matrix[i][j];  //找到、指向每行最大值
                mark_column = j;  //记录该列	
			}
		
		
		p_column_min = &matrix[0][mark_column];  //指向记录列的第一行的元素
        mark_row = 0;  //记录为第一行
		for(int k = 0; k < 5; k++)  //从第一行开始
		    if(*p_column_min > matrix[k][mark_column])
			{
				p_column_min = &matrix[k][mark_column];  //找到、指向每列最小值
                mark_row = k;
		    }
		
		if(p_row_max == p_column_min)//如果为同一元素，则是鞍点
		{
			cout<<++mark_row<<" "<<++mark_column<<" "<<*p_row_max;
			flag = 1;
		}
        else 
            continue;			
				
	}
	if(flag == 0)
		cout<<"not found";
	
	return 0;
	
}