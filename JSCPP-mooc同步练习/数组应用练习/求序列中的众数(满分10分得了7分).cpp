//�����ˣ�������վ����10�ָ���7�֣������˺ü�����
#include <iostream>
using namespace std;
void num_fix(char *, char *);
void find_mode(char (*)[60], int);

int main()
{
	int n = 0;
	cin>>n;
	if(n < 0 || n > 128)
		cout<<"no";
	else
	{
	cin.get();
	
	int count = 0;
	char num[128][60] = {'\0'};
	char num_temp[500] = {'\0'};
	while(1)
	{
		cin.getline(num_temp, 500,'\n');
		
		if(num_temp[0] == '\0')  //�жϸ����Ƿ�Ϊ����
		    continue;
		else
		{
			num_fix(&num_temp[0], &num[count++][0]);  //�����������ʽ����
			for(int i = 0; i < 500; i++)
				num_temp[i] = '\0';  //��ʱ�������
		}
		
		if(count == n)
			break;	
	}
	
	find_mode(num,n);
	}
	
	return 0;
	
}

void num_fix(char *num_temp, char *num)
{
	char *p_check = &num_temp[0];
	
	int check_if_zero = 1;
	while(1)  //�������Ƿ�Ϊ0
	{
		if('0' < *p_check && *p_check <= '9')  //���Ϊ������
		{
			check_if_zero = 0;
			break;
		}
		else
			p_check++;
		
		if(*p_check == '\0')
			break;
	}
	//0�Ĵ���
	if(check_if_zero == 1)
	{
		num[0] = '0';  //����ʽ�����鸳ֵ��
	}
	else if(check_if_zero == 0)
	{
		p_check = &num_temp[0]; //ָ�����
		
		int check_sign = 0;  //ͨ��������Ԫ���ж�������
		if( *p_check == '+' || ('0' <= *p_check && *p_check <= '9') )
			check_sign = 1;  //Ϊ����
		else if(*p_check == '-')
		    check_sign = 0;  //Ϊ����
		
		//��ʼ�������0���д���
		if(check_sign == 1)
		{
			while(1)  //ָ���ƶ�������������
			{
				if( ('0' < *p_check && *p_check <= '9') && *p_check != '+' )//����������
				    break;
			    else
					p_check++;
			}
			//��ʼ��ֵ������Ԫ�ؿ�ʼ��
			for(int i = 0; *p_check != '\0'; i++, p_check++)
				num[i] = *p_check;
		}
		else if(check_sign == 0)
		{
			num[0] = '-';  //��Ԫ�ظ�ֵΪ����
			while(1)  //ָ���ƶ�������������
			{
				if( ('0' < *p_check && *p_check <= '9' ) && *p_check != '-')//����������
				    break;
			    else
					p_check++;
			}
			//��ʼ��ֵ���ӵڶ���Ԫ�ؿ�ʼ��
			for(int i = 1; *p_check != '\0'; i++, p_check++)
				num[i] = *p_check;
		}
		
	}
		/*
		�˺����������б�ʾ0���ַ���������Ϊ'0';
		����������ʾΪ'123'(ʾ��)����ʽ;
		���и�����ʾΪ'-123'����ʽ;
		*/
}

void find_mode(char (*num)[60], int n)
{
	char *p_now = &num[0][0];
	char *p_next = &num[1][0];
	char mode[60] = {'\0'};
	int count_now = 1;
	int count_max = 1;
	
	for(int i = 0; i < n-1; i++)  //i��Ӧnow
	{
		count_now = 1;  //��ǰ������һ
		for(int j = i+1; j < n; j++)  //j��Ӧnext
		{
			p_now = &num[i][0];
			p_next = &num[j][0]; //ָ���ʼ��
			
			int flag = 1;
			while(1)
			{
				if(*p_now != *p_next)
				{
					flag = 0;
					break;
				}
				else
				{p_now++; p_next++;}
			
			    if(*p_now == '\0' || *p_next == '\0')  //����ͷ
                    break;					
			}
			
			if(flag == 0) //��ͬ��
				continue;
			else if(flag == 1)  //��ͬ��
			{
				count_now++;
				if(count_max < count_now)
				{
					count_max = count_now;
					for(int u = 0; u < 60; u++)
						mode[u] = num[i][u];
				}
			}
		}
	}
	
	//�������������ҳ������������ڿ�ʼ��ӡ
	
	if(count_max == 1 || count_max == n)
		cout<<"no";
	else
		cout<<mode;
}

