//从本题开始我踏上了指针的不归路

/*说明：形如字符串"     i am a    student   ",
        有效部分为"i am a    student",
		需打印为  "student    a am i";
		
		形如字符串" i ",
		有效部分为"i",
		需打印为"i";
*/
#include <iostream>
using namespace std;
int main()
{
	char str[105] = {'\0'};
	cin.get(str,100,'\n');
	
	int flag = 0;  /*若为1，有单词等待打印，若为0，有空格等待打印；
	               该标记在有效字符串之外无意义*/
	int begin = 0; //细节一，判断有效字符串的开始
	char *p_now = &str[99];
	char *p_print = &str[99];
	while(1) //本写法关键细节是 1)去除末尾的空格 2)若第一个单词顶格写，要进行特判
	{
		if(*p_now == ' ' && flag == 1)
		{
			flag = 0;
			for(p_print = p_now + 1; (*p_print != ' ' && *p_print != '\0'); p_print++)
				cout<<*p_print;
		}
		//打印英文字母的部分
		
		if(*p_now != ' ' && *p_now != '\0' && flag == 0)
		{
			if(begin == 0)
			{
				begin = 1;
				flag = 1;
			}
			else
			{
				flag = 1;
				for(p_print = p_now + 1; *p_print == ' '; p_print++)
					cout<<' ';
			}
		}
		//打印空格的部分
		
		if(p_now == &str[0] && *p_now != ' ')  //细节二，进行特判
		{
			for(p_print = p_now; (*p_print != ' ' && *p_print != '\0'); p_print++)
				cout<<*p_print;
		}
			
        if(p_now == &str[0])
			break;
		else
		    p_now--;
		//进行循环或结束的部分
	}
	
	return 0;
}