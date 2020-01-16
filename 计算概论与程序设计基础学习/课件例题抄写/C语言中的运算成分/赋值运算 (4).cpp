#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	short short_i = -123;
	cout<<hex<<short_i<<endl;
	int int_j = short_i;
	cout<<hex<<int_j<<endl;
	cout<<dec<<int_j<<endl;
	return 0;
}