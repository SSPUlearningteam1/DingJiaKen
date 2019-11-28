//又是一篇openjudge说好但是jscpp不给过的代码
//可读性极差，能用不能看，当作指针练手算了。
//我会另外收录一篇有参考价值的代码
#include <iostream>
using namespace std;
int main()
{
	char str[120] = {'\0'};
	cin.getline(str,119,'\n');
	
	char key_str[120] = {'\0'};
	cin.getline(key_str,119,'\n');
	
	char rp_str[120] = {'\0'};
	cin.getline(rp_str,119,'\n');
	
	char *p_check = &str[0];
	char *p_head = &str[0];
	char *p_key = &key_str[0];
	int words_flag = 1;
    int key_flag = 0;
	while(1)
	{
		if(*p_check != ' ' && *p_check != '\0')
		{
			if(words_flag == 0)
			{
				p_head = p_check;
				cout<<' ';
				words_flag = 1;
			}
			
			if(words_flag == 1)
			{
			    if(*p_check == *p_key)
			    {
				    p_key++;
					if(key_flag == 0)
					{
				        key_flag = 1;
					}
			    }
			    else if(*p_check != *p_key && key_flag == 1)
			    {
				    key_flag = 0;
			    }
			}
		}
		else if(*p_check == ' ' || *p_check == '\0')
		{
			
			if(words_flag == 1)
			{
				if(*p_key != '\0')
					key_flag = 0;  //确保长度相同
				
				if(key_flag == 0)
					for(; p_head != p_check; p_head++)
						cout<<*p_head;
				else if(key_flag == 1)
				{
					for(int i = 0; rp_str[i] != '\0'; i++)
						cout<<rp_str[i];
				}

                p_key = &key_str[0];//每次打印完一个数后再进行归零操作
				key_flag = 0;
                words_flag = 0;
			}
		}

        if(*p_check == '\0')
            break;
        else
          	p_check++;		
	}
	
	return 0;
}