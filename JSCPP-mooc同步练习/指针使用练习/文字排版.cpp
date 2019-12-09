//openjude满分，jscpp判错
#include <iostream>
using namespace std;

struct WORD
{
	char str[45];
	int length;
};

int get_length(char str[])
{
	char *p = &str[0];
	int length = 0;
	for(length = 0; *p != '\0'; p++,length++);
	
	return length;
}

int main()
{
	int n = 0;
	cin>>n;
	cin.get();
	
	WORD word[300] = {{{'\0'},0}};  //定义结构体数组储存单词
	int i = 0;
	for(i = 0; i < n-1; i++)        //前n-1个遇到空格终止
	{
		cin.getline(word[i].str,45,' ');
		word[i].length = get_length(&word[i].str[0]);  //计算长度
	}
	cin.getline(word[i].str,45,'\n');    //第n个字符串遇到回车终止
	word[i].length = get_length(&word[i].str[0]);
	
	//结束录入
	
    int count = 0;  //计数变量，计量每行的字符数
	int flag_blank = 0; //控制空格的打印
	for(i = 0; i < n; i++)
	{
		while(1)
		{
			if(flag_blank == 0)
				count += word[i].length;  //第一个单词，仅有单词本身长度
			else
				count += (word[i].length + 1);  //一个空格加单词的长度
			
		    if(count <= 80)
		    {
			    if(flag_blank == 0)
				   flag_blank = 1;
			    else
				   cout<<' ';
			
			    cout<<word[i].str;
				break;//打印一个单词成功
		    }
		    else
		    {
				cout<<endl; //换行
			    count = 0;
				flag_blank = 0;
				continue;   //到下一行打印这个单词
		    }
		}
	}
	
	return 0;
	
}