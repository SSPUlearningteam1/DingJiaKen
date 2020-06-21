#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************/
/*学生信息管理系统(顺序表结构)*/
/******************************/

#define MaxSize 100  //最大学生记录数量
#define NumSize 8    //学号长度。要注意C语言的规定，实际上只能输入NumSize-1位学号

int size;            //一个记录的字节大小
int SaveFlag;        //用于表示当前的保存状态。0表示有修改，未保存。

typedef struct Student_str{//结构体定义
	char num[NumSize];    //学号
	double course1; //科目1，定为语文
	double course2; //科目2，定为数学
	double course3; //科目3，定为英语
	double sum;     //总分
}Student;

typedef struct SqList{//建立顺序表来管理记录
	Student data[MaxSize];    //学生记录
	int count;                //记录数量
}RecordList;//记录表

/*Inputchoice:显示提示信息并读取用户的操作*/
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
	getchar();  //读走空格
	return mychoice;
}

/*GetRecordCount:获取记录数量*/
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

/*FileRead:读取文件信息到内存中*/
void FileRead(RecordList *&L)
{
	FILE *fp;
	if((fp=fopen("scores.txt","rb+")) == NULL){//打开文件，若失败则程序结束
		printf("Can not open file scores.txt!\n");
		exit(0);
	}
	/*rb+:以读/写方式打开一个二进制文件，只允许读/写数据。若文件不存在则返回NULL。*/
	L->count = GetRecordCount(fp);        //计算记录总数
	fseek(fp,0,SEEK_SET);                 //移动文件指针至开头
	fread(L->data,size,L->count,fp);      //读取相应数量的数据
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
}

/*FileWrite:存取内存数据，覆盖原文件*/
void FileWrite(RecordList *L)
{
	FILE *fp;
	fp = fopen("scores.txt","wb");
	/*wb:以只写方式打开或新建一个二进制文件，只允许写数据。
	若文件存在则文件长度清为零，即该文件内容会消失。若文件
	不存在则建立该文件。*/
	fseek(fp,0,SEEK_SET);                 //移动文件指针至开头
	fwrite(L->data,size,L->count,fp);     //写入相应数量的数据
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
}

/*AddRecord:添加记录至L->data[count]*/
bool AddRecord(RecordList *&L)
{
	if(L->count == MaxSize){//已达最大容量，显示空间不足，返回false
		printf("Insufficient space!\n");
		return false;
	}
	
	printf("adding...\n");
	printf("Input the student number(%dnumber): ",NumSize-1); scanf("%s",L->data[L->count].num);
	printf("Input the score of Chinese: "); scanf("%lf",&L->data[L->count].course1);
	printf("Input the score of math: "); scanf("%lf",&L->data[L->count].course2);
	printf("Input the score of English: "); scanf("%lf",&L->data[L->count].course3); getchar();//读走空格
	L->data[L->count].sum = L->data[L->count].course1+L->data[L->count].course2+L->data[L->count].course3;
	
	L->count++;//加一
	printf("SUCCESS\n");
	return true;
}

/*ListRecord:打印内存中的所有记录*/
void ListRecord(RecordList *L)
{
	int i;
	for(i = 0; i < L->count; i++){
		printf("\nRECORDS_%d:\n",i+1);
		printf("num:%s\nChinese:%.2lf\nmath:%.2lf\nEnglish:%.2lf\nsum:%.2lf\n",L->data[i].num,L->data[i].course1,L->data[i].course2,L->data[i].course3,L->data[i].sum);
	}
	printf("\n---END---\n");
}

/*SearchRecord:输入学号，搜索某个记录并打印，并返回该记录的逻辑下标；寻找失败则返回0*/
int SearchRecord(RecordList *L)
{
	int i;
	char key[NumSize];
	printf("Input the student number(%dnumber): ",NumSize-1);
	scanf("%s",key);
	getchar();
	for(i = 0; i < L->count; i++)
		if(strcmp(key,L->data[i].num)==0){//只找寻第一个匹配的记录
			printf("\nRECORDS_%d:\n",i+1);
		    printf("num:%s\nChinese:%.2lf\nmath:%.2lf\nEnglish:%.2lf\nsum:%.2lf\n",L->data[i].num,L->data[i].course1,L->data[i].course2,L->data[i].course3,L->data[i].sum);
			return i+1;
	}
	printf("Can not find the record!\n");
	return 0;
}

/*DelRecord:输入学号，删除某个记录*/
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
			getchar();  //读走空格
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
	//第k个元素到第count-1个元素前移(删除元素为第k-1个元素，注意k是逻辑下标)
	L->count--;//减一
	
	printf("SUCCESS\n");
	return true;
}

/*ModifyRecord:输入学号，修改某个记录*/
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
			getchar();  //读走空格
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
	printf("Input the score of English: "); scanf("%lf",&L->data[k-1].course3); getchar();//读走空格
	L->data[k-1].sum = L->data[k-1].course1+L->data[k-1].course2+L->data[k-1].course3;
	
	printf("SUCCESS\n");
	return true;
}

/*SumSort_d:根据总分为依据进行降序排序。使用冒泡排序法。*/
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

/*SumSort_a:根据总分为依据进行升序排序。使用冒泡排序法。*/
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

/*NumSort_d:根据学号为依据进行降序排序。使用冒泡排序法。*/
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

/*NumSort_d:根据学号为依据进行升序排序。使用冒泡排序法。*/
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
	FILE *fp;             //文件指针
	RecordList *L;        //内存中数据的指针
	char choice;          //用于读取用户的操作
	
	if((fp=fopen("scores.txt","rb+")) == NULL){//打开文件，若失败则提示是否创建新文件
		printf("Can not open file scores.txt!\n");
		printf("Would you like to create a new file?(y/n)\n");
		choice = '\0';
		while(1){
		    scanf("%c",&choice);
			getchar(); //读走空格
			if(choice == 'y')
				break;
			else if(choice == 'n')
		        exit(0);
			else
				printf("Unknown order. Try again.\n");
		}
		fp = fopen("scores.txt","wb+");    //创建一个新的二进制文件scores.txt
		/*wb+:以读/写方式打开或建立一个二进制文件，允许读和写。
		若文件存在则文件长度清为零，即该文件内容会消失。若文件
	    不存在则建立该文件。*/
	}
	size = sizeof(Student);                         //计算Student结构体容量
	L = (RecordList*)malloc(sizeof(RecordList));    //申请最大内存空间
	L->count = GetRecordCount(fp);                  //计算记录总数
	fseek(fp,0,SEEK_SET);                           //移动文件指针至开头
	fread(L->data,size,L->count,fp);                //读取相应数量的数据
	SaveFlag = 1;                                   //初始置1
	if(fclose(fp)){
		printf("Can not close the file!\n");
		exit(0);
	}
	/*以上为程序的初始化部分*/
	
	while((choice = Inputchoice())!='0'){
		switch(choice){//读取除了'0'以外的指令。注意SaveFlag的变化。
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
	/*以上为程序的执行部分*/
	
	if(SaveFlag == 0){//退出前没保存提醒保存
		printf("Your changes are not saved. Would you like to save them?(y/n)\n");
	    choice = '\0';
	    while(1)
	    {
		    scanf("%c",&choice);
		    getchar();  //读走空格
		    if(choice == 'y'){
		    FileWrite(L); SaveFlag = 1;break;}
		    else if(choice == 'n')
			    break;
		    else
			    printf("Unknown order. Try again.\n");
	    }
	}
	/*以上为程序的结束部分*/
	
	return 0;
}