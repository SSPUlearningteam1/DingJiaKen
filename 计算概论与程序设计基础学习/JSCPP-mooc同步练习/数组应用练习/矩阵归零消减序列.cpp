#include <iostream>
using namespace std;
int rezero(int *, int);

int main()
{
	int n = 3;
	cin>>n;
	
	int sum = 0;
	int matrix_origin[n][n];  //������ʼn*n����
	for( int k = 0; k < n; k++)  //����n������
	    {
	        for(int i = 0; i < n; i++)
		        for(int j = 0; j < n; j++)
			        cin>>matrix_origin[i][j];
		
		    sum = rezero(&matrix_origin[0][0],n);
		    cout<<sum<<endl;
	    }
	
	return 0;
}

int rezero(int *matrix, int n)  //��ά���鳤�Ȳ���֪��ѡ��ʹ��һά����ָ��
{                               //������ά���飬�����������ֶ�Ѱַ

	int i = 0, j = 0;
	int min = matrix[0];  //���ڴ�����/�е���Сֵ
	for(i = 0; i < n; i++, min = matrix[i*n])  //ÿ��
	{
		for(j = 0; j < n; j++)
			if(min > matrix[i*n+j])
				min = matrix[i*n+j]; //�ҵ���ָ�������Сֵ
			
		for(j = 0; j < n; j++)
			matrix[i*n+j] -= min;  //ÿһ��Ԫ�ظ��м�ȥ��Сֵ
	}
	
	min = matrix[0];  //����
	for(j = 0; j < n; j++, min = matrix[j])  //ÿ��
	{
		for(i = 0; i < n; i++)
			if(min > matrix[i*n+j])
				min = matrix[i*n+j];

        for(i = 0; i < n; i++)
            matrix[i*n+j] -= min;			
	}

    //�������ϲ����������������
	
	int matrix_new[n-1][n-1];  //δ�����������ʼ����δ������Ϊ�����ã���ʡȥ
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
	//����������
	
	return (n-1 > 1)?(matrix[n+1] + rezero(&matrix_new[0][0],n-1)):(matrix[n+1]);  //�ݹ顢�߽�
}