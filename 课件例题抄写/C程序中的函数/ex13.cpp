#include <iostream>
using namespace std;

void change(int a, int b)
{
	a = 30;
	b = 50;
}

int main()
{
	int a[2] = {3,5};
	change (a[0],a[1]);
	cout<<a[0]<<" "<<a[1]<<endl;
	return 0;
}