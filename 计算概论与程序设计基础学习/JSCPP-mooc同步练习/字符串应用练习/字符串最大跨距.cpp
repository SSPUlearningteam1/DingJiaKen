//又一个openjudge网站Accepted但是mooc做题网不接受我答案的代码
//原题网站都通过了，那我就算通过了==!
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
	cin.getline(S2,12,'\n');  //录入数据
	
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
	int flag = 0;  //标识变量
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
			    //此处已有flag = 1
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
		
		p_check++; //循环
	}
	
	if(flag == 1)
		return --p_check;
	else
		return NULL;
}

char *find_S2(char *S, char *S2, char *mark_S1)
{
	int flag = 0;  //标识变量
	char *p_check = moveto_tail(&S[0]);
	char *S2_tail = moveto_tail(&S2[0]);
	char *p_contrast = S2_tail; //初始化，对照指针指向S2的最后一个元素
	
	while(1)
	{
		
		if(*p_check == *p_contrast)
		{
		    if(p_contrast == &S2[0])
			    {
					flag = 1;  //防备S2单元素情况
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
		
		p_check--; //循环
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