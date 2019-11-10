#include <iostream>
using namespace std;

int main()
{
	int num_10 = 0;
	int num_7 = 0;
	int num_9 = 0;
	
	for (int i = 1; i <= 6; i++)  //通过7进制排列数开始找
		for (int j = 0; j <= 6; j++)
			for (int k = 1; k <= 6; k++)
			{
				if((i*49+j*7+k*1) == (i*1+j*9+k*81))
				{
				    num_10 = i*49 + j*7 + k*1;
					num_7 = i*100 + j*10 + k*1;
					num_9 = k*100 + j*10 + i*1;
				}
				    
			}
				
	int control = 0;
	cin>>control;
	
	switch(control)
	{
		case 1: cout<<num_10; break;
		case 2: cout<<num_7; break;
		case 3: cout<<num_9; break;
	}
	
	return 0;
}