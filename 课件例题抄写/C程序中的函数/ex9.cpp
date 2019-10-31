#include <iostream>
using namespace std;

void change(int c, int b)
{
	c = 30; b = 50;
}

int main()
{
	int a = 3, b = 5;
	change (a,b);
	cout<<a<<" "<<b;
	return 0;
}