//有史以来最啰嗦得程序，我得拿大刀砍一砍
#include <iostream>
using namespace std;
bool check_repeat(int mark[], int sum);
void find_cube(int n);

int main()
{
	int N = 0;
	cin>>N;
	
	for (int i = 2; i <= N; i++)  //这里，主函数显得毫无意义
		find_cube(i);
	
	return 0;
}

void find_cube(int a)
{
	int mark[100] = {0};
	int count = 0;
	
	for(int b = 2; b < a; b++)  //这里，因为初始量定义得很笨，导致后面会出现重复数，使得步骤变得啰嗦
		for(int c = 2; c < a; c++)  //事实上，使得int c = b, d = c（或者上一个数+1）会有奇效
			for(int d = 2; d < a; d++)
				if( b*b*b + c*c*c +d*d*d == a*a*a)  //本来我还更蠢地写了一个只用一次的pow函数
				{
					if( check_repeat(mark,(b*c*d)) )
						continue;
					else
					{
						mark[count++] = b * c * d;
						cout<<"Cube = "<<a<<", Triple = ("<<b<<','<<c<<','<<d<<')'<<endl;
					}
				}
}


bool check_repeat(int mark[], int sum)  //充分显示了我的蠢的一个函数
{
	for(int i = 0; mark[i] != 0; i++)
		if (mark[i] == sum)
			return true;
		
	return false;
}