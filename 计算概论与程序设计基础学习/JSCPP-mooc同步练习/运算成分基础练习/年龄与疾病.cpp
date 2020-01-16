#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n = 0;
	int num = 0;
	double level_1 = 0;
	double level_2 = 0;
	double level_3 = 0;
	double level_4 = 0;
	double sum = 0;
	
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		cin>>num;
		if (num <= 18)
			level_1++;
		else if (18 < num && num <= 35)
		    level_2++;
		else if (35 < num && num <= 60)
		    level_3++;
		else if (60 < num)
			level_4++;
	}
	
	sum = level_1 + level_2 + level_3 + level_4;
	
	cout<<"1-18: "<<fixed<<showpoint<<setprecision(2)<<(level_1/sum*100)<<"%"<<endl;
	cout<<"19-35: "<<(level_2/sum*100)<<"%"<<endl;
	cout<<"36-60: "<<(level_3/sum*100)<<"%"<<endl;
	cout<<"Over60: "<<(level_4/sum*100)<<"%"<<endl;
	
	return 0;
}