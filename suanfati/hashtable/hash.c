#include "stdio.h"
//#include "stdlib.h"
void inserthash(int* hash,int key, int hashlen){
	int hashaddr = key%hashlen;
	while(hash[hashaddr] != 0){
		hashaddr = (++hashaddr) % hashlen;
	}
	hash[hashaddr] = key;
}
int searchhash(int* hash, int key, int hashlen){
	int hashaddr = key%hashlen;
	while(hash[hashaddr] != 0&&hash[hashaddr]!=key){
		hashaddr = (++hashaddr) % hashlen;
	}
	if (hash[hashaddr] == 0){
		return -1;
	}
	return hashaddr;
}
void main(){
	int hashlength = 13;
	int a[5] = { 15, 13, 16, 17, 13 };
	int hash[13] = {0};
	//printf("¹şÏ£µØÖ·£º%d\n",hash[2]);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
		inserthash(hash, a[i], 13);
	}
	int c=0;
	while (c!=100){
		scanf("%d", &c);
		printf("¹şÏ£µØÖ·£º\n");
		printf("%d\n", searchhash(hash, c, 13));
	}
	
	//getchar();
	system("PAUSE");
}