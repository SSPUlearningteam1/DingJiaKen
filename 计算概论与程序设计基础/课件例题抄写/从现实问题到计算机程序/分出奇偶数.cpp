//�ֳ���ż��
#include <iostream>
using namespace std;
int main()
{
	int all[10], odd[10], even[10];//odd��¼������even��¼ż��
	int i = 0, j = 0;    //i,jΪѭ����������
	for (; i < 10; i++)  //����10����
	        cin>> all[i];
	int numOdd = 0;
    int numEven = 0;
	for (i = 0; i < 10; i++)  //��������all����������odd,ż������even
	{
		if (all[i]%2 != 0)  //����
		{
			odd[numOdd] = all[i];
			numOdd++;
		}
		else  //ż��
		{
			even[numEven] = all[i];
			numEven++;
		}
	}
	for (i = 0; i < numOdd; i++)//�������
	        cout<<odd[i]<<" ";
			cout<<endl;//�������Լ��ӵ�
    for (i = 0; i < numEven; i++)//���ż��
            cout<<even[i]<<" ";
    return 0;
}	
			

//ʱ��ע����������0��ʼ
//ע���������i,j,numOdd,numEven
//�����жԼ�������i��ÿ������������������¸�ֵ
//�Ҳ�֪���������Ҿ��ó���ᱨ��
//ע���������ʱ�ĳ���д��