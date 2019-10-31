//根本就停不下来
#include <iostream>
using namespace std;
int main()
{
	char c;
	cout<<"enter a sentence:"<<endl;
	while (c = getchar())
		cout<<c;
	return 0;
}