#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char num[10] = {'\0'};
	char num_IO[10] = {'\0'};
	
	cin.getline(num,10,'\n');
	
	int i = 0;
	for(i = 0; num[i] != '\0'; i++);
	for(int j = 0; j != i; j++)
		num_IO[j] = num[i-1-j];
	
	if(strcmp(num,num_IO) == 0)
		cout<<"yes";
	else
		cout<<"no";
	
	return 0;
		
}