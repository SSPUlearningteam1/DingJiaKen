//������ʱ���������ڴ棬Ը�ķ��䣬�´�һ����
//����
#include <stdio.h>
#define MAX 21
int num[MAX] = {0};
int times[MAX] = {0};  //��Ӧÿ��numԪ�أ���ʾnum���ֵĴ���
int get_result(int key, int n, int k, int i);
int check(int key, int n, int k);

int main()
{
	int n = 0, k = 0;
	scanf("%d,%d",&n,&k);
	
	int num_maxtail = 0;
	int length_now = 0;
	int length_max = 0;
	while(1)
	{
		for(int i = 0; i < n; i++)
			scanf("%d",&num[i]);//��ȡ����
		
		if(num[0] == 0)
			break;//����
		
		for(int i = 1; i <= num[n-1]*k; i++)
		{
			if(check(i,n,k))//���ж�
			{
				length_now++;
			}
			else//�ж�
			{
				if(length_max < length_now)
				{
					num_maxtail = i-1;  //�ж�ǰ
					length_max = length_now;
				}
				
				length_now = 0;
			}
			
			if(i == num[n-1]*k)//���У���������
			{
				if(length_max < length_now)
				{
					num_maxtail = i;  //�ж�ǰ
					length_max = length_now;
				}
			}
		}
		
		printf("%d\n",num_maxtail);
		
		for(int i = 0; i < n; i++) //����
		{
			num[i] = 0;
			times[i] = 0;
		}
	    num_maxtail = 0;
	    length_now = 0;
	    length_max = 0;
	}
	
	return 0;
}

int check(int key, int n, int k)
{
	int result = 0;
	while(1)
	{
		result = get_result(key,n,k,0);
		if(result == key)
			return 1;
		else if(result == -1)
			return 0;
	}
}

int get_result(int key, int n, int k, int i)
{
	int result = 0;
	int sum_times = 0;
	for(int j = 0; j <= k; j++, sum_times = 0, result = 0)
	{
		times[i] = j;
	    for(int u = 0; u <= i; u++)
			sum_times += times[u];
		
		if(sum_times < k && i < n-1)
			result = get_result(key,n,k,i+1);
		else if( sum_times == k || (i == n-1 && sum_times <= k) )
		{
			for(int y = 0; y <= i; y++)
				result += num[y]*times[y];
		}
		else if(sum_times > k)
		    break;
		
		if(result == key)
			return result;
		else if(result == 0)
			continue;
		else if(result == -1)
			return -1;
	}
	
	if(times[0] == k)
		return -1;  //����ȫ����
	
	times[i] = 0;
	return 0;
}