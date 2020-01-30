#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("现在创建一个数组：\n");
	printf("**********************\n");
	ElemType a[MaxSize];
	printf("请输入该数组元素的个数：\n");
	int i;
	scanf("%d",&i);
	printf("请依次输入该数组元素，元素之间用空格隔开：\n");
	for(int j = 0; j < i; j++)
		scanf("%d",&a[j]);
	printf("**********************\n\n");
	
	printf("根据该数组创建一个顺序表并打印：\n");
	printf("**********************\n");
    SqList *L;
	CreateList(L,a,i);
	printf("创建完毕，打印：\n");
	DispList(L);
	printf("**********************\n\n");
	
	printf("删除逻辑位序为i的元素并存储在e中，然后打印该表：\n");
	printf("**********************\n");
	printf("请输入逻辑位序i：\n");
	int key;
	int e;
	scanf("%d",&key);
	if(ListDelete(L,key,e))
	{
	    printf("已删除，打印顺序表：\n");
	    DispList(L);
	    printf("打印e:\n");
	    printf("%d\n",e);
	}
	else
		printf("删除失败！\n");
	printf("**********************\n\n");
	
	printf("插入值为e的数据元素在逻辑位i并打印：\n");
	printf("**********************\n");
	printf("请输入逻辑位序i：\n");
	key = 0;
	scanf("%d",&key);
	printf("请输入元素值e：\n");
	e = 0;
	scanf("%d",&e);
	if(ListInsert(L,key,e))
	{
		printf("已插入，打印顺序表：\n");
		DispList(L);
	}
	else
		printf("插入失败！\n");
	printf("**********************\n\n");
	
	printf("删除元素值为e的元素并打印L：\n");
	printf("**********************\n");
	printf("请输入元素值e：\n");
	e = 0;
	scanf("%d",&e);
	key = 0;
	if((key = LocateElem(L,e)))
	{
		printf("已删除，打印顺序表：\n");
		ListDelete(L,key,e);
		DispList(L);
	}
	else
		printf("删除失败！\n");
	printf("**********************\n\n");
	
	printf("求某个数据元素值并存放在e中：\n");
	printf("**********************\n");
	printf("请输入逻辑位序i：\n");
	key = 0;
	scanf("%d",&key);
	e = 0;
	if(GetElem(L,key,e))
		printf("该位元素为：%d\n",e);
	else
		printf("查找失败！\n");
	printf("**********************\n\n");
	
	printf("额外测试，建立空表并测试：\n");
	printf("**********************\n");
	SqList *L2;
	InitList(L2);
	printf("已创建，进行测试：\n");
	printf("测试1：测试是否为空：\n");
	if(ListEmpty(L2))
		printf("L2是空表\n");
	else
		printf("L2不是空表\n");
	printf("测试2：求长度：\n");
	printf("%d\n",ListLength(L2));
	printf("测试结束\n");
	printf("**********************\n");
	
	printf("销毁表\n");
	free(L);
	free(L2);
	
	system("pause");
	
	return 0;
}