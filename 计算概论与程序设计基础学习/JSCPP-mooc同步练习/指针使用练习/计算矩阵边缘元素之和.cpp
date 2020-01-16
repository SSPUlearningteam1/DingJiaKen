#include <iostream>
using namespace std;
void get_sum();
int main()
{
	int k = 0;
	cin>>k;
	
	for(int i = 0; i < k; i++)
		get_sum();
	
	return 0;
}

void get_sum()
{
	int num[100][100] = {0};
	
	int row = 0;
	int col = 0;
	cin>>row>>col;
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cin>>num[i][j];
		
    int sum = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(i == 0 ||  i == row-1 || (j == 0 || j == col-1))
				sum += num[i][j];
			
	cout<<sum<<endl;
}