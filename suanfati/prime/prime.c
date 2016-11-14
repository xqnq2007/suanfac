#include "stdio.h"
#include "stdlib.h"
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
		/*printf("��%d�� \n",vsize);
		printf("V������ֵ:\n");
		int tmpvhead = vhead;
		for (int i = 0; i < vsize; i++){
			printf("%d \n", v[tmpvhead]);
			tmpvhead = (tmpvhead + 1) % vertexnum;
		}
		printf("U������ֵ:\n");
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
				//printf("vvertex:%d uvertex:%d ��ǰѭ����Ȩֵ��%d\n", vvertex, uvertex,g->edge[vvertex][uvertex]);
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
		//printf("���%d ��ӽ��%d \n", minvvertex, minuvertex);		
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
	printf("ͼ����%d\n", g->graphtype);
	for (int i = 0; i < 5; i++){
		printf("��%d������ֵ%d\n", i + 1, g->vertex[i]);
		printf("��%d������Ƿ����%d\n", i + 1, g->istranverse[i]);
	}
}
void displaymintree(minTreeNode m[]){
	for (int i = 0; i < vertexnum; i++){
		printf("��%d�����\n", i+1);
		printf("vertex:%d\n", m[i].vertex);
		printf("minTree[%d].linkNode:\n",i);
		for (int j = 0; j < m[i].linkNodeNum; j++){
			printf("%d ", m[i].linkNode[j]);
		}
		printf("\n");
		printf("minTree[%d].linkNodeNum:%d\n",i, m[i].linkNodeNum);		
	}
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
	minTreeNode* mintree;
	mintree = buidMinTree(g);	
	displaymintree(mintree);	
	system("PAUSE");
}