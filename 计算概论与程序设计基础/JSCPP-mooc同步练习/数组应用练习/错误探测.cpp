#include <iostream>
using namespace std;
int check(int);

int main()
{
	int n = 0;
	while(cin>>n && n != 0)
	{
		if(check(n));
	}
	return 0;
}

int check(int n)
{
	int i = 0, j = 0;
	int matrix[n][n];
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			cin>>matrix[i][j];
	
	int count_for_1 = 0;
	int count_row_result = 0, count_column_result = 0;
	int mark_row_key = 0, mark_column_key = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			if(matrix[i][j] == 1)
				count_for_1++;
			
		if(count_for_1 % 2 != 0)
			count_row_result++;
		
		if(count_row_result == 1 && mark_row_key == 0)
			mark_row_key = i;
		
		if(count_row_result > 1)
		{
			cout<<"Corrupt"<<endl;
			return 0;
		}
		
		count_for_1 = 0;
	}
	
	
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < n; i++)
			if(matrix[i][j] == 1)
				count_for_1++;
			
		if(count_for_1 % 2 != 0)
			count_column_result++;
		
		if(count_column_result == 1 && mark_column_key == 0)
			mark_column_key = j;
		
		if(count_column_result > 1)
		{
			cout<<"Corrupt"<<endl;
			return 0;
		}
		
		count_for_1 = 0;
	}
	
	if(count_row_result == 0 && count_column_result == 0)
		cout<<"OK"<<endl;
	else if(count_row_result == 1 && count_column_result == 1)
		cout<<"Change bit ("<<++mark_row_key<<","<<++mark_column_key<<")"<<endl;
	
	return 1;
			
}