//´òÓ¡É³Â©ÎÊÌâ
#include <iostream>
#include <cmath>
using namespace std;

int get_N (int num)
{
	double sum = num;
	double N = 0;
	
	while(1){
		N = sqrt((sum+1)/2);
		if ( N-(int)N == 0)
			break;
		else
			sum -= 1;
	}
	N = (int)N;
	return N;
}

int get_an (int N)
{
	int a1 = 1;
	int d = 2;
	int an = 0;
	an = a1 + (N - 1) * d;
	return an;
}

void PRINT (int N, int an, int remainder, char P)
{
	int N0 = N;
	int a0  = an;
	int flag = 0;
	
	while(N0 <= N || flag == 0)
	{
		for (int i = 0; i < ((an - a0)/2); i++)
		{cout<<' ';}
	    for (int j = 0; j < a0; j++)
		{cout<<P;}
	    
		if (N0 == 1)
			flag = 1;
		
		if (flag == 0)
		{N0--; a0-=2;}
	    else if (flag == 1)
		{N0++; a0+=2;}
	
	    if(N0 <= N || flag == 0)
			cout<<endl;
	}
	cout<<'\n'<<remainder;
}

int main()
{
	int num = 0;
	int N = 0;
	int an = 0;
	int remainder = 0;
	char P = '\0';
	
	cin>>num>>P;
	
	N = get_N(num);
	an = get_an(N);
	remainder = num - N*N*2 +1;

	PRINT(N, an, remainder ,P);
	
	return 0;
}