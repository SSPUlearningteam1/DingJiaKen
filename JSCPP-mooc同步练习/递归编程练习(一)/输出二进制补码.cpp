//从网上看了递归输出二进制的方案，我这好像算抄了...
//我起码得表示一下，嗯，用循环来写...
//达成成就：openjudge通过，jscpp不通过（卡时间？）
//有空重写
#include <iostream>
using namespace std;
int main()
{
	int digit[31] = {0};
	char str[11] = {'\0'};
	int num = 0;
    while(1)
	{
		cin.getline(str,12,'\n');
		if( ('a' <= str[0] && str[0] <= 'z') || ('A' <= str[0] && str[0] <= 'Z') )
            break;
        else
			num = atof(str);

		for(int i = 0; i < 32; i++)
		{
			digit[31-i] = abs(num % 2);
			num >>= 1; 
			if(num == 0)
				break;
		}
		
		for(int i = 0; i < 32; i++)
			cout<<digit[i];

        cout<<endl;
	}
	
	return 0;
	
}