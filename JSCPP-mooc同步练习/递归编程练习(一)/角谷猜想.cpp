//µİ¹é²»´æÔÚµÄ
#include <iostream>
using namespace std;
int main()
{
	int num = 0;
	int result = 0;
	cin>>num;
	while(num != 1)
	{
		if(num % 2 != 0)
		{
			result = num*3+1;
			cout<<num<<"*3+1="<<result<<endl;
			num = result;
		}
		else
		{
			result = num/2;
			cout<<num<<"/2="<<result<<endl;
			num = result;
		}
	}
	
	cout<<"End";
	
	return 0;
}