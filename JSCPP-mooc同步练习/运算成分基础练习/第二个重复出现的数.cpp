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
	//预准备，定义数组并且读取n个数据;
	int num[500] = {0};
	for (int i = 0; i < n; i++)
		cin>>num[i];
	
	//通过两个指针开始数组的遍历，找出第二个重复的数;
	int f_num = 0; //第一个重复的数;
	int s_num = 0; //第二个重复的数;
	const int *p_next = &num[0];  //该指针从元素0开始遍历到*p_next为零，通过与*p_zero对比找出重复的数;
	const int *p_zero = &num[0];  //该指针从元素0开始遍历到除了*p_next以外的最后一个元素，每次p_next移动前该指针归零;
	
	for( ; *p_next != 0; p_next++, p_zero = &num[0])
	{
		for( ; *p_zero != 0; p_zero++)
		{
		    if (p_next == p_zero) //p_zero跳过p_next
			    continue;
	
		    if (*p_next != *p_zero) //两元素不相同。跳出本次循环,p_zero移动;
			    continue;
		    else
		    {
			    if (*p_next == f_num) //该元素为第一个重复出现的数。跳出本层循环,p_next移动;
			    	break;
			    else
			    {
				    if (f_num == 0)  //记录第一个重复的数.跳出本层循环,p_next移动;
				    {
				    	f_num = *p_next;
				    	break;
				    }
				    else
				    {
				    	s_num = *p_next;  //记录第二个重复出现的数。结束本层循环;
				    	break;
				    }
					
			    }
		    }
		}
		
		if (s_num != 0)  //出口，找到第二个重复出现的数，结束*p_next的移动.
			break;
	}
	
	return s_num;
}