#include <iostream>
using namespace std;
int main()
{
	long int long_i = 0x2AAAAAAA;
	cout<<long_i<<endl;
	short short_j = long_i;
	cout<<hex<<short_j<<endl;
	cout<<dec<<short_j<<endl;
	return 0;
}