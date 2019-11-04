//懂了
#include <iostream>
using namespace std;
void move(int m, char x, char y, char z)
{
	if (m == 1)
	{
		cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl;
	}
	else
	{
		move(m-1,x,z,y); //把m-1只盘子移到中转柱子上
		cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl; //把最后一个盘子移到目标柱子上
		move(m-1,y,x,z);  //把m-1只盘子移到目标柱子上
	}
}
int main()
{
	int n;
	cout<<"请输入盘数n = ";
	cin>>n;
	cout<<"在三根柱子上移动"<<n<<"只盘的步骤为:"<<endl;
	move(n,'A','B','C');
	return 0;
}