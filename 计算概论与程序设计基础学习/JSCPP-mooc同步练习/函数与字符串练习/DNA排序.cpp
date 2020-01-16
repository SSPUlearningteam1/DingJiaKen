//openjudge接受答案，jscpp不接受(话说是这单元第几个这样子的题目了?)
#include <iostream>
using namespace std;

struct DNA
{
	int id;
	int unorder;
	char str[51];
};

int main()
{
	int n = 0;
	int m = 0;
	cin>>n>>m;
	cin.get();
	
	DNA dna[100] ={ {0,0,{'0'}} } ;
	for(int i = 0; i < m; i++)
	{
		dna[i].id = i;
		dna[i].unorder = 0;
		cin.getline(dna[i].str, 51, '\n');
		dna[i].str[50] = '\0';
	}
		
	for(int u = 0; u < m; u++)
		for(int i = n-1; i > 0; i--)
			for(int j = i-1; j > -1; j--)
				if(dna[u].str[i] < dna[u].str[j])
                    dna[u].unorder++;
				
	for(int i = 0; i < m-1; i++)
		for(int j = i+1; j < m; j++)
		{
			if(dna[i].unorder > dna[j].unorder)
			{
				DNA temp = {0,0,{'\0'}};
				temp = dna[i];
				dna[i] = dna[j];
				dna[j] = temp;
			}
			else if(dna[i].unorder == dna[j].unorder && dna[i].id > dna[j].id)
			{
				DNA temp = {0,0,{'\0'}};
				temp = dna[i];
				dna[i] = dna[j];
				dna[j] = temp;
			}
		}
		
	for(int i = 0; i < m; i++)
		cout<<dna[i].str<<endl;
	
	return 0;
				
	
}