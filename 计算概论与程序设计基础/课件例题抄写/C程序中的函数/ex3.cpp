#include <iostream>
using namespace std;

float max(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	cout<<max(3,4);
	return 0;
}