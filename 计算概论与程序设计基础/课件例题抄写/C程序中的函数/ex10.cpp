#include <iostream>
using namespace std;

void exchange(int a, int b)
{
	int p;
	if (a < b)
	{
		p = a;
		a = b;
		b = p;
	}
}

int main()
{
	int a = 3, b = 5;
	exchange(a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}