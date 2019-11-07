#include <iostream>
using namespace std;

bool check(double n)
{
	if (-1.0 < n && n < 1.0)
		return true;
	else
		return false;
}

int main()
{
	double x = 0;
	double y = 0;
	
	cin>>x;
	cin.get();
	cin>>y;
	
	if(check(x) && check(y))
		cout<<"yes";
	else
		cout<<"no";
}