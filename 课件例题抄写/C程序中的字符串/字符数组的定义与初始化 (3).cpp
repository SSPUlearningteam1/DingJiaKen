/*
目测可行的定义方法，但是这种操作有时会造成未定义行为，
在我电脑里，只要字符数组长度短于7
时，就会有有乱码输出
*/

#include <iostream>
using namespace std;
int main()
{
	char a[] = {"China"};
	for (int i  = 0; i < 10; i++)
		cout<<a[i];
	return 0;
}