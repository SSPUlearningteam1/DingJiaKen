#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double n = 0;
	double a = 0, b = 0, c = 0;
	double p = 0;
	double s = 0;
	int flag = 0;
	
	 cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b>>c;
		
		p = (a + b + c) / 2;
		s = sqrt((p*(p-a)*(p-b)*(p-c)));
		
		if (flag == 1)
			cout<<endl;
		else
			flag = 1;
			
		
		cout<<fixed<<showpoint<<setprecision(2)<<s;
		
	}
	
	return 0;
}
