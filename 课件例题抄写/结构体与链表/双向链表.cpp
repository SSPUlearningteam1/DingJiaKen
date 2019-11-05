//约瑟夫问题
#include <iostream>
using namespace std;
struct Node
{
	int num;
	Node *ahead;
	Node *next;
};

Node *Create(int N)  //创建包含N个节点的双向循环链
{
	int n = 1;
	Node *node = new Node;
	node->num = n;
	Node *head = node;  //指向第一个节点
	Node *tail = head;  //指向最后一个节点
	
	while(n++ < N)
	{
		node = new Node;  //创建新节点
		node->num = n;  //赋值
		tail->next = node;  //接入新节点
		node->ahead = tail;
		tail = tail->next;  //尾巴后移
	}
	
	tail->next = head;  //尾巴处理
	head->ahead = tail;
	return head;
}

Node *Search(Node *head, int P)
{
	while(head->num != P)
	{
		head = head->next;
	}
	return head;
}

Node *Release(Node *head, int M)  //释放head开始的第M个节点
{
	int count = 1;
	Node *temp = head;
	while(count < M)  //寻找第M个节点
	{
		temp = temp->next;  //先报数，然后才轮到下一位。当报到标识数，temp不再移动。
		count++;
	}
	temp->ahead->next = temp->next;  //移除第M个节点
	temp->next->ahead = temp->ahead;
	cout<<temp->num<<",";
	head = temp->next;  //释放第M个节点所占的内存空间
	delete temp;
	return head;	
}

int main()
{
	int N,P,M = 0;  //N为起始节点数，P为开始节点
	cin>>N>>P>>M;  //每次释放第M个节点
	Node *head = Create(N);  //创建N个节点的环
	head = Search(head,P);  //找到第P个节点
	while(head->next != head)  //不断释放第M个元素
	{                          //直到只剩一个元素
		head = Release(head,M);  //释放第M个节点
	}
	cout<<head->num;
	return 0;
}



































