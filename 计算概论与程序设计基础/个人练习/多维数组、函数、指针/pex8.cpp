#include <iostream>
using namespace std;
void change(int *);

int main()
{
	int num[3][4] = {0};
	change(num[1]);  //����ڶ���
	
	for(int i = 0; i < 3; i++)
	{
		cout<<"������ά����: ";
		for(int j = 0; j < 4; j++)
            cout<<num[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}

void change(int *num)
{
		for(int j = 0; j < 4; j++)
			num[j] = 1;
}