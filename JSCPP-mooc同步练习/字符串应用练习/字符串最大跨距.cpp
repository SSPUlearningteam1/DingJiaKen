//��һ��openjudge��վAccepted����mooc�������������Ҵ𰸵Ĵ���
//ԭ����վ��ͨ���ˣ����Ҿ���ͨ����==!
#include <iostream>
using namespace std;
char *moveto_tail(char *);
char *find_S1( char *, char *);
char *find_S2( char *, char *,  char *);

int main()
{
	char S[350] = {'\0'};
	char S1[15] = {'\0'};
	char S2[15] = {'\0'};
	cin.getline(S,320,',');
	cin.getline(S1,12,',');
	cin.getline(S2,12,'\n');  //¼������
	
	char *mark_S1 = find_S1(&S[0], &S1[0]);
	char *mark_S2 = find_S2(&S[0], &S2[0], mark_S1);
	if(mark_S1 != NULL && mark_S2 != NULL)
	{
		int count = 0;
		for(; mark_S1 != mark_S2; mark_S1++)
			count++;
		
		cout<<--count;
	}
	else
		cout<<-1;
	
	return 0;
}

char *find_S1( char *S, char *S1)
{
	int flag = 0;  //��ʶ����
	char *p_check = &S[0];
	char *p_contrast = &S1[0];
	while(1)
	{
		if(*p_check == *p_contrast)
		{
			if(flag == 0)
			{
				p_contrast++;
				flag = 1;
			}
			else if(flag ==1)
			{
				p_contrast++;
			}
		}
		else if(*p_check != *p_contrast)
		{
			
			if(*p_contrast == '\0')
			{
			    //�˴�����flag = 1
				break;
			}
			else if(*p_contrast != '\0' && flag == 1)
			{
				p_contrast = &S1[0];
				flag = 0;
			}
		}
		
		if(*p_check == '\0')
			break;
		
		p_check++; //ѭ��
	}
	
	if(flag == 1)
		return --p_check;
	else
		return NULL;
}

char *find_S2(char *S, char *S2, char *mark_S1)
{
	int flag = 0;  //��ʶ����
	char *p_check = moveto_tail(&S[0]);
	char *S2_tail = moveto_tail(&S2[0]);
	char *p_contrast = S2_tail; //��ʼ��������ָ��ָ��S2�����һ��Ԫ��
	
	while(1)
	{
		
		if(*p_check == *p_contrast)
		{
		    if(p_contrast == &S2[0])
			    {
					flag = 1;  //����S2��Ԫ�����
				    break;
			    }
		    else if(flag == 0)
			{
				flag =1;
				p_contrast--;
			}
			else if(flag == 1)
			{
				p_contrast--;
			}
			

		}
		else if(*p_check != *p_contrast && flag == 1)
		{
			p_contrast = S2_tail;
			flag = 0;
		}
		
		if(p_check == mark_S1)
			break;
		
		p_check--; //ѭ��
	}
	
	if(flag == 1)
		return p_check;
	else
		return NULL;
}

char *moveto_tail(char *p)
{
	for(; *p != '\0'; p++);
	
	return --p;
}