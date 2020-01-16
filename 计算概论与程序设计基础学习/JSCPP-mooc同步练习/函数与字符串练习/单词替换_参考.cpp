//这个方案分割每一个单词，并且直接调用相关的string函数，简单并且可读性很高
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
const int INF=1<<29;
int main(){
	char s[100][100];
	int cnt=0;
	while(1){
		scanf("%s",s[cnt++]);
		char c=getchar();
		if(c=='\n') break; 
	} 
	char a[100],b[100];
	scanf("%s%s",a,b);
	for(int i=0;i<cnt;i++){
		if(strcmp(s[i],a)==0){
			strcpy(s[i],b);
		}
	}
	printf("%s",s[0]);
	for(int i=1;i<cnt;i++) printf(" %s",s[i]);
	return 0;
}