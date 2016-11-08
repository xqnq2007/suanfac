#include "stdio.h"
#include "stdlib.h"
#define seqsize 100
typedef struct student{
	int id;
	char name[10];
	int age;
}stu;
typedef struct stulist{
	stu s[seqsize];
	int numlen;	
}slist;
void initlist(slist* st){
	st->numlen = 0;
}
int addlist(slist* st,stu s){
	if (st->numlen == seqsize){
		printf("线性表已经满\n");
		return 0;
	}
	st->s[st->numlen++] = s;
	return 1;
}
int insertlist(slist* st, stu s,int k){
	if (st->numlen == seqsize){
		printf("线性表已经满\n");
		return 0;
	}
	if (k<1 || k>st->numlen){
		printf("插入位置不正确\n");
		return 0;
	}
	for (int i = st->numlen; i >=k; i--){
		st->s[i] = st->s[i - 1];
	}
	st->s[k-1] = s;
	st->numlen++;
	return 1;
}
int deletelist(slist* st, int k){	
	if (k<1 || k>st->numlen){
		printf("删除位置不正确\n");
		return 0;
	}
	for (int i = k; i < st->numlen; i++){
		st->s[i-1] = st->s[i];
	}	
	st->numlen--;
	return 1;
}
int searchlist(slist* st,char* cs,stu* p){
	if (st->numlen == 0){
		printf("列表数据为空\n");		
		return 0;
	}
	int i;
	for (i = 0; i < st->numlen; i++){
		if (!strcmp(st->s[i].name,cs)){
			*p= (st->s[i]);
			return 1;
		}		
	}
	if (i == st->numlen){
		printf("无此数据\n");
		return 0;
	}
}
void displaylist(slist* st){
	if (st->numlen == 0){
		printf("列表数据为空\n");
		return 0;
	}
	for (int i = 0; i < st->numlen; i++){
		printf("第%d条数据：id:%d\t name:%s\t age:%d \n", i + 1, st->s[i].id, st->s[i].name, st->s[i].age);
	}
}
void main(){
	slist* testlist = (slist*)malloc(sizeof(slist));
	initlist(testlist);
	displaylist(testlist);
	printf("****************\n");
	stu s1 = { 111, "王", 29 };
	stu s2 = { 112, "李", 24 };
	stu s3 = { 113, "杨", 26 };
	stu s4 = { 114, "赵", 21 };
	addlist(testlist, s1);
	addlist(testlist, s2);
	addlist(testlist, s3);
	displaylist(testlist);
	//printf("第%d条数据：id:%d\t name:%s\t age:%d \n", 1, s1.id, s1.name, s1.age);
	printf("插入一条数据\n");
	insertlist(testlist, s4, 2);
	displaylist(testlist);
	printf("删除一条数据\n");
	deletelist(testlist,2);
	displaylist(testlist);
	printf("查找一条数据\n");
	stu* stup = (stu*)malloc(sizeof(stu));;
	char* na = "王";
	if (searchlist(testlist, na, stup)){
		printf("查找到的数据：id:%d\t name:%s\t age:%d \n", stup->id, stup->name, stup->age);
	};
	displaylist(testlist);
	system("PAUSE");
}