//�ӱ��⿪ʼ��̤����ָ��Ĳ���·

/*˵���������ַ���"     i am a    student   ",
        ��Ч����Ϊ"i am a    student",
		���ӡΪ  "student    a am i";
		
		�����ַ���" i ",
		��Ч����Ϊ"i",
		���ӡΪ"i";
*/
#include <iostream>
using namespace std;
int main()
{
	char str[105] = {'\0'};
	cin.get(str,100,'\n');
	
	int flag = 0;  /*��Ϊ1���е��ʵȴ���ӡ����Ϊ0���пո�ȴ���ӡ��
	               �ñ������Ч�ַ���֮��������*/
	int begin = 0; //ϸ��һ���ж���Ч�ַ����Ŀ�ʼ
	char *p_now = &str[99];
	char *p_print = &str[99];
	while(1) //��д���ؼ�ϸ���� 1)ȥ��ĩβ�Ŀո� 2)����һ�����ʶ���д��Ҫ��������
	{
		if(*p_now == ' ' && flag == 1)
		{
			flag = 0;
			for(p_print = p_now + 1; (*p_print != ' ' && *p_print != '\0'); p_print++)
				cout<<*p_print;
		}
		//��ӡӢ����ĸ�Ĳ���
		
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
		//��ӡ�ո�Ĳ���
		
		if(p_now == &str[0] && *p_now != ' ')  //ϸ�ڶ�����������
		{
			for(p_print = p_now; (*p_print != ' ' && *p_print != '\0'); p_print++)
				cout<<*p_print;
		}
			
        if(p_now == &str[0])
			break;
		else
		    p_now--;
		//����ѭ��������Ĳ���
	}
	
	return 0;
}