//openjudge���֡�jscpp�д������
#include <iostream>
using namespace std;
#define MAX 100
void get_matrix();

int main()
{
	int g = 0;
	cin>>g;
	
	for(int i = 0; i < g; i++)
		get_matrix();
	
	return 0;
}

void get_matrix()
{
	int n = 0, m = 0, k = 0;
	cin>>n>>m>>k;
	
	int A[MAX][MAX] = {0};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>A[i][j];
		
	int B[MAX][MAX] = {0};
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++)
			cin>>B[i][j];
		
	int C[MAX][MAX] = {0};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
			for(int u = 0; u < m; u++)
				C[i][j] += (A[i][u] * B[u][j]);
			
	for(int i = 0; i < n; i++)
	{
		if(i != 0)
			cout<<endl; //���Ƹ�ʽ
		
		for(int j = 0; j < k; j++)
		{
			if(j != 0)
				cout<<' ';  //���Ƹ�ʽ
			
			cout<<C[i][j];
		}
	}		
}