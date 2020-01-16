#include <iostream>
using namespace std;
int main()
{
	char a[10][10];
	int n = 0;
	cin>>n;
	cin.get(); //Ìí¼ÓÒ»ÌõÓï¾ä
	for (int i = 0; i < n; i++)
		cin.getline(a[i],10);
	for (int i = 0; i < n; i++)
        cout<<a[i]<<endl;
    return 0;	
}