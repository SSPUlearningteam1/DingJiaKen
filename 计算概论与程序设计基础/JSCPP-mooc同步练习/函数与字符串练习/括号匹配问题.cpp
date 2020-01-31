//迷之零分答案，样例完全对，结果得零分？一脸黑人问号
#include <iostream>
#include <cstring>
using namespace std;
void find_unmatching();

int main()
{
	int n = 0;
	cin>>n;
	cin.get(); //读走回车
	
	for(int i = 0; i < n; i++)
	{
		find_unmatching();
	}
	
	return 0;
}

void find_unmatching()
{
	char str_origin[101] = {'\0'};
	cin.getline(str_origin,101,'\n');
	
	char str[101] = {'\0'};  //我的写法会对字符串产生破坏，故这里复制一个副本
	strcpy(str,str_origin);
    
	char *p_check = &str[0]; //指针变量，具体指向参考变量名
	char *p_left = &str[0];
	char *p_right = &str[0];
	int flag_left = 0;  //标识变量，分别为找到左括号，找到在左括号右边的右括号。
	int flag_right = 0; 
	
	//找到所有的成对括号
	while(1)
	{
		//寻找左括号,找到str[0]右边第一个左括号为止
		for(p_check = &str[0]; *p_check != '\0'; p_check++)
            if(*p_check == '(')
		    {
			    p_left = p_check;
			    flag_left = 1;
				break;
			}
		
        //寻找右括号，前提是有左括号。找到左括号右边第一个右括号为止	
		if(flag_left ==1)
			for(p_check = p_left; *p_check != '\0'; p_check++) //从左括号开始遍历
				if(*p_check == ')')
				{
					p_right = p_check;
					flag_right = 1;
					break;
				}
		
		//匹配最短距离的一对括号，前提是存在至少一对符合条件的左右括号
        //这里是找到右括号左边的第一个左括号
		if(flag_right == 1)
		{
			for(p_check = p_right;  ; p_check--)
				if(*p_check == '(')
				{
					p_left = p_check;
					break;
				}
		}
		
		if(flag_left == 1 && flag_right == 1)
		{
			*p_left = ' '; //删除这对括号
			*p_right = ' ';
			
			p_check = &str[0]; //全部清零
			p_left = &str[0];
			p_right = &str[0];
			flag_left = 0;
			flag_right = 0;
			
			continue;  //继续处理
		}
		else  //找不到成对括号了,处理完毕
		    break;
	}
	
	//开始打印
	cout<<str_origin<<endl;
	for(p_check = &str[0]; *p_check != '\0'; p_check++)
	{
		if(*p_check == '(')
			cout<<'$';
		else if(*p_check == ')')
			cout<<'?';
		else
			cout<<' ';
	}
	cout<<endl;
}