//��openjudge��վ�õ�Accepted����,Ȼ��mooc������վ��ʾ������Խ��......
//��������Ϊ�ַ������δ������Ϊ�����˵�.....
//ԭ����վ��ͨ���ˣ����Ҿ���ͨ����==!
#include <iostream>
using namespace std;
bool different(char *p1, char *p2);
void PRINT(char (*words)[60] );
void exchange(char *p1, char *p2);
bool check(char *p1, char *p2);
void reline_min_to_max(char (*words)[60] );
void reline_min_to_max(char (*words)[60] );
void get_words(char (*words)[60]);

int main()
{
	char words[105][60] = {'\0'};
	
    get_words(&words[0]);
	
	reline_min_to_max(&words[0]);
	
	PRINT(&words[0]);
	
	return 0;
	
}

void get_words(char (*words)[60])
{
	char temp = {'\0'};
    int flag = 0;
	int i = -1, j = 0;  //i == -1Ϊ��ʼ��һ��������׼��
	while(1)
	{
		cin.get(temp);
		
		if(temp == '\n') //����
			break;
		
		if(temp == ' ' && flag == 1)
			flag = 0;
		else if(temp != ' ' && temp != '\n')
		{
			if(flag == 0)
			{
				i++;    //��һ��
				j = 0;  //�й���
				flag = 1;
			}
			words[i][j++] = temp;
		}
	}
}

void reline_min_to_max(char (*words)[60] )
{
	for(int i = 0; words[i+1][0] != '\0';  i++)
		for(int j = i + 1; words[j][0] != '\0'; j++)
			if( check(&words[i][0],&words[j][0]) )//���words[i]����words[j],����
		        exchange(&words[i][0],&words[j][0]);
				
}

bool check(char *p1, char *p2)
{
	//ע��'A'~'Z'����Ϊ65��90 'a'~'z'����Ϊ97��122
	for(int i = 0; i < 60; i++)
	{
		if(p1[i] < p2[i])  //p1ΪС��ţ�Ӧ����ǰ�棬����Ҫ����
            return false;	
		else if(p1[i] > p2[i])  //p1Ϊ����ţ�Ӧ����ǰ�棬����
			return true;
	}		
    
	return false;  //Ϊ��ͬ����
}

void exchange(char *p1, char *p2)
{
	char temp[60] = {'\0'};
    int i = 0;
	for(i = 0; i < 60; i++)
		temp[i] = p1[i];
	for(i = 0; i < 60; i++)
		p1[i] = p2[i];
	for(i = 0; i < 60; i++)
		p2[i] = temp[i];
}

void PRINT(char (*words)[60] )
{
	char temp_null[60] = {'\0'};
	char *p_now = &temp_null[0];
	char *p_next = &words[0][0];
	
	while(p_next[0] != '\0')
	{
		if( different(p_now,p_next) )
		{
			for(int i = 0; p_next[i] != '\0'; i++)
				cout<<p_next[i];
			cout<<endl;
			p_now = p_next;
		}
		p_next += 60;;
	}
}

bool different(char *p1, char *p2)
{
	for(int i = 0; i < 60; i++)
		if(p1[i] != p2[i])
			return true;
	
	return false;
}