//枚举使我快乐
#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	cin>>n;
	
	int num[100] = {0};
	for(int i = 0; i < n; i++)
		cin>>num[i];
	
	int num_RO[100] = {0};
	for(int i = 0; i < n; i++)
	    num_RO[n-1-i] = num[i];
	
	cout<<num_RO[0];  //解决格式问题，第一个元素手动打印
	for(int i = 1; i < n; i++)
		cout<<' '<<num_RO[i];
	
	return 0;
}