#include <iostream>
using namespace std;
void get_second_repetition ();
int get_num (int n);


int main()
{
	int m = 0;
	cin>>m;
	
	for (int i = 0; i < m; i++)
		get_second_repetition();
	
	return 0;
}

void get_second_repetition()
{
	int n = 0;
	int result = 0;
	cin>>n;
	
	result = get_num(n);
	
	if (result != 0)
	{
		cout<<result<<endl;
	}
	else
	{
		cout<<"NOT EXIST"<<endl;
	}
	
}

int get_num (int n)
{
	//Ԥ׼�����������鲢�Ҷ�ȡn������;
	int num[500] = {0};
	for (int i = 0; i < n; i++)
		cin>>num[i];
	
	//ͨ������ָ�뿪ʼ����ı������ҳ��ڶ����ظ�����;
	int f_num = 0; //��һ���ظ�����;
	int s_num = 0; //�ڶ����ظ�����;
	const int *p_next = &num[0];  //��ָ���Ԫ��0��ʼ������*p_nextΪ�㣬ͨ����*p_zero�Ա��ҳ��ظ�����;
	const int *p_zero = &num[0];  //��ָ���Ԫ��0��ʼ����������*p_next��������һ��Ԫ�أ�ÿ��p_next�ƶ�ǰ��ָ�����;
	
	for( ; *p_next != 0; p_next++, p_zero = &num[0])
	{
		for( ; *p_zero != 0; p_zero++)
		{
		    if (p_next == p_zero) //p_zero����p_next
			    continue;
	
		    if (*p_next != *p_zero) //��Ԫ�ز���ͬ����������ѭ��,p_zero�ƶ�;
			    continue;
		    else
		    {
			    if (*p_next == f_num) //��Ԫ��Ϊ��һ���ظ����ֵ�������������ѭ��,p_next�ƶ�;
			    	break;
			    else
			    {
				    if (f_num == 0)  //��¼��һ���ظ�����.��������ѭ��,p_next�ƶ�;
				    {
				    	f_num = *p_next;
				    	break;
				    }
				    else
				    {
				    	s_num = *p_next;  //��¼�ڶ����ظ����ֵ�������������ѭ��;
				    	break;
				    }
					
			    }
		    }
		}
		
		if (s_num != 0)  //���ڣ��ҵ��ڶ����ظ����ֵ���������*p_next���ƶ�.
			break;
	}
	
	return s_num;
}