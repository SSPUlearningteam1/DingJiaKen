//����
#include <iostream>
using namespace std;
void move(int m, char x, char y, char z)
{
	if (m == 1)
	{
		cout<<"��һ�����Ӵ�"<<x<<"�ƶ���"<<z<<endl;
	}
	else
	{
		move(m-1,x,z,y); //��m-1ֻ�����Ƶ���ת������
		cout<<"��һ�����Ӵ�"<<x<<"�ƶ���"<<z<<endl; //�����һ�������Ƶ�Ŀ��������
		move(m-1,y,x,z);  //��m-1ֻ�����Ƶ�Ŀ��������
	}
}
int main()
{
	int n;
	cout<<"����������n = ";
	cin>>n;
	cout<<"�������������ƶ�"<<n<<"ֻ�̵Ĳ���Ϊ:"<<endl;
	move(n,'A','B','C');
	return 0;
}