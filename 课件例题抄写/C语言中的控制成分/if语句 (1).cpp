#include <iostream>
using namespace std;
int main()
{
	float weight = 0, height = 0, healthRate = 0;
	cin>>weight>>height;
	healthRate = weight/(height*height);
	if ((18 <= healthRate) && (healthRate <= 25))
		cout<<"��������!"<<endl;
	else if ((25<healthRate) && (healthRate <= 30))
	    cout<<"����!ע�����!"<<endl;
	else if ((30 < healthRate) && (healthRate <= 35))
		cout<<"����!���ʰ�!"<<endl;
	else if ((35 < healthRate) && (healthRate <= 40))
		cout<<"�ضȷ���!�����!"<<endl;
	else
		cout<<"��ֱ�Ӳ���120!"<<endl;
	return 0;
}