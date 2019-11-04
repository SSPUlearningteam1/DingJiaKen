//ÇĞÆ»¹ûÎÊÌâ
#include<iostream>
using namespace std;
int q(int n)
{
	if (n == 0)
		return 1;
	else
		return (n + q(n-1));
}

int main()
{
	int x = 0;
	int sum =0;
	cin>>x;
	sum = q(x);
	cout<<sum;
	return 0;
}