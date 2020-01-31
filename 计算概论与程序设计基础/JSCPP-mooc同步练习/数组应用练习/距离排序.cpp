#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void exchange(double[], double[]);

int main()
{
	int n = 0;
	cin>>n;
	int i = 0, j = 0, u = 0;  //计数变量i,j,u

	double num[10][3] = {0};  //设置一个二维数组储存n组数据，每组有三个数字，分别代表x,y,z
	for(i = 0; i < n; i++)
		for(j = 0; j < 3; j++)
			cin>>num[i][j];
		
	double distance = 0;
	double message[45][8] = {0}; //用于存贮信息的数组
	u = 0;
	for(i = 0; i < (n - 1); i++)  //依次计算所有的两间距离，因为n不大于10，所以所有点的组合不会超过45,这是上一个数组"45"的意义
		for(j = (i + 1); j < n; j++)
		{
			distance = sqrt( pow( abs(num[i][0]-num[j][0]),2) + pow( abs(num[i][1] - num[j][1]),2) + pow( abs(num[i][2] - num[j][2]),2) );
			//从二维数组中取数进行计算
			message[u][0] = num[i][0];
			message[u][1] = num[i][1];
			message[u][2] = num[i][2];  //0~2储存第一个坐标
			message[u][3] = num[j][0];
			message[u][4] = num[j][1];
			message[u][5] = num[j][2];  //3~5储存第二个坐标
			message[u][6] = distance;   //6储存距离
			message[u][7] = u; //为处理数据做准备,顺序号
			u++;  //计数
		}
	
	for(i = 0; i < (u-1); i++)  //对u组信息进行冒泡排序
		for(j = (i + 1); j < u; j++)
		{
			if(message[i][6] < message[j][6])
			    exchange(message[i],message[j]);	
			//交换所有的信息
            else if(message[i][6] == message[j][6] && message[i][7] > message[j][7])//处理等量含距离数据排序问题
					exchange(message[i],message[j]);
		}

    for(i = 0; i < u; i++)  //打印所有的u条信息
	{
		//printf("(%.0lf,%.0lf,%.0lf)-(%.0lf,%.0lf,%.0lf)=%.2lf\n",message[i][0],message[i][1],message[i][2],message[i][3],message[i][4],message[i][5],message[i][6]);
		//做题网站编译器残疾，没办法
		
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