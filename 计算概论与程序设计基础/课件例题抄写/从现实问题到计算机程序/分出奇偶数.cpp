//分出奇偶数
#include <iostream>
using namespace std;
int main()
{
	int all[10], odd[10], even[10];//odd记录奇数，even记录偶数
	int i = 0, j = 0;    //i,j为循环计数变量
	for (; i < 10; i++)  //输入10个数
	        cin>> all[i];
	int numOdd = 0;
    int numEven = 0;
	for (i = 0; i < 10; i++)  //遍历数组all，奇数放入odd,偶数放入even
	{
		if (all[i]%2 != 0)  //奇数
		{
			odd[numOdd] = all[i];
			numOdd++;
		}
		else  //偶数
		{
			even[numEven] = all[i];
			numEven++;
		}
	}
	for (i = 0; i < numOdd; i++)//输出奇数
	        cout<<odd[i]<<" ";
			cout<<endl;//这行我自己加的
    for (i = 0; i < numEven; i++)//输出偶数
            cout<<even[i]<<" ";
    return 0;
}	
			

//时刻注意数组名从0开始
//注意计数变量i,j,numOdd,numEven
//程序中对计数变量i的每次重新利都会进行重新赋值
//我不知道定义干嘛，我觉得程序会报错
//注意遍历分组时的程序写法