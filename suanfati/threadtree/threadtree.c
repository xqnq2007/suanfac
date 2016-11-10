#include "stdio.h"
#include "stdlib.h"
typedef enum{
	left = 1,
	right = 2
}direction;
typedef enum{
	thread = 1,
	subtree = 2	
}nodetype;
typedef struct chainnode{
	char data;
	struct chainnode* left;
	struct chainnode* right;
	nodetype lefttype;
	nodetype righttype;
}node;
node* initTree(char k){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = k;
	return tmp;
}
int insert(node* root, char cur, char new, direction d){
	if (root == NULL){		
		return 0;
	}
	if (root->data == cur){
		node* tmp=(node*)malloc(sizeof(node));
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->data = new;
		if (d == 1){
			if (root->left){
				printf("该处已有结点\n");
				return 0;
			}
			root->left = tmp;
		}
		else{
			if (root->right){
				printf("该处已有结点\n");
				return 0;
			}
			root->right = tmp;
		}			
		return 1;
	}
	return insert(root->left, cur, new, d) + insert(root->right, cur, new, d);
}
void buildThreadTree(node* root, node* preNode){
	if (root == NULL){
		return;
	}
	buildThreadTree(root->left, preNode);
	if (root->left)root->lefttype = subtree;
	else root->lefttype = thread;
	if (root->right)root->righttype = subtree;
	else root->righttype = thread;
	if (preNode != NULL){
		if (root->lefttype == 1){
			root->left = preNode;
		}
		if (preNode->righttype == 1)
			preNode->right = root;
	}
	preNode=root;
	buildThreadTree(root->right, preNode);
}
void main(){
	node* root = NULL;
	root = initTree('A');
	insert(root, 'A', 'B', left);
	insert(root, 'A', 'C', right);
	insert(root, 'B', 'D', left);
	//printf("%c\n", root->left->left->data);
	node* prenode = NULL;
	buildThreadTree(root, prenode);
	printf("%c\n", root->left->right->data);
	system("PAUSE");
}
