//��ͨ����������
#include <iostream>
using namespace std;
int main()
{
	bool prime = true;
	for (int i = 2; i < 100; i++)//�иĶ���int i = 0��Ϊint i = 2,�����ӡ�������ݽ������0��1
	{
		prime = true;
		for (int j = 2; j < i; j++)
		{
			if(i%j == 0)
				prime = false;
		}
        if (prime == true)
                cout<<i<<endl;			
	}
	return 0;

}