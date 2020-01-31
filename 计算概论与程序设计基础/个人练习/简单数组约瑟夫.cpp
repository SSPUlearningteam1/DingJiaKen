#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff( n, m, out );   
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}

void CountOff( int n, int m, int out[] )
{
	for(int i = 0; i < n; i++)
		out[i] = 0;
	
	int count = 1;
	int p = 0;
	while(count <= n)
	{
		for(int j = 0; j < m; p++)
		{
			p %= n;
			if(out[p] == 0)
			    j++;
		}
		
		out[p-1] = count++;
	}
}