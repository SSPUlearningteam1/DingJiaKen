#include <iostream>
using namespace std;
int main()
{
	int i = 0;
	cout<<(i = 10)<<endl;
	cout<<(i = i + i);
	return 0;
}