//Ò»ÑÔÖ®£¬An = f(A(n-1));
#include <stdio.h>
double get_sum (double);
double get_numerator (double);
double get_denominator (double);
double get_an (double);

int main()
{
	double N = 0;
	double sum = 0;
	
	scanf("%lf",&N);
	
	sum = get_sum(N);
	
	printf("%.2lf",sum);
	
	return 0;
}

double get_sum (double N)
{
	double sum = 0;
	if (N == 1)
		return 2;
	else
	{
	sum = get_sum(N-1) +get_an(N);
	return sum;
	}
	
}

double get_an(double N)
{
	double an = 0;
	if (N == 1)
		return 2;
	else
	{
		an = (get_numerator(N))/(get_denominator(N));
		return an;
	}
}

double get_numerator (double N)
{
	double numerator = 0;
	if (N == 1)
		return 2;
	else
	{
		numerator = get_numerator(N-1) + get_denominator(N-1);
		return numerator;
	}
}

double get_denominator (double N)
{
	double denominator = 1;
	if (N == 1)
		return 1;
	else
	{
		denominator = get_numerator(N-1);
		return denominator;
	}
}











































