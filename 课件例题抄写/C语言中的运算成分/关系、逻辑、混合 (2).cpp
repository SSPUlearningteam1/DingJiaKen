#include <iostream>
using namespace std;
int main()
{
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || c++;
	cout<<i<<" "<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}