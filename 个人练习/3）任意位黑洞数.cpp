//任意位黑洞问题--位数设置常数变量为figures--关键数常数变量为key。
//给出参考：三位黑洞数为495，四位黑洞数是6174.
//本程序目前填入的是三位黑洞数
#include <stdio.h>

void get_num(int a[],int num,int figures)
{
	for (int i = 0; i < figures; i++)
	{
		a[i] = num % 10;
		num /= 10;
	}
}

void reline_max_to_min(int a[],int figures)
{
	int i = 0, j = 0;
	int temp = 0;
	for(i = 0; i < (figures-1); i++)
		for(j = i + 1; j < figures; j++)
			if(a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

int get_max(int a[],int figures)
{
	int max = 0;
	int i = 0;
	int n = 1;
	for( i = (figures-1); i >= 0; i--)
	{
		max += a[i]*n;
		n *= 10;
	}		
	
	return max;
		
}
int get_min(int a[],int figures)
{
	int min = 0;
	int i = 0;
	int n = 1;
	for( i = 0; i < figures; i++)
	{
		min += a[i]*n;
		n *= 10;
	}		
	
	return min;
		
}

int main()
{
	int num = 0;
	int max = 0;
	int min = 0;
	int count = 0;
	int a[10] = {0};
	const int figures = 3;
	const int key = 495;
	
	scanf("%d",&num);
	
	while(1)
	{
		count++;
		
		get_num(a,num,figures);
		
		reline_max_to_min(a,figures);
		
		max = get_max(a,figures);
		min = get_min(a,figures);
		num = max - min;
		
		printf("%d: %d - %d = %d",count,max,min,num);
		
		if(num == 0 || num == key)
			break;
		else
			printf("\n");
	}
	
	return 0;
}