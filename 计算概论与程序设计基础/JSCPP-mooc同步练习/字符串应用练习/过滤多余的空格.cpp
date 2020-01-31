#include <iostream>
using namespace std;
int main()
{
	char str[201] = {'\0'};
	cin.get(str,200,'\n');
	
	char *p_check = &str[0];
	char *p_head = &str[0];
    int flag = 1;
	while(1)
	{
		if( (*p_check == ' ' || *p_check == '\0') && flag ==1 )
		{
			for(; p_head != p_check; p_head++)
				cout<<*p_head;
			
			flag = 0;
			
			if(*p_check == '\0')
				break;
		}
		
		if( *p_check != ' ' && flag == 0)
		{
			cout<<' ';
			p_head = p_check;
			flag = 1;
		}
		
		p_check++;
	}
	
	return 0;
}
