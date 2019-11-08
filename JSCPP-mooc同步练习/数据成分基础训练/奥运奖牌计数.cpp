#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	int sum = 0;
	int gold = 0;
	int silver = 0;
	int copper = 0;
	int temp = 0;
	
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		gold += temp;
		
		cin>>temp;
		silver +=temp;
		
		cin>>temp;
		copper += temp;
	}
	
	sum = gold + silver + copper;
	
	cout<<gold<<" "<<silver<<" "<<copper<<" "<<sum;
	
	return 0;
}