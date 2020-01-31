#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float a, b;
	a = 123456.789e5;
	b = a +20;
	cout<<setprecision(20)<<b<<endl;
	return 0;
}