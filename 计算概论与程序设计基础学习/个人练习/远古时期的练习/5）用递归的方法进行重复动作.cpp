#include <stdio.h>

void PRINT(int n)
{
	if (n / 10 == 0)
		printf("%d ",n%10);
	else
	{
		PRINT(n/10);
		printf("%d ",n%10);
	}
}

int main()
{
	int N = 0;
	scanf("%d",&N);
	PRINT(N);
	return 0;
}