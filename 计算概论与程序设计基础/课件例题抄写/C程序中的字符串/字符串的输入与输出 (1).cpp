#include <iostream>
using namespace std;
int main()
{
	float grade;
	cout<<"enter grade:";
	while (cin>>grade)  //能从cin流读取数据
	{
		if (grade >= 85)
			cout<<grade<<"GOOD"<<endl;
		else if (grade < 60)
			cout<<grade<<"fail!"<<endl;
		else
			cout<<grade<<"soso"<<endl;//小补充
		cout<<"enter grade:";
	}
	return 0;
}