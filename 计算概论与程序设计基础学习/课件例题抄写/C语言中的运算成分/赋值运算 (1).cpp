#include <iostream>
using namespace std;
int main()
{
	int int_i = 64.12345;
	char char_i = int_i;
	float float_i = char_i;
	bool bool_i = float_i;
	cout<<showpoint<<int_i<<" "<<char_i<<" "<<float_i<<" "<<bool_i<<endl;
	return 0;
}