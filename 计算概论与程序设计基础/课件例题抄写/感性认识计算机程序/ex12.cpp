#include <iostream>
using namespace std;
int main()
{
	char a = '0';//���ڴ���û��������ĸ
	cout<<"�²������ĸ���ĸ������5��Ŷ:"<<endl;
	int i = 0;//���ڼ�¼�¹����ٴ���
	for (i = 0; i < 5; i++)
	{
		cin>>a;
		if(a == 'G')//�������
		{
			cout<<"���������!"<<endl;
			break;//��ֹѭ��
		}
		else  //���û�в���
		cout<<"��´���!���Ų°�!"<<endl;
	}
	return 0;
}



//��������ʱ���鲻��Ϊ�գ��������������