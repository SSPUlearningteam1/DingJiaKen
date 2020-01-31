#include <iostream>
using namespace std;
float max (float, float);

int main()
{
	cout<<max(3,4);
	return 0;
}

float max (float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}