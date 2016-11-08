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
	
	while (bs){
		if (bs->left){
			if (bs->left->value == tmp){
				return bs;
			}
		}
		if (bs->right){
			if (bs->right->value == tmp){
				return bs;
			}
		}
		if (tmp > bs->value && bs->right){
			bs = bs->right;
		}else if (tmp < bs->value && bs->left){
			bs = bs->left;
		}
	}
	
}
int delete(bstree* root,int key){
	if (key == root->value){
		free(root);
		return 1;
	}
	bstree* tmp = search(root,key);
	bstree* par=getPar(root,key);
	if (!(tmp->left || tmp->right)){		
		free(tmp);
		return 1;		
	}
	if (!(tmp->left && tmp->right)){
		if (tmp->left){
			if (par->left == tmp){
				par->left = tmp->left;
				free(tmp);
				return 1;
			}
			else{
				par->right = tmp->left;
				free(tmp);
				return 1;
			}
			
		}
		if (tmp->right){
			if (par->left == tmp){
				par->left = tmp->right;
				free(tmp);
				return 1;
			}
			else{
				par->right = tmp->right;
				free(tmp);
				return 1;
			}
		}
	}
	if (tmp->left && tmp->right){
		bstree* p = tmp->right;
		bstree* s = p;
		while (s->left){
			s = s->left;
		}
		if (s != p){
			if (s->right){
				bstree* spar = getPar(root, s->value);
				printf("结点的值：%d\n", s->value);
				printf("父亲结点的值：%d\n", spar->value);
				spar->left = s->right;
				tmp->value = s->value;
				free(s);
				return 1;
			}
			else{
				tmp->value = s->value;
				free(s);
				return 1;
			}
			
			
		}
		else{			
			if (s->right){
				tmp->right = s->right;
				tmp->value = s->value;
				free(s);
				return 1;
			}
			else{
				tmp->value = s->value;
				free(s);
				return 1;
			}
		}		
		
	}
}
void main(){
	bstree* root = (bstree*)malloc(sizeof(bstree));
	int a[12] = {5,16,3,12,20,10,13,18,23,6,7,6};
	initbstree(root,15);
	for (int i = 0; i < 12; i++){
		insert(root, a[i]);
	}
	//printf("%d\n",root->right->right->left->value);
	while (1){
		int c;
		printf("请输入需要删除的数据\n");
		scanf("%d", &c);
		if (delete(root,c))
			printf("删除成功\n");
		else
			printf("删除失败\n");		
		printf("%d\n",root->left->right->value);		
	}
	/*bstree* tmp = getPar(root, 6);
	printf("%d\n", tmp->value);*/
	
	system("PAUSE");
}