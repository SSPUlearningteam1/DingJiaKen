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
	int m = 3, n = 4;
	float result = 0;
	result = max(m,n);
	cout<<result;
	return 0;
}