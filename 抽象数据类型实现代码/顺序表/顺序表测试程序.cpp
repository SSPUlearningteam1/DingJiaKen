#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("���ڴ���һ�����飺\n");
	printf("**********************\n");
	ElemType a[MaxSize];
	printf("�����������Ԫ�صĸ�����\n");
	int i;
	scanf("%d",&i);
	printf("���������������Ԫ�أ�Ԫ��֮���ÿո������\n");
	for(int j = 0; j < i; j++)
		scanf("%d",&a[j]);
	printf("**********************\n\n");
	
	printf("���ݸ����鴴��һ��˳�����ӡ��\n");
	printf("**********************\n");
    SqList *L;
	CreateList(L,a,i);
	printf("������ϣ���ӡ��\n");
	DispList(L);
	printf("**********************\n\n");
	
	printf("ɾ���߼�λ��Ϊi��Ԫ�ز��洢��e�У�Ȼ���ӡ�ñ�\n");
	printf("**********************\n");
	printf("�������߼�λ��i��\n");
	int key;
	int e;
	scanf("%d",&key);
	if(ListDelete(L,key,e))
	{
	    printf("��ɾ������ӡ˳���\n");
	    DispList(L);
	    printf("��ӡe:\n");
	    printf("%d\n",e);
	}
	else
		printf("ɾ��ʧ�ܣ�\n");
	printf("**********************\n\n");
	
	printf("����ֵΪe������Ԫ�����߼�λi����ӡ��\n");
	printf("**********************\n");
	printf("�������߼�λ��i��\n");
	key = 0;
	scanf("%d",&key);
	printf("������Ԫ��ֵe��\n");
	e = 0;
	scanf("%d",&e);
	if(ListInsert(L,key,e))
	{
		printf("�Ѳ��룬��ӡ˳���\n");
		DispList(L);
	}
	else
		printf("����ʧ�ܣ�\n");
	printf("**********************\n\n");
	
	printf("ɾ��Ԫ��ֵΪe��Ԫ�ز���ӡL��\n");
	printf("**********************\n");
	printf("������Ԫ��ֵe��\n");
	e = 0;
	scanf("%d",&e);
	key = 0;
	if((key = LocateElem(L,e)))
	{
		printf("��ɾ������ӡ˳���\n");
		ListDelete(L,key,e);
		DispList(L);
	}
	else
		printf("ɾ��ʧ�ܣ�\n");
	printf("**********************\n\n");
	
	printf("��ĳ������Ԫ��ֵ�������e�У�\n");
	printf("**********************\n");
	printf("�������߼�λ��i��\n");
	key = 0;
	scanf("%d",&key);
	e = 0;
	if(GetElem(L,key,e))
		printf("��λԪ��Ϊ��%d\n",e);
	else
		printf("����ʧ�ܣ�\n");
	printf("**********************\n\n");
	
	printf("������ԣ������ձ����ԣ�\n");
	printf("**********************\n");
	SqList *L2;
	InitList(L2);
	printf("�Ѵ��������в��ԣ�\n");
	printf("����1�������Ƿ�Ϊ�գ�\n");
	if(ListEmpty(L2))
		printf("L2�ǿձ�\n");
	else
		printf("L2���ǿձ�\n");
	printf("����2���󳤶ȣ�\n");
	printf("%d\n",ListLength(L2));
	printf("���Խ���\n");
	printf("**********************\n");
	
	printf("���ٱ�\n");
	free(L);
	free(L2);
	
	system("pause");
	
	return 0;
}