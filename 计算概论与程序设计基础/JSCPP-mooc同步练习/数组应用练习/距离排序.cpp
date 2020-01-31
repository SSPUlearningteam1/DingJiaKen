#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void exchange(double[], double[]);

int main()
{
	int n = 0;
	cin>>n;
	int i = 0, j = 0, u = 0;  //��������i,j,u

	double num[10][3] = {0};  //����һ����ά���鴢��n�����ݣ�ÿ�����������֣��ֱ����x,y,z
	for(i = 0; i < n; i++)
		for(j = 0; j < 3; j++)
			cin>>num[i][j];
		
	double distance = 0;
	double message[45][8] = {0}; //���ڴ�����Ϣ������
	u = 0;
	for(i = 0; i < (n - 1); i++)  //���μ������е�������룬��Ϊn������10���������е����ϲ��ᳬ��45,������һ������"45"������
		for(j = (i + 1); j < n; j++)
		{
			distance = sqrt( pow( abs(num[i][0]-num[j][0]),2) + pow( abs(num[i][1] - num[j][1]),2) + pow( abs(num[i][2] - num[j][2]),2) );
			//�Ӷ�ά������ȡ�����м���
			message[u][0] = num[i][0];
			message[u][1] = num[i][1];
			message[u][2] = num[i][2];  //0~2�����һ������
			message[u][3] = num[j][0];
			message[u][4] = num[j][1];
			message[u][5] = num[j][2];  //3~5����ڶ�������
			message[u][6] = distance;   //6�������
			message[u][7] = u; //Ϊ����������׼��,˳���
			u++;  //����
		}
	
	for(i = 0; i < (u-1); i++)  //��u����Ϣ����ð������
		for(j = (i + 1); j < u; j++)
		{
			if(message[i][6] < message[j][6])
			    exchange(message[i],message[j]);	
			//�������е���Ϣ
            else if(message[i][6] == message[j][6] && message[i][7] > message[j][7])//�������������������������
					exchange(message[i],message[j]);
		}

    for(i = 0; i < u; i++)  //��ӡ���е�u����Ϣ
	{
		//printf("(%.0lf,%.0lf,%.0lf)-(%.0lf,%.0lf,%.0lf)=%.2lf\n",message[i][0],message[i][1],message[i][2],message[i][3],message[i][4],message[i][5],message[i][6]);
		//������վ�������м���û�취
		
		cout<<fixed<<setprecision(0)<<'('<<message[i][0]<<','<<message[i][1]<<','<<message[i][2]<<")-("<<message[i][3]<<','<<message[i][4]<<','<<message[i][5]<<")=";
		cout<<fixed<<setprecision(2)<<message[i][6]<<endl;
	}
        		
	return 0;
}

void exchange(double m1[], double m2[])
{
	double temp = 0;
	for(int i = 0; i < 8; i++)
	{
		temp = m1[i];
		m1[i] = m2[i];
		m2[i] = temp;
	}
}