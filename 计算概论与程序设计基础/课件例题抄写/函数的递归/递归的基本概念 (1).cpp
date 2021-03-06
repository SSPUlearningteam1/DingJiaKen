#include <iostream>
#include <cmath>
using namespace std;
bool checkPrime(int);
int main()
{
	int a;
	cout<<"请输入一个整数"<<endl;
	while(cin >> a)
	{
		if(checkPrime(a))
			cout<<"是质数"<<endl;
		else
			cout<<"不是质数"<<endl;
	}
	return 0;
}

bool checkPrime(int number)
{
	int i, k;
	k = sqrt(number); //根据初等数论只需要计算到sqrt(number)就可以了
	for (i = 2; i <= k; i++)
	{
		if (number % i == 0)
			return 0;   	//只要有一个数被除尽
			                //则不是素数
	}
	return 1;
}