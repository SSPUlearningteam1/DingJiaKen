#include <iostream>
using namespace std;
struct fraction;
fraction add(fraction, fraction);
int f_gcd (int, int);

struct fraction  //分数结构体
{
	int n_or ; //分子
	int d_or;  //分母
};

int main()
{
	int n = 0;
	fraction f_1 = {0,0};
	fraction f_2 = {0,0};
	
	cin>>n;
	
	for(int i = 0; i < n; i++)  //累加n次
	{
		if (f_1.n_or != 0) //如果不为第一次读取分数
		{
			cin>>f_2.n_or;  //读取分子
		    cin.get();  //读走除号
			cin>>f_2.d_or;  //读走分母
			
		    f_1 = add(f_1,f_2); //此处进行累加操作
		} 
		
		else  //第一次读取分数
		{
			cin>>f_1.n_or;
		    cin.get();
			cin>>f_1.d_or;
		}
			
	}
	
	if(f_1.d_or != 1)  //如果累加结果分母不为1
		cout<<f_1.n_or<<"/"<<f_1.d_or;
	else               //如果累加结果分母为1
		cout<<f_1.n_or;
	
	return 0;
}

fraction add(fraction f_1, fraction f_2)
{
	fraction f_r = {0,0};  //结果分数
	
	f_r.d_or = f_1.d_or * f_2.d_or ;  //分母通分
	f_r.n_or = (f_1.n_or * f_2.d_or) + (f_2.n_or * f_1.d_or);  //分子随分母通分后相加
	
	int gcd = 0;  //求结果分数分子分母的最大公约数
	gcd = f_gcd(f_r.n_or , f_r.d_or);
	
	f_r.n_or /= gcd;  //约分
	f_r.d_or /= gcd;
	
	return f_r;
}

int f_gcd (int num1, int num2)
{
	int temp = 0;
	if(num1 < num2)  //使num1 > num2
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