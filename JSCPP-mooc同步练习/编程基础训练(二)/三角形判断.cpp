#include <iostream>
#include <cmath>
using namespace std;

bool check(int a, int b, int c)
{
	if( (a + b > c) && (a + c > b) && (b + c > a) && (abs(a - b) < c) && (abs(a - c) < b) && (abs(b - c) < a) )
		return true;
	else
		return false;
}

int main()
{
	int a = 0, b = 0, c = 0;
	
	cin>>a>>b>>c;
	
	if(check(a,b,c))
		cout<<"yes";
	else
		cout<<"no";
	
	return 0;
}