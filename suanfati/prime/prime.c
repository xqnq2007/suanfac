#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define vertexnum 5
#define edgenum 6
typedef struct node{
	int graphtype;
	int vertex[vertexnum];
	int edge[vertexnum][vertexnum];
	int istranverse[vertexnum];
}graph;
typedef struct treenode{
	int vertex;
	int linkNode[vertexnum];
	int linkNodeNum;
}minTreeNode;
minTreeNode* buidMinTree(graph* g){
	minTreeNode* minTree=(minTreeNode*)malloc(sizeof(minTreeNode)*vertexnum);	
	for (int vi = 0; vi < vertexnum; vi++){
		minTree[vi].linkNodeNum = 0;
		minTree[vi].vertex = vi;
		for (int vj = 0; vj < vertexnum; vj++){
			minTree[vi].linkNode[vj] = 0;			
		}
	}	
	int minTreeNodeNum = 0;
	int u[vertexnum] = {0,1,2,3,4};
	int v[vertexnum];
	int uhead, utail, vhead, vtail, usize, vsize;
	uhead = utail = vhead = vtail = 0;
	usize = 5;
	vsize = 0;
	int tmp = u[uhead];
	uhead = (uhead + 1) % vertexnum;
	usize--;	
	v[vtail] = tmp;
	vtail = (vtail + 1) % vertexnum;
	vsize++;	
	while (vsize <= 5){
		/*printf("第%d次 \n",vsize);
		printf("V中所有值:\n");
		int tmpvhead = vhead;
		for (int i = 0; i < vsize; i++){
			printf("%d \n", v[tmpvhead]);
			tmpvhead = (tmpvhead + 1) % vertexnum;
		}
		printf("U中所有值:\n");
		int tmpuhead = uhead;
		for (int i = 0; i < usize; i++){
			printf("%d \n", u[tmpuhead]);
			tmpuhead = (tmpuhead + 1) % vertexnum;
		}*/
		int minWeight = 100;
		int minvvertex, minuvertex;
		minvvertex = minuvertex = 0;
		int tvhead = vhead;		
		for (int i = 0; i < vsize; i++){
			int vvertex = v[tvhead];
			int tuhead = uhead;
			for (int j = 0; j < usize; j++){				
				int uvertex = u[tuhead];
				tuhead = (tuhead + 1) % vertexnum; 		
				//printf("vvertex:%d uvertex:%d 当前循环边权值：%d\n", vvertex, uvertex,g->edge[vvertex][uvertex]);
				if (g->edge[vvertex][uvertex] < minWeight&&g->edge[vvertex][uvertex]!=0){
					minvvertex = vvertex;
					minuvertex = uvertex;
					minWeight = g->edge[vvertex][uvertex];
				}
			}
			tvhead = (tvhead + 1) % vertexnum;
		}
		//printf("minvvertex:%d minuvertex:%d minWeight:%d\n", minvvertex, minuvertex, minWeight);
		//printf("minvvertex:%d linkNodeNum:%d \n", minvvertex, minTree[minvvertex].linkNodeNum);
		if (minWeight!=100)
			minTree[minvvertex].linkNode[minTree[minvvertex].linkNodeNum++] = minuvertex;
		//printf("结点%d 添加结点%d \n", minvvertex, minuvertex);		
		v[vtail] = minuvertex;
		vtail = (vtail + 1) % vertexnum;
		vsize++;
		int curu = 0;
		for (int m = uhead; m != utail; m = (m + 1) % vertexnum){
			if (u[m] == minuvertex)
				curu = m;
		}		
		if (curu == uhead){
			uhead = (uhead + 1) % vertexnum;
		}
		else {
			for (int n = curu; n != uhead; n = (n - 1 + vertexnum) % vertexnum){
				u[n] = u[(n - 1 + vertexnum) % vertexnum];
			}	
			uhead = (uhead + 1) % vertexnum;
		}
		usize--;
	}	
	return minTree;
}
void BFST(graph* g){
	for (int i = 0; i < vertexnum; i++){
		int a[5] = { 0, 0, 0, 0, 0 };
		int head, tail;
		head = tail = 0;
		a[tail] = i;
		tail = (tail + 1) % 5;
		while (head != tail){
			int tmp = a[head];
			head = (head + 1) % 5;
			if (g->istranverse[tmp] == 0){
				printf("->%d", g->vertex[tmp]);
				g->istranverse[tmp] = 1;
			}
			for (int j = 0; j < vertexnum; j++){
				if (g->istranverse[j] == 0 && g->edge[j][tmp] != 0){
					a[tail] = j;
					tail = (tail + 1) % 5;
				}
			}
		}
	}
}
void DFST_tranverse(graph* g, int i){
	if (g->istranverse[i] == 0){
		printf("->%d", g->vertex[i]);
		g->istranverse[i] = 1;
	}
	for (int j = 0; j < vertexnum; j++){
		if (g->istranverse[j] == 0 && g->edge[j][i] != 0){
			DFST_tranverse(g, j);
		}
	}

}
void DFST(graph* g){
	for (int j = 0; j < vertexnum; j++){
		if (g->istranverse[j] == 0)
			DFST_tranverse(g, j);
	}

}
void displaygraph(graph* g){
	printf("图类型%d\n", g->graphtype);
	for (int i = 0; i < 5; i++){
		printf("第%d个结点的值%d\n", i + 1, g->vertex[i]);
		printf("第%d个结点是否遍历%d\n", i + 1, g->istranverse[i]);
	}
}
void displaymintree(minTreeNode m[]){
	for (int i = 0; i < vertexnum; i++){
		printf("第%d个结点\n", i+1);
		printf("vertex:%d\n", m[i].vertex);
		printf("minTree[%d].linkNode:\n",i);
		for (int j = 0; j < m[i].linkNodeNum; j++){
			printf("%d ", m[i].linkNode[j]);
		}
		printf("\n");
		printf("minTree[%d].linkNodeNum:%d\n",i, m[i].linkNodeNum);		
	}
}
char* reversestr(char* p){
	int len = strlen(p);
	char *result = (char*)malloc(len);
	for (int i = 0; i < len; i++)
		*(result + i) = *(p + len - 1 - i);
	*(result + len) = '\0';
	return result;
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
int intToStr(int m, char* str){
	int i = 0;
	int j = 1;
	int k = 0;
	char c;
	if (m < 0)
		str[i++] = '-';
	m = m>0 ? m : -m;
	do{
		str[i] = '0' + m % 10;
		m = m / 10;
		i++;
	} while (m > 0);
	if (str[0] == '-')
		j = 1;
	else
		j = 0;
	k = i - 1;
	while (j < k){
		c = str[j];
		str[j] = str[k];
		str[k] = c;
		j++;
		k--;
	}
	str[i] = '\0';
	return i - 1;
}
void minRoute(graph* g, int* weight, int* route,int* final){	
	int v0;
	printf("请输入：\n");
	scanf("%d",&v0);
	//printf("v0：%d\n",v0);
	int tmpw;
	for (int i = 0; i < vertexnum; i++){
		//printf("g->edge[0][0]:%d", g->edge[0][0]);
		tmpw = g->edge[v0][i];
		//printf("tmpw：%d\n", tmpw);
		if (tmpw>0)
			weight[i] = tmpw;
		else
			weight[i] = 1000;
		//printf("weight:%d", weight[i]);
		route[i] = v0;
		final[i] = 0;
	}
	weight[v0] = 0;	
	printf("\n");
	final[v0] = 1;	
	for (int i = 1; i < vertexnum; i++){
		int index = 0;
		int minw = 1000;
		for (int j = 0; j < vertexnum; j++){
			tmpw = weight[j];
			printf("weight[j]:%d\n", weight[j]);
			if (tmpw<minw && final[j] == 0){
				minw = tmpw;
				index = j;
			}			
		}
		printf("minw:%d index:%d\n",minw,index);		
		final[index] = 1;
		for (int k = 0; k < vertexnum; k++){			
			if (g->edge[index][k]>0 && ((minw + g->edge[index][k])<weight[k]) && final[k] == 0){
				weight[k] = minw + g->edge[index][k];
				route[k] = index;
				printf("weight[k]:%d route[k]:%d\n", weight[k], route[k]);
			}
		}
	}	
	for (int i = 0; i < vertexnum; i++){
		if (i != v0){
			printf("到第%d个结点的最短路径值为：%d\n", i, weight[i]);
			printf("到第%d个结点的最短路径为：\n", i);
			int tmpv = i;
			char* tmp = "";			
			while (tmpv != v0){
				printf("%d->", tmpv);
				char* tmp1 = "";
				tmp = join2(tmp,intToStr(tmpv,tmp1));
				tmpv = route[tmpv];
			}
			printf("v0\n",v0);
			char* tmp2 = "";
			tmp = join2(tmp, intToStr(v0, tmp2));
			tmp = reversestr(tmp);
			printf("%s\n", tmp);
		}		
	}
}
void testarr(int* a){
	for (int i = 0; i < 5; i++){
		a[i] = i+9;
		printf("%d->", a[i]);
	}
	//printf("%d->", a);
}
void main(){
	graph* g = (graph*)malloc(sizeof(graph));
	g->graphtype = 0;
	int vtex[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++){
		g->vertex[i] = vtex[i];
		g->istranverse[i] = 0;
		for (int j = 0; j < 5; j++){
			g->edge[i][j] = 0;
		}
	}
	g->edge[0][1] = 2;
	g->edge[1][0] = 2;
	g->edge[0][2] = 5;
	g->edge[2][0] = 5;
	g->edge[0][4] = 3;
	g->edge[4][0] = 3;
	g->edge[1][3] = 4;
	g->edge[3][1] = 4;
	g->edge[2][4] = 5;
	g->edge[4][2] = 5;
	g->edge[3][4] = 2;
	g->edge[4][3] = 2;
	//DFST(g);
	//minTreeNode* mintree;
	//mintree = buidMinTree(g);	
	//displaymintree(mintree);	
	//int weight[vertexnum],route[vertexnum],final[vertexnum];
	int* weight = (int*)malloc(sizeof(int)*vertexnum);
	int* route = (int*)malloc(sizeof(int)*vertexnum);
	int* final = (int*)malloc(sizeof(int)*vertexnum);
	minRoute(g, weight, route, final);
	//printf("g->edge[0][0]:5%d", g->edge[0][0]);
	//int a[5];
	//int* a = (int*)malloc(sizeof(int)*vertexnum);
	//testarr(a);
	system("PAUSE");
}