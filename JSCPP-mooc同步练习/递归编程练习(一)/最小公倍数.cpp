#include <stdio.h>
int common_divisor(int num1, int num2)
{
	return (num1%num2 == 0)?(num2):(common_divisor(num2,num1%num2));
}
int main()
{
	int num1 = 0, num2 = 0;
	scanf("%d,%d",&num1,&num2);
	printf("%d",(num1*num2)/common_divisor(num1,num2));
	return 0;
}