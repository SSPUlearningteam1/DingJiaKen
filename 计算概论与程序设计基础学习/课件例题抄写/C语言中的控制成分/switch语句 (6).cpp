#include <iostream>
using namespace std;
int main()
{
	int score,num;
	cout<<"Please give the score"<<endl;
	cin>>score;
	num = score/10;
	switch(num)
	{
		case 10:cout<<"A"<<endl;
	    case 9:cout<<"A"<<endl;
		case 8:cout<<"B"<<endl;
		case 7:cout<<"C"<<endl;
		case 6:cout<<"D"<<endl;
		default :cout<<"E"<<endl;
	}
	return 0;
}