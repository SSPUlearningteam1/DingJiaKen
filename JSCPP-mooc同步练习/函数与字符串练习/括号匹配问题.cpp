//��֮��ִ𰸣�������ȫ�ԣ��������֣�һ�������ʺ�
#include <iostream>
#include <cstring>
using namespace std;
void find_unmatching();

int main()
{
	int n = 0;
	cin>>n;
	cin.get(); //���߻س�
	
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
	
	char str[101] = {'\0'};  //�ҵ�д������ַ��������ƻ��������︴��һ������
	strcpy(str,str_origin);
    
	char *p_check = &str[0]; //ָ�����������ָ��ο�������
	char *p_left = &str[0];
	char *p_right = &str[0];
	int flag_left = 0;  //��ʶ�������ֱ�Ϊ�ҵ������ţ��ҵ����������ұߵ������š�
	int flag_right = 0; 
	
	//�ҵ����еĳɶ�����
	while(1)
	{
		//Ѱ��������,�ҵ�str[0]�ұߵ�һ��������Ϊֹ
		for(p_check = &str[0]; *p_check != '\0'; p_check++)
            if(*p_check == '(')
		    {
			    p_left = p_check;
			    flag_left = 1;
				break;
			}
		
        //Ѱ�������ţ�ǰ�����������š��ҵ��������ұߵ�һ��������Ϊֹ	
		if(flag_left ==1)
			for(p_check = p_left; *p_check != '\0'; p_check++) //�������ſ�ʼ����
				if(*p_check == ')')
				{
					p_right = p_check;
					flag_right = 1;
					break;
				}
		
		//ƥ����̾����һ�����ţ�ǰ���Ǵ�������һ�Է�����������������
        //�������ҵ���������ߵĵ�һ��������
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
			*p_left = ' '; //ɾ���������
			*p_right = ' ';
			
			p_check = &str[0]; //ȫ������
			p_left = &str[0];
			p_right = &str[0];
			flag_left = 0;
			flag_right = 0;
			
			continue;  //��������
		}
		else  //�Ҳ����ɶ�������,�������
		    break;
	}
	
	//��ʼ��ӡ
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