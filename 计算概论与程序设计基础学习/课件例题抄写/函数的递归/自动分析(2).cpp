//看的懂，不会写mak
#include<iostream>
using namespace std;
int count(int apples, int plates)
{
	if (apples <= 1 || plates <= 1)
		return 1;
	if (apples < plates)
		return count(apples,apples);
	else
		return count(apples, plates-1) + count(apples-plates,plates);
}

int main()
{
	int apples, plates;
	cin>>apples>>plates;
	cout<<count(apples,plates);
	return 0;
}