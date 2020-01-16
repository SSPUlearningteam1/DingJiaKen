#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int a[100];
	int flag = 0;
	
	cin>>n;
	
	for (int i = 0; i < n; i++)
		cin>>a[i];
	
	for (int j = (n-1); j >= 0; j--)
	{
		if(flag == 1)
			cout<<" ";
		else
			flag = 1;
		cout<<a[j];
	}
	
	return 0;
}