#include <iostream>
using namespace std;
int main()
{
	char str[1001] = {'.'};
	cin.get(str,1000,'\n');
	
	char *p_check = &str[0];
	char *p_head = &str[0];
	int  flag = 0;
	int max = 0;
	int count  = 0;
	
	while(1)
	{
		if(*p_check != ' ' && *p_check != '.')
		{
			if(flag == 0)
			{
				count++;
			    flag = 1;
			}
			else if(flag == 1)
				count++;
		}
		else if(*p_check == ' ' || *p_check == '.')
		{
			if(flag == 1)
			{
			    if(max < count)
				    max = count;
			
			    count = 0;
			    flag = 0;
			}
			
			if(*p_check == '.')
				break;
		}
		
		p_check++;
		
	}
	//ͨ���������룬���ǵõ����ַ���������ʵĳ���Ϊmax
	
	p_check = &str[0];
	flag = 0;
	count = 0;//���㸴λ
	while(1)
	{
		if(*p_check != ' ' && *p_check != '.')
		{
			if(flag == 0)
			{
				p_head = p_check;
				count++;
				flag = 1;
			}
			else if(flag == 1)
				count++;
		}
		else if( (*p_check == ' ' || *p_check == '.') && flag == 1)
		{
			if(count == max)
			{
				for( ;p_head != p_check; p_head++)
					cout<<*p_head;
				
				break;
			}
			else
			{
				count = 0;
				flag = 0;
			}
		}
		
		p_check++;
	}
	//ͨ���������룬���Ǵ�ӡ���˵�һ������󳤶ȵĵ���
	
	return 0;
}