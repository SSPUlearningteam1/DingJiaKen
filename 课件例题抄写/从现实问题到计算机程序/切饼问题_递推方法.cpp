#include <iostream>
using namespace std;
int main()
{
	int blockCount = 0;
	int i = 0,N = 0;
	cin>>N;
	blockCount = 1;
	for(i = 1; i <= N; i++)
		blockCount = blockCount + i;
	cout<<"最多可切"<<blockCount<<"块"<<endl;
	return 0;
}

//本题用循环语句，用递推的方法写出
//调试的时候发现出现一个拼写错误，main函数打错,导致程序无法返回0值，编译报错