#include <iostream>
using namespace std;

bool check(int n)
{
	if (n % 2 != 0)
		return true;
	else
		return false;
}

int main()
{
	int m = 0;
	int n = 0;
	int sum = 0;
	
	cin>>m>>n;
	
	for(int i = m; i <= n; i++)
	{
		if(check(i))
			sum += i;
		else
			continue;
	}
	
	cout<<sum;
	
	return 0;
}