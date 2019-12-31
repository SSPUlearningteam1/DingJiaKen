#include <iostream>
#include <cstring>
using namespace std;
#define MAX 302
int main()
{
	char str[MAX] = {'\0'};
	cin.getline(str,MAX,'\n');
	
	char num[MAX/2][MAX] = {'\0'};
	int flag = 0;
	int begin = 0;
	int count = 0;
	char *p_next = NULL;
	char *p_now = NULL;
	for(p_next = &str[0]; *p_next != '\0' || *(p_next-1) != '\0'; p_next++)
	{
		if( ('1' <= *p_next && *p_next <= '9') && flag == 0)
		{
			if(begin == 0)
			    begin = 1;

			flag = 1;
			p_now = p_next;
		}
		else if( (!('0' <= *p_next && *p_next <= '9') || *p_next == '\0') && flag == 1)
		{
			for(int i = 0; p_now != p_next; p_now++,i++)
				num[count][i] = *p_now;
			count++;
			
			flag = 0;
		}
	}
	
	if(begin != 0){
	for(int i = 0; i < count-1; i++)
		for(int j = i+1; j < count; j++)
			if(atof(&num[i][0]) > atof(&num[j][0]))
			{
				char temp[MAX] = {'\0'};
				strcpy(&temp[0],&num[i][0]);
				strcpy(&num[i][0],&num[j][0]);
				strcpy(&num[j][0],&temp[0]);
			}
			
	for(int i = 0; i < count; i++)
	{
		if(i != 0)
			cout<<',';
		cout<<num[i];
	}
	}
	else
		cout<<0;
		
	return 0;
}