#include <iostream>
using namespace std;
void change_1(int *, int);
void change_2(int *, int, int);

int main()
{
	int n = 0;  //��
	int m = 0;  //��
	
	int i = 0, j = 0;
	int num[3][4] = {0};
	n = 3; m = 4;  //������鳤����ѡ������ô�����ʼ�������δ������Ϊ
	               //����int num[n][m] = {0};ֻ�в���Ԫ�ر���ʼ��Ϊ0
	               //����ٸ����ӣ�ģ������n = 3,m = 4�����
				   
	cout<<"��һ�α���һ����ά���飺"<<endl;
	for(i = 0; i < n; i++)  //����
	{
		for(j = 0; j < m; j++)
			cout<<num[i][j]<<" ";
        cout<<endl;
	}
	
	change_1(&num[0][0], m);  //һάָ�룬Ҳ����д��num[0]
	
	cout<<"�ڶ��α���һ����ά���飺"<<endl;
	for(i = 0; i < n; i++)  //����
	{
		for(j = 0; j < m; j++)
			cout<<num[i][j]<<" ";
        cout<<endl;
	}
	
	change_2(num[0], n, m);
	
	cout<<"�����α���һ����ά���飺"<<endl;
	for(i = 0; i < n; i++)  //����
	{
		for(j = 0; j < m; j++)
			cout<<num[i][j]<<" ";
        cout<<endl;
	}
	
}

void change_1(int *num, int m)  //��Ϊ����δ֪��*num����д��������ʽ
{
	//�ֶ�Ѱַ
	num[m-1] = 1;
	num[m-1 + 1*m] = 1;
	num[m-1 + 2*m] = 1;
}

void change_2(int *num, int n, int m)
{
	//�ֶ�Ѱַ
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			num[i*m + j] = 2;
}