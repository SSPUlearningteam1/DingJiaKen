//openjude���֣�jscpp�д�
#include <iostream>
using namespace std;

struct WORD
{
	char str[45];
	int length;
};

int get_length(char str[])
{
	char *p = &str[0];
	int length = 0;
	for(length = 0; *p != '\0'; p++,length++);
	
	return length;
}

int main()
{
	int n = 0;
	cin>>n;
	cin.get();
	
	WORD word[300] = {{{'\0'},0}};  //����ṹ�����鴢�浥��
	int i = 0;
	for(i = 0; i < n-1; i++)        //ǰn-1�������ո���ֹ
	{
		cin.getline(word[i].str,45,' ');
		word[i].length = get_length(&word[i].str[0]);  //���㳤��
	}
	cin.getline(word[i].str,45,'\n');    //��n���ַ��������س���ֹ
	word[i].length = get_length(&word[i].str[0]);
	
	//����¼��
	
    int count = 0;  //��������������ÿ�е��ַ���
	int flag_blank = 0; //���ƿո�Ĵ�ӡ
	for(i = 0; i < n; i++)
	{
		while(1)
		{
			if(flag_blank == 0)
				count += word[i].length;  //��һ�����ʣ����е��ʱ�����
			else
				count += (word[i].length + 1);  //һ���ո�ӵ��ʵĳ���
			
		    if(count <= 80)
		    {
			    if(flag_blank == 0)
				   flag_blank = 1;
			    else
				   cout<<' ';
			
			    cout<<word[i].str;
				break;//��ӡһ�����ʳɹ�
		    }
		    else
		    {
				cout<<endl; //����
			    count = 0;
				flag_blank = 0;
				continue;   //����һ�д�ӡ�������
		    }
		}
	}
	
	return 0;
	
}