#include <iostream>
using namespace std;
bool get_num (int count, int n)
{
	switch (count)
	{
		case 0: count = 100; break;
		case 100: count = 50; break;
		case 50: count = 20; break;
		case 20: count = 10; break;
		case 10: count = 5; break;
		case 5: count = 1;break;
		case 1: return true;
	}
	
	int temp = 0;
	temp = n/count;
	if(temp != 0)
	{
		cout<<temp<<endl;
		if(get_num(count, (n%count)))
			return true;
	}
	else if(temp == 0)
	{
		cout<<0<<endl;
		if(get_num(count, n))
			return true;
	}
	
	return true;
}

int main()
{
	int n = 0;
	int count = 0;
	cin>>n;
	if(get_num(count,n))
		return 0;
	else
		return 0;
}