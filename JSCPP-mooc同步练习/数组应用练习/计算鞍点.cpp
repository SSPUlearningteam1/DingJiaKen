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
		p_row_max = &matrix[i][0];  //ָ��ÿ�е�һ��Ԫ��
		mark_column = 0;   //��¼Ϊ��һ��
		for(j = 0; j < 5; j++)
			if(*p_row_max < matrix[i][j])
			{
				p_row_max = &matrix[i][j];  //�ҵ���ָ��ÿ�����ֵ
                mark_column = j;  //��¼����	
			}
		
		
		p_column_min = &matrix[0][mark_column];  //ָ���¼�еĵ�һ�е�Ԫ��
        mark_row = 0;  //��¼Ϊ��һ��
		for(int k = 0; k < 5; k++)  //�ӵ�һ�п�ʼ
		    if(*p_column_min > matrix[k][mark_column])
			{
				p_column_min = &matrix[k][mark_column];  //�ҵ���ָ��ÿ����Сֵ
                mark_row = k;
		    }
		
		if(p_row_max == p_column_min)//���ΪͬһԪ�أ����ǰ���
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