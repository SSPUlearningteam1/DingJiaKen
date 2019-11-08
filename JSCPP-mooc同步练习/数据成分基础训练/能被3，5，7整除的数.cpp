#include <iostream>
using namespace std;
int flag = 0;

void PRINT()
{
	if(flag == 1)
		cout<<" ";
	else
		flag = 1;
}

void check(int n)
{
	if (n % 3 == 0)
	{
		PRINT();
		cout<<3;
	}
	
	if (n % 5 == 0)
	{
		PRINT();
		cout<<5;
	}
	
	if (n % 7 == 0)
	{
		PRINT();
		cout<<7;
	}
	
	if (flag == 0)
		cout<<"n";
}

int main()
{
	int n = 0;
	
	cin>>n;
	
	check(n);
	
	return 0;
}