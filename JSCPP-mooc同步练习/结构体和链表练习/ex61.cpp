//open judge  给我AC了，耶（已经忽略jscpp的判题了好吗）
#include <iostream>
#include <cstring>
#define MAX 180
#define LONGEST 20
using namespace std;

struct CLASS
{
	int month;
	int day;
	char name[LONGEST];
};

int check_longest(char *str1, char *str2)
{
	int i = 0, j = 0;
	for(i = 0; str1[i] != '\0'; i++) ;
	for(j = 0; str2[j] != '\0'; j++) ;
	
	if(i == j)
		return 0;
	else if(i > j)
		return 1;
	else
		return -1;
}

void PRINT(int n,int key_month, int key_day, CLASS *p)
{
	
	cout<<key_month<<' '<<key_day;
	for(int i = 0; i < n; i++,p++)
		if(p->month == key_month && p->day == key_day)
			cout<<' '<<p->name;
		
	cout<<endl;
}

int main()
{
	int n = 0;
	cin>>n;
	cin.get();//读走空格
	
	CLASS student[MAX] = {{0,0,{'\0'}}};
	for(int i = 0; i < n; i++)
	{
		cin.getline(student[i].name, 20 ,' ');
		cin>>student[i].month>>student[i].day;
		cin.get();
	}//录入数据结束
	
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
		{
			if(check_longest(student[i].name, student[j].name) > 0)
			{
				CLASS temp = {0,0,{'\0'}};
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
			else if(check_longest(student[i].name, student[j].name) == 0)
			{
				if(strcmp(student[i].name,student[j].name) > 0)
			    {
				CLASS temp = {0,0,{'\0'}};
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			    }
			}
		
		}
	 //排序结束
	 
	int count = 0;
	int flag = 0;
    for(int i = 1; i <= 12; i++)
		for(int j = 0; j < 31; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(student[k].month == i && student[k].day == j)
					count++;
				
			}//遍历计数
			
			if(count > 1)
			{
				if(flag == 0)
					flag = 1;
				PRINT(n,i,j,student);
			}//检查次数，满足次数的进行打印
			
			count = 0;
		}
			
	if(flag == 0)
        cout<<"None";

    return 0;	
}