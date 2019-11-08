#include <iostream>
using namespace std;

int main()
{
	int num_help = 0; //用int,使细菌数量不满一舍去
	int num_harm = 0;
	int n = 0;
	int count = 0;
	
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		cin>>num_harm>>num_help;
		while(1)
		{
			count++;
			
			num_harm -= num_help;
			
			if(num_harm <= 0)
				break;
			else
			{
				num_harm *= 2;
				if(num_harm > 1000000)
					num_harm = 1000000;
				
			    num_help *= 1.05;
			}
		}
		
		cout<<count<<endl;
		count = 0;
	}
	return 0;
}