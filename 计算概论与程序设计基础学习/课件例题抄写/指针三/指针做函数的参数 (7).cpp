#include <iostream>
using namespace std;
int main()
{
	const int a = 78; const int b = 28; int c = 18;
    const int *pi = &a;
// *pi = 58; (error,*p���ܱ���ֵ)
    pi = &b; //(���Ը�pi���¸�ֵ)
// *pi = 68; (error)
    pi = &c;
// *pi = 88; (error,*p���ܱ���ֵ)
    cout<<c;
    return 0;	
}