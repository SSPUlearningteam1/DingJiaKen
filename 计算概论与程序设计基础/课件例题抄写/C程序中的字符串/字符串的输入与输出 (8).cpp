#include <iostream>
using namespace std;
int main()
{
	char weekday[7][11] = {"Sunday","Monday",
	"Tuesday","Wednesday","Thursday","Friday","Saturday"};
	for (int i = 0; i <7; i++)
        cout<<weekday[i]<<endl;
	return 0 ;
}