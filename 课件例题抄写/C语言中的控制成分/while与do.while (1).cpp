#include <iostream>
using namespace std;
int main()
{
	int i, sum = 0;
	i = 1;
	while (i <= 100)
	{
		sum = sum + i;
		i++;
	}
	cout<<sum<<endl;
	return 0;
}