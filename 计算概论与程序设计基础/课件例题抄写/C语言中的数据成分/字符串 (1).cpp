#include <iostream>
#include <iomanip>
using namespace	std;
int main()
{
	char a = 64;
	int b = 'Z';
	int c = b - a;
	/*我的编译器不认可下一行的溢出输入，故删去*/
	/*char d = 6 + 256;*/
	cout<<a<<" "<<b<<" "<<c<<" "<<"留给d的位置"<<endl;
	return 0;
}