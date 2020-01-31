#include <iostream>
using namespace std;
void get_longest(int);

int main()
{
	int n = 0;
	while(1)
	{
		cin>>n;
		if(n != 0)
		   get_longest(n);
	    else
		   break;
	}
	
	return 0;
}

void get_longest(int n)
{
	int num_now = 0;
	int num_next = 0;
	int count = 0;
	int count_max = 0;
	
	cin>>num_now;
	count = 1;
	count_max = 1;
	
	for (int i  = 0; i < (n-1); i++)
	{
		cin>>num_next;
		if(num_next == num_now)
		{
			count++;
			if(count_max < count)
				count_max = count;
		}
		else
		{
			num_now = num_next;
			count = 1;
		}
	}
	
	cout<<count_max<<endl;
}