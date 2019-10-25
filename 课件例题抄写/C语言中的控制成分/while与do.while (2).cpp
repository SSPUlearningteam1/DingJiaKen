#include <iostream>
using namespace std;
int main()
{
	int ageOfHong = 10, ageOfFather = 33, count = 0;
	while (2*ageOfHong != ageOfFather)
	{
		ageOfHong++;
		ageOfFather++;
		count++;
	}
	cout<<count;
	return 0;
}