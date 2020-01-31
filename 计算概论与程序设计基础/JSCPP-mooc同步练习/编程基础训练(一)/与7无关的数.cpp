#include <iostream>
using namespace std;

int pow(int x, int n)
{
	int an = 1;
	for (int i = 1; i <= n; i++)
		an *= x;
	
	return an;
	
}

bool check(int n)
{	
	if (n % 7 == 0)
		return false;
	else
	{
		int temp = 0;
		int copy = n;
		while(1)
		{
		    temp = copy % 10;
			if (temp == 7)
				return false;
			else
				copy /= 10;
			
			if (copy == 0)
				break;
		}
		return true;
	}
}

int main()
{
	int n = 0;
    int sum = 0;
	cin>>n;
	
	for (int i = 1; i <= n; i++)
	{
		if (check(i))
			sum += pow(i,2);
	}
	
	cout<<sum;
	
	return 0;
}