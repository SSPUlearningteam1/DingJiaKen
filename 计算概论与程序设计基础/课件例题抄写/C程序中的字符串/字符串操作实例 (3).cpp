#include <iostream>
using namespace std;
int main()
{
	int len1, len2;
	char str1[40],str2[40];
	cin.getline(str1,20);
	cin.getline(str2,20);

	for (len1 = 0; str1[len1] != '\0'; len1++);//ע��˴�Ϊ�����
	for (len2 = 0; str2[len2] != '\0'; len2++);//ע��˴�Ϊ�����
	
    if (len1 >= len2)
	{
		for (len2 = 0; str2[len2] != '\0'; len2++)
			str1[len1++] = str2[len2];
		str1[len1] = '\0';//���ַ�����\0����
	}
	/*ע��һ�£��˴�str1��ָ�����ַ����ĺ��棬
	str2��ָ�����ַ�����ǰ��*/
	else
	{
		for (len1 = 0; str1[len1] != '\0'; len1++)
			str2[len2++] = str1[len1];
		str2[len2] = '\0';//���ַ�����\0����
	}
	/*���Ƶģ��˴�str2��ָ�����ַ����ĺ��棬
	str1��ָ�����ַ�����ǰ��*/
	cout<<str1<<endl;
	cout<<str2<<endl;
	return 0;
}