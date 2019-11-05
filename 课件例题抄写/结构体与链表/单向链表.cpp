//虽然不会写，但是拼起来还是会拼的.
#include <iostream>
using namespace std;
struct student
{
	int id;
	student *next;
};

student *create()
{
	student *head, *temp;
	int num, n = 0;
	head = new student;
	temp = head;
	cin >> num;
	while (num != -1) //-1标识结束，所以会有一个多余的链元素。算是单向链表的一个缺点吧。
	{
		n++;
		temp->id = num;
		temp->next = new student;
		temp = temp->next;
		cin>>num;
	}
	if(n ==0)
		head = NULL;
	else
		temp->next = NULL;
	return head;
	
}

student *dele(student *head, int n)
{
	student *temp, *follow;
	temp = head;
	if (head == NULL)  //head为空，空表的情况；
	{
		return(head);
	}
	if (head->id == n)  //第一个节点是要删除的目标；
	{
		head = head->next;
		delete temp;
		return(head);
	}
	
	while (temp != NULL && temp->id != n)  //寻找要删除的目标；
	{
		follow = temp;
	    temp = temp->next;
	}
	if (temp == NULL)  //没寻到要删除的目标；
		cout<<"not found";
	else  //删除目标节点；
	{
		follow->next = temp->next;
		delete temp;
	}
	return(head);
}

student *insert(student *head, int n)
{
	student *temp, *unit, *follow;  //插入结点值为n的结点
	temp = head;
	unit = new student;
	unit->id = n;
	unit->next = NULL;
	if (head == NULL)  //如果链为空，直接插入
	{
		head = unit;
		return (head);
	}
	while ((temp->next != NULL) && (temp->id < n)) //寻找第一个不小于n或结尾的结点temp
	{
		follow = temp;
		temp = temp->next;
	}
	if (temp == head)  //如果temp为第一个结点
	{
		unit->next = head;
		head = unit;
	}
	else
	{
		if (temp->next == NULL)  //如果temp为最后一个结点
			temp->next = unit;
		else  //如果temp为一个中间结点
		{
			follow->next = unit;
			unit->next = temp;
		}
	}
	return (head);
}


int main()
{
	int n = 0;
	cout<<"现在我们创造一个链表，依次输入结点ID，以-1结束"<<endl;
	student *pointer = create();
	student *backup = pointer;
	cout<<"现在链表为:"<<endl;
	while (pointer->next != NULL)
	{
		cout<<pointer->id<<endl;
		pointer = pointer->next;
	}
	pointer = backup;
	
	cout<<"现在我们删除一个结点，输入结点ID n："<<endl;
	cin>>n;
	pointer = dele(pointer,n);
	backup = pointer;
    cout<<"现在链表为:"<<endl;
	while (pointer->next != NULL)
	{
		cout<<pointer->id<<endl;
		pointer = pointer->next;
	}
	pointer = backup;
	
	cout<<"现在我们插入一个链表，输入结点ID n:"<<endl;
	cin>>n;
	pointer = insert(pointer,n);
	backup = pointer;
	cout<<"现在链表为:"<<endl;
	while (pointer->next != NULL)
	{
		cout<<pointer->id<<endl;
		pointer = pointer->next;
	}
	pointer = backup;
	
	return 0;
}