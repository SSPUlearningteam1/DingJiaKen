//openjudge都说好，jscpp不给过
#include <iostream>
#include <cstring>
using namespace std;
void sort_str();

int main()
{
	int t = 0;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		sort_str();
	}
	return 0;
}

void sort_str()
{
	char str[105][210] = {'\0'};
	int n = 0;
	cin>>n;
	cin.get();
	
	for(int i = 0; i < n; i++)
		cin.getline(str[i],210,'\n');
	
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if( strcmp(str[i],str[j]) > 0 )
			{
				char temp[210] = {'\0'};
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
	
	for(int i = 0; i < n; i++)
		cout<<str[i]<<endl;
	
	cout<<endl;
}