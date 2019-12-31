//我错了，下次我用结构体指针，而且我再也不起花里胡哨的变量名了
#include <iostream>
using namespace std;
#define MAX 100

struct USER
{
	int m_times; //times of be mentioned
	int m_bloggers[MAX]; //id of those bloggers who mention this user
};

bool check_repeat(int a[], int num)
{
	if(a[0] == 0)
		return 0;
	else
	{
		for(int i = 0; a[i] != 0; i++)
			if(num == a[i])
				return 1;
	}
	
	return 0;
}

int main()
{
	USER user[MAX] = {{0,{0}}};
	
	int n = 0;
	cin>>n;
	
	int blogger = 0 ;  //the author of weibo
	int id_be_mention = 0; //id of who is mentioned
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>blogger;
		cin>>k;
		
		for(int j = 0; j < k; j++)
		{			
			cin>>id_be_mention;
			user[id_be_mention].m_times++;
			if( !check_repeat(&user[id_be_mention].m_bloggers[0] , blogger) )
			{
				int mark_0 = 0;
				for(mark_0 = 0; user[id_be_mention].m_bloggers[mark_0] != 0; mark_0++) ;
				
				user[id_be_mention].m_bloggers[mark_0] = blogger;
			}
		}
	}//finish entry the data of weibo
	
	
	int id_focus = 1;
	for(int i = 1; i < MAX; i++)
		if(user[id_focus].m_times < user[i].m_times)
			id_focus = i;//find the focus
		
	int mark_tail = 0;
	for(mark_tail = 0; user[id_focus].m_bloggers[mark_tail] != 0; mark_tail++) ;
	
	for(int i = 0; i < mark_tail-1; i++)
		for(int j = i; j < mark_tail; j++)
			if(user[id_focus].m_bloggers[i] > user[id_focus].m_bloggers[j])
			{
				int temp = 0;
				temp = user[id_focus].m_bloggers[i];
				user[id_focus].m_bloggers[i] = user[id_focus].m_bloggers[j];
				user[id_focus].m_bloggers[j] = temp;
			}
			
	cout<<id_focus<<endl;
	for(int i = 0; i < mark_tail; i++)
	{
		if(i != 0)
			cout<<' ';
		cout<<user[id_focus].m_bloggers[i];
	}
	
	return 0;
}