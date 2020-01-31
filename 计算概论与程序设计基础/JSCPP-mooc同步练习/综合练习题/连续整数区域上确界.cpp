//完美超时，完美超内存，愿赌服输，下次一定改
//真难
#include <stdio.h>
#define MAX 21
int num[MAX] = {0};
int times[MAX] = {0};  //对应每个num元素，表示num出现的次数
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
			scanf("%d",&num[i]);//读取结束
		
		if(num[0] == 0)
			break;//出口
		
		for(int i = 1; i <= num[n-1]*k; i++)
		{
			if(check(i,n,k))//不中断
			{
				length_now++;
			}
			else//中断
			{
				if(length_max < length_now)
				{
					num_maxtail = i-1;  //中断前
					length_max = length_now;
				}
				
				length_now = 0;
			}
			
			if(i == num[n-1]*k)//特判，遍历结束
			{
				if(length_max < length_now)
				{
					num_maxtail = i;  //中断前
					length_max = length_now;
				}
			}
		}
		
		printf("%d\n",num_maxtail);
		
		for(int i = 0; i < n; i++) //归零
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
		return -1;  //遍历全结束
	
	times[i] = 0;
	return 0;
}