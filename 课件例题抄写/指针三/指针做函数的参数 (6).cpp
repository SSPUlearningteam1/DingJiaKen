#include <iostream>
using namespace std;
int main()
{
	int a = 256;
	const int *p = &a;
//  *p = 257;  ����Ĳ���
    cout<<*p<<endl;
	return 0;
}