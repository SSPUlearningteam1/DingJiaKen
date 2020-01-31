#include <iostream>
using namespace std;
void change(int []);

int main()
{
	int num[10] = {0};
	change(num);
	
	for(int i = 0; i < 10; i++)
		cout<<num[i]<<" ";
	return 0;
}

void change(int num[])
{
	for(int i = 0; i < 10; i++)
		num[i] = i;
}