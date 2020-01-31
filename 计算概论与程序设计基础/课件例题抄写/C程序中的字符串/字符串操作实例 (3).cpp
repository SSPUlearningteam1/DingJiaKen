#include <iostream>
using namespace std;
int main()
{
	int len1, len2;
	char str1[40],str2[40];
	cin.getline(str1,20);
	cin.getline(str2,20);

	for (len1 = 0; str1[len1] != '\0'; len1++);//注意此处为空语句
	for (len2 = 0; str2[len2] != '\0'; len2++);//注意此处为空语句
	
    if (len1 >= len2)
	{
		for (len2 = 0; str2[len2] != '\0'; len2++)
			str1[len1++] = str2[len2];
		str1[len1] = '\0';//让字符串以\0结束
	}
	/*注意一下，此处str1的指针在字符串的后面，
	str2的指针在字符串的前面*/
	else
	{
		for (len1 = 0; str1[len1] != '\0'; len1++)
			str2[len2++] = str1[len1];
		str2[len2] = '\0';//让字符串以\0结束
	}
	/*类似的，此处str2的指针在字符串的后面，
	str1的指针在字符串的前面*/
	cout<<str1<<endl;
	cout<<str2<<endl;
	return 0;
}