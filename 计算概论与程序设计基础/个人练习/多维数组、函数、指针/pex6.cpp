#include <iostream>
using namespace std;
void change(int [][4]);

int main()
{
	int num[3][4] = {0};
	change(num);
	
	for(int i = 0; i < 3; i++)
	{
		cout<<"遍历二维数组: ";
		for(int j = 0; j < 4; j++)
            cout<<num[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}

void change(int num[][4])
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			num[i][j] = i * j;
}