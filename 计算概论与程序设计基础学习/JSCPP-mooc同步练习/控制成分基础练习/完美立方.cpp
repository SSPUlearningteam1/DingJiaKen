//��ʷ������µó����ҵ��ô󵶿�һ��
#include <iostream>
using namespace std;
bool check_repeat(int mark[], int sum);
void find_cube(int n);

int main()
{
	int N = 0;
	cin>>N;
	
	for (int i = 2; i <= N; i++)  //����������Եú�������
		find_cube(i);
	
	return 0;
}

void find_cube(int a)
{
	int mark[100] = {0};
	int count = 0;
	
	for(int b = 2; b < a; b++)  //�����Ϊ��ʼ������úܱ������º��������ظ�����ʹ�ò����Æ���
		for(int c = 2; c < a; c++)  //��ʵ�ϣ�ʹ��int c = b, d = c��������һ����+1��������Ч
			for(int d = 2; d < a; d++)
				if( b*b*b + c*c*c +d*d*d == a*a*a)  //�����һ�������д��һ��ֻ��һ�ε�pow����
				{
					if( check_repeat(mark,(b*c*d)) )
						continue;
					else
					{
						mark[count++] = b * c * d;
						cout<<"Cube = "<<a<<", Triple = ("<<b<<','<<c<<','<<d<<')'<<endl;
					}
				}
}


bool check_repeat(int mark[], int sum)  //�����ʾ���ҵĴ���һ������
{
	for(int i = 0; mark[i] != 0; i++)
		if (mark[i] == sum)
			return true;
		
	return false;
}