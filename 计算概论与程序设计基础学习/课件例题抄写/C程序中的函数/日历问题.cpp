//日历问题,有小改动
#include <iostream>
using namespace std;
int days;

int get_dayofweek()
{
	int dayofweek;
	dayofweek = days % 7;
	return dayofweek;
}

int get_year()
{
	int i = 2000, leap_year;
	while(1)
	{
		leap_year = (i%4 == 0 && i%100 != 0 || i%400 == 0); //该语句需要反复执行，所以放在子函数的循环里
		if (leap_year == 1 && days >= 366)
		{
			days = days - 366;
			i++;
			continue;
		}
		else if (leap_year == 0 && days >= 365)
		{
			days = days - 365;
			i++;
			continue;
		}
		else
			break;
	}
	return i;
}

int get_month(int leap_year)
{
	int pmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int rmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	//两个数组，方便快捷
	int j = 0; //注意数组编号从0开始
	while(1)
	{
		if (leap_year == 1 && days >= rmonth[j])
		{
			days = days - rmonth[j];
			j++;
		}
		else if (leap_year == 0 && days >= pmonth[j])
		{
			days = days - pmonth[j];
			j++;
		}
		else break;
	}
	return ++j; //依然是因为数组的编号问题，所以需要加一
}

int main()
{
	int year, month, dayofweek;
	int leap_year;
	char week[7][10] = {"Saturday","Sunday","Monday","Thesday",
	                    "Wednesday","Thursday","Friday"};
	while ((cin>>days) && days != -1){
		dayofweek = get_dayofweek();
		year = get_year();
		leap_year = (year%4 == 0 && year%100 != 0 || year%400 == 0);
		month = get_month(leap_year);
		cout<<year<<"-"<<month<<"-"<<++days<<" "<<week[dayofweek]<<endl;
	}
	return 0;
}































