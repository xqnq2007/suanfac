#include "stdio.h"
#include "stdlib.h"
typedef struct node{
	struct node* left;
	struct node* right;
	int value;
}bstree;
void initbstree(bstree* bs,int key){
	bs->left = NULL;
	bs->right = NULL;
	bs->value = key;
}
int insert(bstree* bs,int key){
	while (bs){
		if (key < bs->value){
			if (bs->left)
				bs = bs->left;
			else{
				bstree* tmp = (bstree*)malloc(sizeof(bstree));
				tmp->left = NULL;
				tmp->right = NULL;
				tmp->value = key;				
				bs->left = tmp;	
				return 1;
			}
		}
		else if (key > bs->value){
			if (bs->right){
				bs = bs->right;
			}
			else{
				bstree* tmp1 = (bstree*)malloc(sizeof(bstree));
				tmp1->left = NULL;
				tmp1->right = NULL;
				tmp1->value = key;
				bs->right = tmp1;
				return 1;
			}
		}
		else{
			printf("该值已经存在\n");
			return 0;
		}
	}
}
bstree* search(bstree* bs, int key){
	while (bs){
		if (key < bs->value){			
			bs = bs->left;			
		}
		else if (key > bs->value){			
			bs = bs->right;						
		}
		else{
			return bs;
		}
	}
	if (bs == NULL)
		return NULL;
}
bstree* getPar(bstree* bs, int tmp){
	if (bs->value == tmp)
		return NULL;
	bstree* tmpleft;
	bstree* tmpright;
	
	while (!(tmpleft->value == tmp || tmpright->value == tmp)){
		if ()
	}
	while (bs){
		if (bs->value > tmp){
			if (bs->left){
				if (bs->left->value == tmp){
					return bs;
				}
				else if (bs->left->value > tmp){
					bs = bs->left->right;
				}
				else{
					bs = bs->left->left;
				}
			}
		}
		else{}

	}
}
void main(){
	bstree* root = (bstree*)malloc(sizeof(bstree));
	int a[12] = {5,16,3,12,20,10,13,18,23,6,7,6};
	initbstree(root,15);
	for (int i = 0; i < 12; i++){
		insert(root, a[i]);
	}
	
	while (1){
		int c;
		printf("请输入需要检索的数据\n");
		scanf("%d", &c);
		bstree* sp;
		sp = search(root, c);
		if (sp)
			printf("%d\n",sp->value);
		else
			printf("没有该数据\n");
	}
	
	system("PAUSE");
}