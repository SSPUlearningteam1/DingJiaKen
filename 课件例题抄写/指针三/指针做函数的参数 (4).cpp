#include <iostream>
using namespace std;
int main()
{
	const float PI = 3.14159f; //float const PI = 3.14159f;
	float r;
	cout<<"请输入半径r:";
	cin>>r;
	cout<<"圆面积为:"<<PI*r*r<<endl;
	return 0;
}