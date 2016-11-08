#include "stdio.h"
typedef struct student{
	int id;
	char name[10];
	int age;
}stu;
typedef struct chainnode{
	stu data;
	stu* next;
}node;
void init(node* head){	
	head->next = NULL;	
}
int isEmpty(node* head){
	if (head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int getlen(node* head){
	int num = 0;
	while (head!= NULL){
		++num;
		head = head->next;
	}
	return num;
}
void add(node* head,stu s){
	if (head==NULL){		
		node* tmp=(node*)malloc(sizeof(node));
		tmp->data= s;
		tmp->next = NULL;
		head = tmp;		
		return;
	}
	else{
		node* tmpnode;
		tmpnode= head;
		while (tmpnode != NULL){
			tmpnode = tmpnode->next;
		}
		node* tmp = (node*)malloc(sizeof(node));
		tmp->data = s;
		tmp->next = NULL;
		tmpnode = tmp;
		return head;		
	}
}
void display(node* head){
	while (head != NULL){
		printf("id:%d \t name:%s\t age:%d\n", head->data.id,head->data.name,head->data.age);
		head = head->next;
	}
}
void main(){	
	node* head = NULL;	
	head = (node*)malloc(sizeof(node));
	stu s1 = {111,"Íõ",21};
	stu s2 = { 112, "Àî", 21 };
	stu s3 = { 113, "ÃÏ", 21 };
	add(head, s1);
	//add(head, s2);
	//add(head, s3);
	//display(head);	
	//printf("%d \n", isEmpty(head));
	printf("%d \n",head->data.age);
	system("PAUSE");
}