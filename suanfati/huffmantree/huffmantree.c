#include "stdio.h"
#include "stdlib.h"
#include "string.h"s
char * join2(char *str1, char *str2);
typedef struct{
	int weight;
	int parent;
	int left;
	int right;
}huffnode;
char* reversestr(char* p){
	int len = strlen(p);
	char *result = (char*)malloc(len);
	for (int i = 0; i < len; i++)
		*(result + i) = *(p + len - 1 - i);
	*(result + len) = '\0';
	return result;
}
void selectMinTwoNode(huffnode* hufftree, int nodeNum, int* node1Index, int* node2Index){
	int index1 = -1;
	int index2 = -1;
	for (int i = 0; i < nodeNum; i++){
		if (hufftree[i].parent == -1){
			if (index1 == -1){
				*node1Index = i;
				index1 = 0;
				continue;
			}
			if (index2 == -1){
				*node2Index = i;
				index2 = 0;
				if (hufftree[*node1Index].weight > hufftree[*node2Index].weight){
					huffnode tmp = hufftree[*node1Index];
					hufftree[*node1Index] = hufftree[*node2Index];
					hufftree[*node2Index] = tmp;
					int tmpIndex = *node1Index;
					*node1Index = *node2Index;
					*node2Index = tmpIndex;
				}
				continue;
			}
			if (index1 != -1 && index2 != -1){
				if (hufftree[i].weight < hufftree[*node1Index].weight){
					//printf("交换了1\n");
					hufftree[*node2Index] = hufftree[*node1Index];
					hufftree[*node1Index] = hufftree[i];
					*node2Index = *node1Index;
					*node1Index = i;
				}
				else{
					if (hufftree[i].weight < hufftree[*node2Index].weight){
						//printf("第一个权重：%d 第二个权重：%d \n", hufftree[i].weight, hufftree[*node2Index].weight);
						//printf("i的值:%d 第一个索引：%d 第二个索引：%d \n", i,*node1Index, *node2Index);
						//printf("交换了2\n");
						/*huffnode tmp = hufftree[*node2Index];
						hufftree[*node2Index] = hufftree[i];
						hufftree[*node2Index] = tmp;*/
						//hufftree[*node2Index] = hufftree[i];
						*node2Index = i;
					}
				}
			}
		}
	}
}
void creatHuffTree(huffnode* hufftree, int leafNum, int* leafWeight){
	int huffNodeNum = 2 * leafNum - 1;

	for (int i = 0; i < huffNodeNum; i++){
		hufftree[i].parent = -1;
		if (i < leafNum){
			hufftree[i].weight = leafWeight[i];
		}
		else
			hufftree[i].weight = 0;
	}
	int* node1 = (int*)malloc(sizeof(int));
	int* node2 = (int*)malloc(sizeof(int));
	for (int i = leafNum; i < huffNodeNum; i++){
		//printf("******\n");
		for (int j = 0; j < i; j++){
			//printf("权重%d 父亲%d 左%d 右%d\n", hufftree[j].weight, hufftree[j].parent, hufftree[j].left, hufftree[j].right);
		}
		*node1 = -1;
		*node2 = -1;
		selectMinTwoNode(hufftree, i, node1, node2);

		//printf("%d %d\n", hufftree[*node1].weight, hufftree[*node2].weight);
		//printf("此时的结点数：%d\n", huffNodeNum);


		hufftree[*node1].parent = i;
		hufftree[*node2].parent = i;
		hufftree[i].left = *node1;
		hufftree[i].right = *node2;
		hufftree[i].weight = hufftree[*node1].weight + hufftree[*node2].weight;

	}
}
void test(char* a[][10]){
	(*a)[1] = "abvc";
}

int getcharlen(char* str){
	return strlen(str);
}
void huffCoding(huffnode* hufftree, int leafNum, char* a[][10]){
	int cur;
	int par;
	cur =par= 0;
	for (int i = 0; i < leafNum; i++){
		cur = i;
		par = hufftree[cur].parent;
		char* s = "";
		//printf("%d %d\n", cur, par);
		while (par != -1){
			//printf("%d %d\n",cur,par);
			if (cur == hufftree[par].left){
				s = join2(s,"0");
				//printf("0\n");
			}
			else{
				s = join2(s, "1");
				//printf("1\n");
			}
			cur = par;
			par = hufftree[par].parent;
		}
		(*a)[i] = reversestr(s);
	}


}

char* join(char* str1, char* str2){
	char* result = (char*)malloc(strlen(str1)+strlen(str2)+1);
	if (result == NULL){
		printf("合并字符串失败\n");
		return NULL;
	}
	
	char* c = (char*)malloc(strlen(str1) + strlen(str2) + 1);
	c = result;
	while (*str1 != '\0'){
		*result++ = *str1++;
	}
	while (*str2 != '\0'){
		*result++ = *str2++;
	}
	return c;
}
char* join2(char* str1, char* str2){
	char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
	if (result == NULL){
		printf("合并字符串失败\n");
		return NULL;
	}
	strcpy(result, str1);
	strcat(result, str2);
	return result;
}
char* huffEncode(char* a[][10], char* test, char* alphabet){
	char* result = "";
	for (int i = 0; i < strlen(test); i++){
		for (int j = 0; j < strlen(alphabet); j++){
			//printf("%c %c", test[i], alphabet[j]);
			if (test[i]==alphabet[j]){
				//printf("%s", (*a)[j]);
				result = join2(result, (*a)[j]);
			}
		}		
	}	
	return result;
}
char* huffDecode(huffnode* hufftree, int huffNode,char* test, char* alphabet){
	
	char* result = "";
	for (int i = 0; i < strlen(test); ){
		int j = huffNode - 1;
		
		while(hufftree[j].left >= 0 || hufftree[j].right>= 0){
			//printf("当前字符%c 当前结点%d", test[i], j);
			if (test[i] == '0')
				j = hufftree[j].left;
			else
				j = hufftree[j].right;
			i++;
		}
		//printf("%s", { alphabet[j] });
		char  tmp = alphabet[j];
		char tmp1[2] = { tmp };
		result = join2(result,tmp1);
	}
	return result;
}
char* clearstr(char* str){
	char* result = (char*)malloc(sizeof(strlen(str)+1));
	int i = 0;
	int j = 0;
	for (int i = 0; i < strlen(str); i++){
		if (str[i] != ' '){
			result[j++] = str[i];
		}
		
	}
	result[j] = '\0';
	return result;
}
void main(){
	/*char *a[2][10] = { "Hello", "ddd" };
	test(a);
	printf("%s ",(*a)[1]);*/
	huffnode hufftree[100];
	int leafWeight[4] = { 2, 5, 7, 13 };
	creatHuffTree(hufftree, 4, leafWeight);
	for (int i = 0; i < 9; i++){
		//printf("%d ", hufftree[i].weight);
	}
	char *a[4][10] = {"","","",""};
	huffCoding(hufftree,4,a);
	for (int i = 0; i < 7; i++){
		//printf("权重%d父亲%d左%d右%d\n", hufftree[i].weight, hufftree[i].parent, hufftree[i].left, hufftree[i].right);
	}
	for (int i = 0; i < 4; i++){
		printf("%s ", (*a)[i]);
	}
	char words[4] = "cabd";
	//char* tmp=huffEncode(a, "abcd", words);
	FILE *sfp, *df;
	int i;
	/*char buff[5000]="";
	sfp = fopen("D:\\source.txt","r");
	i = 0;
	while (!feof(sfp)){
		buff[i++] = fgetc(sfp);
		
	}
	df = fopen("D:\\result.txt", "w");
	fclose(sfp);
	char* tmp = huffEncode(a, buff, words);
	for (int i = 0; i < strlen(tmp); i++){
		fputc(tmp[i], df);
	}	
	fclose(df);*/
	//printf("%s", tmp);
	sfp = fopen("D:\\source.txt", "r");
	i = 0;
	char buff1[500] = "";
	char ch;
	while (!feof(sfp)){
		buff1[i++] = fgetc(sfp);
		//printf("%c", fgetc(sfp));
	}
	//char *test = "110111";
	char* tmp = huffDecode(hufftree,7, buff1, words);
	
	char* tmpbuff1= clearstr(buff1);
	printf("%s", tmpbuff1);
	system("PAUSE");
}