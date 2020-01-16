//普通方法求素数
#include <iostream>
using namespace std;
int main()
{
	bool prime = true;
	for (int i = 2; i < 100; i++)//有改动，int i = 0改为int i = 2,否则打印出的数据将会存在0和1
	{
		prime = true;
		for (int j = 2; j < i; j++)
		{
			if(i%j == 0)
				prime = false;
		}
        if (prime == true)
                cout<<i<<endl;			
	}
	return 0;

}