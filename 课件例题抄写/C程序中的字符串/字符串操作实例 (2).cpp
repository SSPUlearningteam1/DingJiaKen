#include <iostream>
#include <cstring> //编译器提示头文件名为cstring,而不是string
using namespace std;
int main()
{
	char str1[20], str2[20];
	cin.getline(str1,20);
	strcpy(str2,str1);
	cout<<str1<<endl; //数组名就是字符串名
	cout<<str2<<endl;
    return 0;
}
