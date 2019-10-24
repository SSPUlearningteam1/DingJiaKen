#include <iostream>
using namespace std;
int main()
{
	char char_a = ' ';
	int int_i = 0x361;
	cout<<hex<<int_i<<endl;
	char_a = int_i;
	cout<<char_a<<endl;
	return 0;
}