//尽力了，做题网站满分10分给了7分，我做了好几天了
#include <iostream>
using namespace std;
void num_fix(char *, char *);
void find_mode(char (*)[60], int);

int main()
{
	int n = 0;
	cin>>n;
	if(n < 0 || n > 128)
		cout<<"no";
	else
	{
	cin.get();
	
	int count = 0;
	char num[128][60] = {'\0'};
	char num_temp[500] = {'\0'};
	while(1)
	{
		cin.getline(num_temp, 500,'\n');
		
		if(num_temp[0] == '\0')  //判断该行是否为空行
		    continue;
		else
		{
			num_fix(&num_temp[0], &num[count++][0]);  //处理后填入正式数组
			for(int i = 0; i < 500; i++)
				num_temp[i] = '\0';  //临时数组归零
		}
		
		if(count == n)
			break;	
	}
	
	find_mode(num,n);
	}
	
	return 0;
	
}

void num_fix(char *num_temp, char *num)
{
	char *p_check = &num_temp[0];
	
	int check_if_zero = 1;
	while(1)  //遍历，是否为0
	{
		if('0' < *p_check && *p_check <= '9')  //如果为非零数
		{
			check_if_zero = 0;
			break;
		}
		else
			p_check++;
		
		if(*p_check == '\0')
			break;
	}
	//0的处理
	if(check_if_zero == 1)
	{
		num[0] = '0';  //给正式的数组赋值零
	}
	else if(check_if_zero == 0)
	{
		p_check = &num_temp[0]; //指针归零
		
		int check_sign = 0;  //通过数组首元素判断正负数
		if( *p_check == '+' || ('0' <= *p_check && *p_check <= '9') )
			check_sign = 1;  //为正数
		else if(*p_check == '-')
		    check_sign = 0;  //为负数
		
		//开始对冗余的0进行处理
		if(check_sign == 1)
		{
			while(1)  //指针移动到非零数部分
			{
				if( ('0' < *p_check && *p_check <= '9') && *p_check != '+' )//读到非零数
				    break;
			    else
					p_check++;
			}
			//开始赋值。从首元素开始。
			for(int i = 0; *p_check != '\0'; i++, p_check++)
				num[i] = *p_check;
		}
		else if(check_sign == 0)
		{
			num[0] = '-';  //首元素赋值为负号
			while(1)  //指针移动到非零数部分
			{
				if( ('0' < *p_check && *p_check <= '9' ) && *p_check != '-')//读到非零数
				    break;
			    else
					p_check++;
			}
			//开始赋值。从第二个元素开始。
			for(int i = 1; *p_check != '\0'; i++, p_check++)
				num[i] = *p_check;
		}
		
	}
		/*
		此函数过后，所有表示0的字符串将储存为'0';
		所有正数表示为'123'(示例)的形式;
		所有负数表示为'-123'的形式;
		*/
}

void find_mode(char (*num)[60], int n)
{
	char *p_now = &num[0][0];
	char *p_next = &num[1][0];
	char mode[60] = {'\0'};
	int count_now = 1;
	int count_max = 1;
	
	for(int i = 0; i < n-1; i++)  //i对应now
	{
		count_now = 1;  //当前计数归一
		for(int j = i+1; j < n; j++)  //j对应next
		{
			p_now = &num[i][0];
			p_next = &num[j][0]; //指针初始化
			
			int flag = 1;
			while(1)
			{
				if(*p_now != *p_next)
				{
					flag = 0;
					break;
				}
				else
				{p_now++; p_next++;}
			
			    if(*p_now == '\0' || *p_next == '\0')  //数到头
                    break;					
			}
			
			if(flag == 0) //不同数
				continue;
			else if(flag == 1)  //相同数
			{
				count_now++;
				if(count_max < count_now)
				{
					count_max = count_now;
					for(int u = 0; u < 60; u++)
						mode[u] = num[i][u];
				}
			}
		}
	}
	
	//经过上述步骤找出了众数，现在开始打印
	
	if(count_max == 1 || count_max == n)
		cout<<"no";
	else
		cout<<mode;
}

