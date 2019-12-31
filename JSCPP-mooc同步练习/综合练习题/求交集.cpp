#include <iostream>
using namespace std;
#define MAX 201

int main()
{
	int num_1[MAX] = {0};
	int num_2[MAX] = {0};
	
	char check = '\0';
	cin>>num_1[0];
    int count_1 = 1;
	while(1)
	{
		check = cin.get();
		if(check == ',')
			cin>>num_1[count_1++];
		else if(check == '\n')
			break;
	}
	
	check = '\0';
	cin>>num_2[0];
    int count_2 = 1;
	while(1)
	{
		check = cin.get();
		if(check == ',')
			cin>>num_2[count_2++];
		else if(check == '\n')
			break;
	}
	
	int intersection[MAX] = {0};
	int count_3 = 0 ;
	int flag = 0;
	for(int i = 0; i < count_1; i++)
		for(int j = 0; j < count_2; j++)
			if(num_1[i] == num_2[j])
			{
				if(flag == 0)
				{
					flag = 1;
					intersection[count_3++] = num_1[i];
				}
				else
				{
					bool repeat = 0;
					for(int u = 0; u < count_3; u++)
						if(intersection[u] == num_1[i])
							repeat = 1;
						
					if(repeat == 0)
						intersection[count_3++] = num_1[i];
				}
			}
			
			
	if(flag != 0)
	{
    for(int i = 0; i < count_3-1; i++)
		for(int j = i; j < count_3; j++)
			if(intersection[i] > intersection[j])
			{
				int temp = 0;
				temp = intersection[i];
				intersection[i] = intersection[j];
				intersection[j] = temp;
			}
			
	for(int i = 0; i < count_3; i++)
	{
		if(i != 0)
			cout<<',';
		
		cout<<intersection[i];
	}
	}
	else
		cout<<"NULL";
	
	return 0;
}