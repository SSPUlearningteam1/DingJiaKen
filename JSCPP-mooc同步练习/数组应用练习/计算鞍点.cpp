//升级版，改进了一些错误
#include <stdio.h>
#define LIMIT 6
int main()
{
	int n = 0;
	scanf("%d",&n);
	
	int i = 0, j = 0, k = 0;  //计数变量
	int num[LIMIT][LIMIT] = {0};
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d",&num[i][j]);
	
	int flag = 0;
	int max_row = 0;
	int min_col = 0;
	for(i = 0; i < n; i++)
	{
		max_row = num[i][0];
		for(j = 0; j < n; j++)
			if(max_row < num[i][j])
				max_row = num[i][j];

		for(j = 0; j < n; j++) 
			if(num[i][j] == max_row)
			{
				min_col = num[0][j];
				for(k = 0; k < n; k++)
					if(min_col > num[k][j])
						min_col = num[k][j];
				
				for(k = 0; k < n; k++)
					if(num[k][j] == min_col && k == i)  //找到鞍点
					{
						printf("%d %d",i,j);
						flag = 1;
					}
			}
	}
	if(flag == 0)
		printf("NONE");
	
	return 0;
}