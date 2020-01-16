#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	unsigned int unsigned_int_i = 0xAAAAAAAA;
	cout<<unsigned_int_i<<endl;
	signed int signed_int_j = unsigned_int_i;
	cout<<hex<<signed_int_j<<endl;
	cout<<dec<<signed_int_j<<endl;
	return 0;
}