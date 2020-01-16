#include <iostream>
using namespace std;
int main()
{
	char weekday[7][11];
	for(int i = 0; i < 7; i++)
		cin.getline(weekday[i],11);
	for(int i = 0; i < 7; i++)
		cout<<weekday[i]<<endl;
	return 0;
}