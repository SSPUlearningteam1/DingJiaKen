#include <iostream>
#include <cmath>
using namespace std;
bool checkPrime(int);
int main()
{
	int a;
	cout<<"������һ������"<<endl;
	while(cin >> a)
	{
		if(checkPrime(a))
			cout<<"������"<<endl;
		else
			cout<<"��������"<<endl;
	}
	return 0;
}

bool checkPrime(int number)
{
	int i, k;
	k = sqrt(number); //���ݳ�������ֻ��Ҫ���㵽sqrt(number)�Ϳ�����
	for (i = 2; i <= k; i++)
	{
		if (number % i == 0)
			return 0;   	//ֻҪ��һ����������
			                //��������
	}
	return 1;
}