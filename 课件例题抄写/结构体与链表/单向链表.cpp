//��Ȼ����д������ƴ�������ǻ�ƴ��.
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
	while (num != -1) //-1��ʶ���������Ի���һ���������Ԫ�ء����ǵ��������һ��ȱ��ɡ�
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
	if (head == NULL)  //headΪ�գ��ձ�������
	{
		return(head);
	}
	if (head->id == n)  //��һ���ڵ���Ҫɾ����Ŀ�ꣻ
	{
		head = head->next;
		delete temp;
		return(head);
	}
	
	while (temp != NULL && temp->id != n)  //Ѱ��Ҫɾ����Ŀ�ꣻ
	{
		follow = temp;
	    temp = temp->next;
	}
	if (temp == NULL)  //ûѰ��Ҫɾ����Ŀ�ꣻ
		cout<<"not found";
	else  //ɾ��Ŀ��ڵ㣻
	{
		follow->next = temp->next;
		delete temp;
	}
	return(head);
}

student *insert(student *head, int n)
{
	student *temp, *unit, *follow;  //������ֵΪn�Ľ��
	temp = head;
	unit = new student;
	unit->id = n;
	unit->next = NULL;
	if (head == NULL)  //�����Ϊ�գ�ֱ�Ӳ���
	{
		head = unit;
		return (head);
	}
	while ((temp->next != NULL) && (temp->id < n)) //Ѱ�ҵ�һ����С��n���β�Ľ��temp
	{
		follow = temp;
		temp = temp->next;
	}
	if (temp == head)  //���tempΪ��һ�����
	{
		unit->next = head;
		head = unit;
	}
	else
	{
		if (temp->next == NULL)  //���tempΪ���һ�����
			temp->next = unit;
		else  //���tempΪһ���м���
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
	cout<<"�������Ǵ���һ����������������ID����-1����"<<endl;
	student *pointer = create();
	student *backup = pointer;
	cout<<"��������Ϊ:"<<endl;
	while (pointer->next != NULL)
	{
		cout<<pointer->id<<endl;
		pointer = pointer->next;
	}
	pointer = backup;
	
	cout<<"��������ɾ��һ����㣬������ID n��"<<endl;
	cin>>n;
	pointer = dele(pointer,n);
	backup = pointer;
    cout<<"��������Ϊ:"<<endl;
	while (pointer->next != NULL)
	{
		cout<<pointer->id<<endl;
		pointer = pointer->next;
	}
	pointer = backup;
	
	cout<<"�������ǲ���һ������������ID n:"<<endl;
	cin>>n;
	pointer = insert(pointer,n);
	backup = pointer;
	cout<<"��������Ϊ:"<<endl;
	while (pointer->next != NULL)
	{
		cout<<pointer->id<<endl;
		pointer = pointer->next;
	}
	pointer = backup;
	
	return 0;
}