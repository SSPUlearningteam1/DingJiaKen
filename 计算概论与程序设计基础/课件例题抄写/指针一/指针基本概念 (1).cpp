#include <iostream>
using namespace std;
int main()
{
	int iCount = 18;
	int *iPtr = &iCount;
	*iPtr = 58;
	cout<<iCount<<endl;
	cout<<iPtr<<endl;
	cout<<&iCount<<endl;
	cout<<*iPtr<<endl;
	cout<<&iPtr<<endl;
	return 0;
}