//�����Ͽ��˵ݹ���������Ƶķ�������������㳭��...
//������ñ�ʾһ�£��ţ���ѭ����д...
//��ɳɾͣ�openjudgeͨ����jscpp��ͨ������ʱ�䣿��
//�п���д
#include <iostream>
using namespace std;
int main()
{
	int digit[31] = {0};
	char str[11] = {'\0'};
	int num = 0;
    while(1)
	{
		cin.getline(str,12,'\n');
		if( ('a' <= str[0] && str[0] <= 'z') || ('A' <= str[0] && str[0] <= 'Z') )
            break;
        else
			num = atof(str);

		for(int i = 0; i < 32; i++)
		{
			digit[31-i] = abs(num % 2);
			num >>= 1; 
			if(num == 0)
				break;
		}
		
		for(int i = 0; i < 32; i++)
			cout<<digit[i];

        cout<<endl;
	}
	
	return 0;
	
}