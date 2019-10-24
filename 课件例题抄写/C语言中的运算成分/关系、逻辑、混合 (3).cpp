#include <iostream>
using namespace std;
int main()
{
	int a = 0, b = 1;
	a = 8>4-(b=!'c')&&(5>3+'a'%6)=='b';
	cout<<a<<" "<<b;
	return 0;
}
	