#include <iostream>
using namespace std;
struct fraction;
fraction add(fraction, fraction);
int f_gcd (int, int);

struct fraction  //�����ṹ��
{
	int n_or ; //����
	int d_or;  //��ĸ
};

int main()
{
	int n = 0;
	fraction f_1 = {0,0};
	fraction f_2 = {0,0};
	
	cin>>n;
	
	for(int i = 0; i < n; i++)  //�ۼ�n��
	{
		if (f_1.n_or != 0) //�����Ϊ��һ�ζ�ȡ����
		{
			cin>>f_2.n_or;  //��ȡ����
		    cin.get();  //���߳���
			cin>>f_2.d_or;  //���߷�ĸ
			
		    f_1 = add(f_1,f_2); //�˴������ۼӲ���
		} 
		
		else  //��һ�ζ�ȡ����
		{
			cin>>f_1.n_or;
		    cin.get();
			cin>>f_1.d_or;
		}
			
	}
	
	if(f_1.d_or != 1)  //����ۼӽ����ĸ��Ϊ1
		cout<<f_1.n_or<<"/"<<f_1.d_or;
	else               //����ۼӽ����ĸΪ1
		cout<<f_1.n_or;
	
	return 0;
}

fraction add(fraction f_1, fraction f_2)
{
	fraction f_r = {0,0};  //�������
	
	f_r.d_or = f_1.d_or * f_2.d_or ;  //��ĸͨ��
	f_r.n_or = (f_1.n_or * f_2.d_or) + (f_2.n_or * f_1.d_or);  //�������ĸͨ�ֺ����
	
	int gcd = 0;  //�����������ӷ�ĸ�����Լ��
	gcd = f_gcd(f_r.n_or , f_r.d_or);
	
	f_r.n_or /= gcd;  //Լ��
	f_r.d_or /= gcd;
	
	return f_r;
}

int f_gcd (int num1, int num2)
{
	int temp = 0;
	if(num1 < num2)  //ʹnum1 > num2
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	
	int gcd = 1;
	for(int i = 1; i <= num2; i++)
	{
		if ((num1 % i == 0) && (num2 % i == 0))
			gcd = i;
	}
	
	return gcd;
}