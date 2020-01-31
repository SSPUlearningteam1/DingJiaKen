//openjudge得AC，运行时间330ms左右；结果jscpp运行了3m然后判我超时==!
#include <iostream>
using namespace std;

struct Number
{
	int num;
	Number *next;
};

Number *creat_link(int n)
{
	
	Number *head = NULL;
	Number *temp = NULL;
	for(int i = 0; i < n; i++)
	{
		if(head == NULL)
		{
			head = new Number;
			temp = head;
			cin>>temp->num;
			temp->next = NULL;
		}
		else
		{
			temp->next = new Number;
			temp = temp->next;
			cin>>temp->num;
			temp->next = NULL;
		}
	}
	
	return head;
}

Number *delete_link(int key, Number *head)
{
	Number *temp = head;
	Number *follow = temp;
	while(temp != NULL)
	{
		if(temp->num == key)			
		{
			if(temp != head)
		    {
				follow->next = temp->next;
				delete temp;
				temp = follow->next;
			}
		    else if(temp == head)
		    {
			    head = head->next;
			    delete temp;
				temp = head;
				follow = temp;
		    }
		}
		else
		{
			follow = temp;
		    temp = temp->next;
		}
	}
	
	return head;
}

int main()
{
	int n = 0;
	cin>>n;
	
	Number *head = NULL;
	head = creat_link(n);
	
	int key = 0;
	cin>>key;
	
	head = delete_link(key,head);
	
	for(Number *temp = head; temp != NULL; temp = temp->next)
	{
		if(temp != head)
			cout<<' ';
		
		cout<<temp->num;
	}
	
	return 0;
}