//��֮0��
#include <iostream>
using namespace std;

void find_max_ch()
{
	char str[201] = {'\0'};  //��ֹ�������Խ��
	cin.getline(str,201,'\n');
	
	char *p_now = NULL;
	char *p_next = NULL;
	int count = 0;
	int max = 0;
	char ch_max = 0;
	for(p_now = &str[0], p_next = &str[0]; (*p_next != '\0' || *p_now !='\0'); p_next++)
	{
		if(*p_next != *p_now || *p_next == '\0')
		{
			if(max < count)
			{
				max = count;
				ch_max = *p_now;
			}
			p_now = p_next;
			count = 1; //��1����һ������������*p_now == *p_next
		}
		else
			count++;  //����
	}
	
	cout<<ch_max<<' '<<max;
	
}

int main()
{
	int n = 0;
	cin>>n;
	cin.get();
	
	for(int i = 0; i < n; i++)
	{
		find_max_ch();
		if(i != n-1)
			cout<<endl;  //���Ƹ�ʽ
	}
	
	return 0;
}