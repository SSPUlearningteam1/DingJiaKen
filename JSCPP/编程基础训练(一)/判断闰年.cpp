#include <iostream>
using namespace std;
int main()
{
	int year = 0;
	cin>>year;
	if(year % 4 == 0 && (year % 100 != 0 || year %400 == 0))
		cout<<"YES";
	else
		cout<<"NO";
	
	return 0;
}