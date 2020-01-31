#include <iostream>
using namespace std;
int main()
{
	int chicken = 0;
	int rabbit = 0;
	int heads = 0;
	int feet = 0;
	
	cin>>heads>>feet;
	
	for(rabbit = 0; rabbit <= heads; rabbit++)
	{
		chicken = heads - rabbit;
		if(4*rabbit + 2*chicken == feet)
			cout<<chicken<<" "<<rabbit;
	}
			
	return 0;
}