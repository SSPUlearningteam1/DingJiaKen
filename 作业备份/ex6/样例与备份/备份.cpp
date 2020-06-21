#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************/
/*ѧ����Ϣ����ϵͳ(˳���ṹ)*/
/******************************/

#define MaxSize 100  //���ѧ����¼����
#define NumSize 8    //ѧ�ų��ȡ�Ҫע��C���ԵĹ涨��ʵ����ֻ������NumSize-1λѧ��

int size;            //һ����¼���ֽڴ�С
int SaveFlag;        //���ڱ�ʾ��ǰ�ı���״̬��0��ʾ���޸ģ�δ���档

typedef struct Student_str{//�ṹ�嶨��
	char num[NumSize];    //ѧ��
	double course1; //��Ŀ1����Ϊ����
	double course2; //��Ŀ2����Ϊ��ѧ
	double course3; //��Ŀ3����ΪӢ��
	double sum;     //�ܷ�
}Student;

typedef struct SqList{//����˳����������¼
	Student data[MaxSize];    //ѧ����¼
	int count;                //��¼����
}RecordList;//��¼��

/*Inputchoice:��ʾ��ʾ��Ϣ����ȡ�û��Ĳ���*/
char Inputchoice()
{
	char mychoice;
	printf("\nManagement for Students's scores\n");
	printf("1.Append record\n");
	printf("2.List record\n");
	printf("3.Delete record\n");
	printf("4.Modify record\n");
	printf("5.Search record\n");
	printf("6.Sort in descending order by sum\n");
	printf("7.Sort in ascending order by sum\n");
	printf("8.Sort in descending order by num\n");
	printf("9.Sort in ascending order by num\n");
	printf("W.Write to a File\n");
	printf("R.Read from a File\n");
	printf("0.Exit\n");
	
	scanf("%c",&mychoice);
	getchar();  //���߿ո�
	return mychoice;
}

/*GetRecordCount:��ȡ��¼����*/
int GetRecordCount(FILE *fp)
{
	int begin,end,recordcount;
	
	fseek(fp,0,SEEK_SET);
	begin=ftell(fp);
	fseek(fp,0,SEEK_END);
	end=ftell(fp);
	recordcount=(end-begin)/size;
	return recordcount;
}

/*FileRead:��ȡ�ļ���Ϣ���ڴ���*/
void FileRead(RecordList *&L)
{
	FILE *fp;
	if((fp=fopen("scores.txt","rb+")) == NULL){//���ļ�����ʧ����������
		printf("Can not open file scores.txt!\n");
		exit(0);
	}
	/*rb+:�Զ�/д��ʽ��һ���������ļ���ֻ�����/д���ݡ����ļ��������򷵻�NULL��*/
	L->count = GetRecordCount(fp);        //�����¼����
	fseek(fp,0,SEEK_SET);                 //�ƶ��ļ�ָ������ͷ
	fread(L->data,size,L->count,fp);      //��ȡ��Ӧ����������
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
}

/*FileWrite:��ȡ�ڴ����ݣ�����ԭ�ļ�*/
void FileWrite(RecordList *L)
{
	FILE *fp;
	fp = fopen("scores.txt","wb");
	/*wb:��ֻд��ʽ�򿪻��½�һ���������ļ���ֻ����д���ݡ�
	���ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ�
	�������������ļ���*/
	fseek(fp,0,SEEK_SET);                 //�ƶ��ļ�ָ������ͷ
	fwrite(L->data,size,L->count,fp);     //д����Ӧ����������
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
}

/*AddRecord:��Ӽ�¼��L->data[count]*/
bool AddRecord(RecordList *&L)
{
	if(L->count == MaxSize){//�Ѵ������������ʾ�ռ䲻�㣬����false
		printf("Insufficient space!\n");
		return false;
	}
	
	printf("adding...\n");
	printf("Input the student number(%dnumber): ",NumSize-1); scanf("%s",L->data[L->count].num);
	printf("Input the score of Chinese: "); scanf("%lf",&L->data[L->count].course1);
	printf("Input the score of math: "); scanf("%lf",&L->data[L->count].course2);
	printf("Input the score of English: "); scanf("%lf",&L->data[L->count].course3); getchar();//���߿ո�
	L->data[L->count].sum = L->data[L->count].course1+L->data[L->count].course2+L->data[L->count].course3;
	
	L->count++;//��һ
	printf("SUCCESS\n");
	return true;
}

/*ListRecord:��ӡ�ڴ��е����м�¼*/
void ListRecord(RecordList *L)
{
	int i;
	for(i = 0; i < L->count; i++){
		printf("\nRECORDS_%d:\n",i+1);
		printf("num:%s\nChinese:%.2lf\nmath:%.2lf\nEnglish:%.2lf\nsum:%.2lf\n",L->data[i].num,L->data[i].course1,L->data[i].course2,L->data[i].course3,L->data[i].sum);
	}
	printf("\n---END---\n");
}

/*SearchRecord:����ѧ�ţ�����ĳ����¼����ӡ�������ظü�¼���߼��±ꣻѰ��ʧ���򷵻�0*/
int SearchRecord(RecordList *L)
{
	int i;
	char key[NumSize];
	printf("Input the student number(%dnumber): ",NumSize-1);
	scanf("%s",key);
	getchar();
	for(i = 0; i < L->count; i++)
		if(strcmp(key,L->data[i].num)==0){//ֻ��Ѱ��һ��ƥ��ļ�¼
			printf("\nRECORDS_%d:\n",i+1);
		    printf("num:%s\nChinese:%.2lf\nmath:%.2lf\nEnglish:%.2lf\nsum:%.2lf\n",L->data[i].num,L->data[i].course1,L->data[i].course2,L->data[i].course3,L->data[i].sum);
			return i+1;
	}
	printf("Can not find the record!\n");
	return 0;
}

/*DelRecord:����ѧ�ţ�ɾ��ĳ����¼*/
bool DelRecord(RecordList *L)
{
	int i;
	int k;
	char mychoice;
	k = SearchRecord(L);
	if(k == 0)
	{
		printf("Can not delete the record!\n");
		return false;
	}
	else
	{
		mychoice = '\n';
		printf("Would you like to delete the record?(y/n)\n");
		while(1)
		{
			scanf("%c",&mychoice);
			getchar();  //���߿ո�
			if(mychoice == 'y')
				break;
			else if(mychoice == 'n')
				return false;
			else
				printf("Unknown order. Try again.\n");
		}
	}
	for(i = k; i < L->count; i++)
		L->data[i-1] = L->data[i];
	//��k��Ԫ�ص���count-1��Ԫ��ǰ��(ɾ��Ԫ��Ϊ��k-1��Ԫ�أ�ע��k���߼��±�)
	L->count--;//��һ
	
	printf("SUCCESS\n");
	return true;
}

/*ModifyRecord:����ѧ�ţ��޸�ĳ����¼*/
bool ModifyRecord(RecordList *L)
{
	int k;
	char mychoice;
	k = SearchRecord(L);
	if(k == 0)
	{
		printf("Can not Modify the record!\n");
		return false;
	}
	else
	{
		mychoice = '\n';
		printf("Would you like to Modify the record?(y/n)\n");
		while(1)
		{
			scanf("%c",&mychoice);
			getchar();  //���߿ո�
			if(mychoice == 'y')
				break;
			else if(mychoice == 'n')
				return false;
			else
				printf("Unknown order. Try again.\n");
		}
	}
	printf("Modifying...\n");
	printf("Input the student number(%dnumber): ",NumSize-1); scanf("%s",L->data[k-1].num);
	printf("Input the score of Chinese: "); scanf("%lf",&L->data[k-1].course1);
	printf("Input the score of math: "); scanf("%lf",&L->data[k-1].course2);
	printf("Input the score of English: "); scanf("%lf",&L->data[k-1].course3); getchar();//���߿ո�
	L->data[k-1].sum = L->data[k-1].course1+L->data[k-1].course2+L->data[k-1].course3;
	
	printf("SUCCESS\n");
	return true;
}

/*SumSort_d:�����ܷ�Ϊ���ݽ��н�������ʹ��ð�����򷨡�*/
void SumSort_d(RecordList *&L)
{
	int i,j;
	Student temp;
	for(i = 0; i < L->count-1; i++)
		for(j = 0; j < L->count-1-i; j++)
			if(L->data[j].sum < L->data[j+1].sum)
			{
				temp = L->data[j];
				L->data[j] = L->data[j+1];
				L->data[j+1] = temp;
			}
	printf("SUCCESS\n");
}

/*SumSort_a:�����ܷ�Ϊ���ݽ�����������ʹ��ð�����򷨡�*/
void SumSort_a(RecordList *&L)
{
	int i,j;
	Student temp;
	for(i = 0; i < L->count-1; i++)
		for(j = 0; j < L->count-1-i; j++)
			if(L->data[j].sum > L->data[j+1].sum)
			{
				temp = L->data[j];
				L->data[j] = L->data[j+1];
				L->data[j+1] = temp;
			}
	printf("SUCCESS\n");
}

/*NumSort_d:����ѧ��Ϊ���ݽ��н�������ʹ��ð�����򷨡�*/
void NumSort_d(RecordList *&L)
{
	int i,j;
	Student temp;
	for(i = 0; i < L->count-1; i++)
		for(j = 0; j < L->count-1-i; j++)
			if(strcmp(L->data[j].num,L->data[j+1].num) < 0)
			{
				temp = L->data[j];
				L->data[j] = L->data[j+1];
				L->data[j+1] = temp;
			}
	printf("SUCCESS\n");
}

/*NumSort_d:����ѧ��Ϊ���ݽ�����������ʹ��ð�����򷨡�*/
void NumSort_a(RecordList *&L)
{
	int i,j;
	Student temp;
	for(i = 0; i < L->count-1; i++)
		for(j = 0; j < L->count-1-i; j++)
			if(strcmp(L->data[j].num,L->data[j+1].num) > 0)
			{
				temp = L->data[j];
				L->data[j] = L->data[j+1];
				L->data[j+1] = temp;
			}
	printf("SUCCESS\n");
}

int main()
{
	FILE *fp;             //�ļ�ָ��
	RecordList *L;        //�ڴ������ݵ�ָ��
	char choice;          //���ڶ�ȡ�û��Ĳ���
	
	if((fp=fopen("scores.txt","rb+")) == NULL){//���ļ�����ʧ������ʾ�Ƿ񴴽����ļ�
		printf("Can not open file scores.txt!\n");
		printf("Would you like to create a new file?(y/n)\n");
		choice = '\0';
		while(1){
		    scanf("%c",&choice);
			getchar(); //���߿ո�
			if(choice == 'y')
				break;
			else if(choice == 'n')
		        exit(0);
			else
				printf("Unknown order. Try again.\n");
		}
		fp = fopen("scores.txt","wb+");    //����һ���µĶ������ļ�scores.txt
		/*wb+:�Զ�/д��ʽ�򿪻���һ���������ļ����������д��
		���ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ�
	    �������������ļ���*/
	}
	size = sizeof(Student);                         //����Student�ṹ������
	L = (RecordList*)malloc(sizeof(RecordList));    //��������ڴ�ռ�
	L->count = GetRecordCount(fp);                  //�����¼����
	fseek(fp,0,SEEK_SET);                           //�ƶ��ļ�ָ������ͷ
	fread(L->data,size,L->count,fp);                //��ȡ��Ӧ����������
	SaveFlag = 1;                                   //��ʼ��1
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	/*����Ϊ����ĳ�ʼ������*/
	
	while((choice = Inputchoice())!='0'){
		switch(choice){//��ȡ����'0'�����ָ�ע��SaveFlag�ı仯��
			case '1':AddRecord(L); SaveFlag = 0; break;
			case '2':ListRecord(L); break;
			case '3':DelRecord(L); SaveFlag = 0; break;
			case '4':ModifyRecord(L); SaveFlag = 0; break;
			case '5':SearchRecord(L); break;
			case '6':SumSort_d(L); SaveFlag = 0; break;
			case '7':SumSort_a(L); SaveFlag = 0; break;
			case '8':NumSort_d(L); SaveFlag = 0; break;
			case '9':NumSort_a(L); SaveFlag = 0; break;
			case 'W':FileWrite(L); SaveFlag = 1; break;
			case 'R':FileRead(L); SaveFlag = 1; break;
			default :printf("Unknown order. Try again.\n");break;
		}
	}
	/*����Ϊ�����ִ�в���*/
	
	if(SaveFlag == 0){//�˳�ǰû�������ѱ���
		printf("Your changes are not saved. Would you like to save them?(y/n)\n");
	    choice = '\0';
	    while(1)
	    {
		    scanf("%c",&choice);
		    getchar();  //���߿ո�
		    if(choice == 'y'){
		    FileWrite(L); SaveFlag = 1;break;}
		    else if(choice == 'n')
			    break;
		    else
			    printf("Unknown order. Try again.\n");
	    }
	}
	/*����Ϊ����Ľ�������*/
	
	return 0;
}