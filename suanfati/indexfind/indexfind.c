#include "stdio.h"
#define getlen(arr)(sizeof(arr)/sizeof(arr[0]))
typedef struct{
	int index;
	int start;
	int length;
}indexItem;
indexItem itm[3] = { { 1, 0, 5 }, { 2, 10, 4 }, { 3, 20, 3 } };
int student[30] = { 100, 101, 103, 104, 105, 0, 0, 0, 0, 0,
201, 204, 205, 206, 0, 0, 0, 0, 0, 0,
301, 305, 306, 0, 0, 0, 0, 0, 0, 0
};
int insert(int key){
	int indexnum = key/100;
	int tmpItem=-1;
	indexItem tmp = {0,0,0};
	for (int i = 0; i < sizeof(itm) / sizeof(itm[0]); i++){
		if (indexnum == itm[i].index){
			//tmpItem = itm[i].index,itm[i].start,itm[i].length};
			tmpItem = i;
			tmp.start = itm[i].start;
			tmp.length = itm[i].length;			
			break;
		}
	}
	if (tmpItem == -1)
		return -1;
	if (tmp.length >= 10){
		printf("���Ѿ����ˣ�\n");
		return -1;
	}
	student[tmp.start + tmp.length] = key;
	itm[tmpItem].length++;
	return 1;
}
int search(int key){
	int indexnum = key /100;
	int tmpItem=NULL;
	for (int i = 0; i < sizeof(itm) / sizeof(itm[0]); i++){
		if (indexnum == itm[i].index){
			for (int j = itm[i].start; j < itm[i].start + itm[i].length; j++){
				if (student[j] == key){
					tmpItem = itm[i].index;
					return j;					
				}
			}	
		}
	}
	if (tmpItem == NULL)
		return -1;	
}
int getlen1(int* a){
	int num = 0;
	while (a[num]!=NULL){
		num++;
	}
	return num;
}
void main(){
	while (1){
		printf("��ѡ��\n");
		printf("1����������\n");
		printf("2����������\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1){
			printf("��������ǰ��\n");
			for (int i = 0; i < getlen(student); i++){
				printf("%-5d ", student[i]);
				if ((i + 1) % 10 == 0){
					printf("\n");
				}
			}
			printf("\n************\n");
			int key;
			scanf("%d", &key);			
			if (insert(key) != -1){
				printf("�������ݺ�\n");
				for (int i = 0; i < getlen(student); i++){
					printf("%-5d ", student[i]);
					if ((i + 1) % 10 == 0){
						printf("\n");
					}
				}
				printf("\n************\n");
				printf("��������λ�ã�%d\n ", search(key));
			}
			else{
				printf("��������ʧ�ܣ�\n");
			}
		}
		else{
			int skey;
			scanf("%d", &skey);
			if (search(skey)!=-1)
				printf("��������λ�ã�%d\n ", search(skey));
			else
				printf("�޴�����\n");
		}
	}
		
		
	
	
	
	//printf("%d\n",itm[1].index);
	system("PAUSE");
	
}