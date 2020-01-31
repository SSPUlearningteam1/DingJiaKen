//从来没写过那么啰嗦的程序
#include <iostream>
using namespace std;
void PRINT(int , int , int );
void check(int , int , int );

int main()
{
	for(int a = 0; a < 3; a++)
	{
		for(int b = 0;  b < 3; b++)
		{
			if(b == a)
				continue;
			else
				for(int c = 0; c < 3; c++)
				{
					if(c == a || c == b)
						continue;
					else
						check(a,b,c);
				}
		}
	}
	
	return 0;
}

void check(int a, int b, int c)
{
	int count_a = 0;
	int count_b = 0;
	int count_c = 0;
	
	if( !(b > a) )
		count_a++;
	if( !(c == a) )
		count_a++;
	
	if( !(a > b) )
		count_b++;
	if( !(a > c) )
		count_b++;
	
	if( !(c > b) )
		count_c++;
	if( !(b > a) )
		count_c++;
	
	if( a == count_a && b == count_b && c == count_c)
		PRINT(a,b,c);
}

void PRINT(int a, int b, int c)
{
	int num[3] = {0};
	int reline[3] = {0};
	char name[4] = {'A','B','C','\0'};
	
	reline[0] = num[0] = a;
	reline[1] = num[1] = b;
	reline[2] = num[2] = c;
	
	int temp = 0;
	for (int i = 0; i < 2; i++)
		for (int j = i+1; j < 3; j++)
			if(reline[i] > reline[j])
			{
				temp = reline[i];
				reline[i] = reline[j];
				reline[j] = temp;
			}
	
	for(int k = 0; k < 3; k++)
		for(int u = 0; u < 3; u++)
			if(reline[k] == num[u])
				cout<<name[u];
}