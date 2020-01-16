#include <iostream>
using namespace std;
int excel_number = 0;

void excel_count (float score)
{
	if (score > 85)
	{
		excel_number++;
	}
}

int main()
{
	float score = 0;
	for (int i = 0; i <10; i++) //小改动
	{
		cin>>score;
		excel_count(score);
	}
	cout<<excel_number<<endl; //此处有改正
	return 0;
}