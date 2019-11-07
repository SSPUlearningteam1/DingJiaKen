#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	int temp = 0;
	int c10 = 0;
	int c5 = 0;
	int c1 = 0;
	
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		
		if (temp == 1)
			c1++;
		
		if(temp == 5)
			c5++;
		
		if(temp == 10)
			c10++;
	}
	
	cout<<c1<<'\n'<<c5<<'\n'<<c10;
	
	return 0;
}