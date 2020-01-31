#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int teacher[21][13];
	int school, department;
	int i, j;
	char name[30];
	
	for(i = 0; i < 1000; i++)
	{
		cin>>name>>school>>department;
		teacher[school][department]++;
	}
	
	for (i = 1; i < 21; i++)
		for (j = 1; j = 13; j++)
			cout<<setw(4)<<teacher[i][j];
		cout<<endl;
		return 0;
}