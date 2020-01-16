#include <iostream>
using namespace std;

int check (int n)
{
	int copy = n;
	int temp = 0;
	int count = 0;
	
	while(1)
	{
		temp = copy %10;
		if ( temp == 1)
			count++;
		
		copy /= 10;
		
		if (copy == 0)
			break;
	}
	
	return count;
}

int main()
{
	int n = 0;
	int sum = 0;
	
	cin>>n;
	
	for (int i = 1; i <= n; i++)
		sum += check(i);
	
	cout<<"Number of one in "<<n<<" is "<<sum<<".";
	
	return 0;
}