#include <iostream>
using namespace std;
void change_1(int *);
void change_2(int (*)[4]);

int main()
{
	int num[3][4] = {0};
	change_1(&num[0][0]);  //һάָ�룬ָ��һ������Ԫ��
	                       //&num[x][0]Ҳ����д��num[x]
						   
	change_2(&num[0]);     //��άָ�룬ָ��һ��һά����
	                       //&num[a]Ҳ����д��num
	
	for(int i = 0; i < 3; i++)
	{
		cout<<"������ά����: ";
		for(int j = 0; j < 4; j++)
            cout<<num[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}

void change_1(int *num) //һ��ָ�����βΣ�����ֱ�Ӳ���һ��Ԫ��
{                       //Ҳ���Ա���һ��һά����
            *num = 1;   //�β�Ҳ����д��int num[]
			num[1] = 1;
}

void change_2(int (*num)[4])  //ָ���β�Ϊ����ָ�룬ָ�������Ϊ
{                             //��4��Ԫ�ص�һά����
	num[1][1] = 1;            //�β�Ҳ����д��int num[][4]
}
