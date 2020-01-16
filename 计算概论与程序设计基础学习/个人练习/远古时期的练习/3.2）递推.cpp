//“ª—‘÷Æ£¨A(n+1) = f(A(n));
#include <stdio.h>
int main()
{
	double N = 0;
	double sum = 2;
	double an = 2;
	double n_or = 2;
	double d_or = 1;
	double temp = 0;
	
	scanf("%lf",&N);
	
	if (N == 1)
		printf("%.2lf",sum);
	else
	{
		for(int i = 1; i < N; i++)
		{
		temp = n_or;
		n_or = n_or + d_or;
		d_or = temp;
		
		an = n_or/d_or;
		
		sum += an;
		}
		printf("%.2lf",sum);
	}
	return 0;
}