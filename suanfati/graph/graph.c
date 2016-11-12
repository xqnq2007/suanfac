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
void BFST(graph* g){
	for (int i = 0; i < vertexnum; i++){
		int a[5] = {0,0,0,0,0};
		int head, tail;
		head = tail = 0;		
		a[tail] = i;
		tail=(tail+1)%5;		
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
void DFST_tranverse(graph* g,int i){	
		if (g->istranverse[i] == 0){
			printf("->%d", g->vertex[i]);
			g->istranverse[i] = 1;
		}
		for (int j = 0; j < vertexnum; j++){
			if (g->istranverse[j] == 0 && g->edge[j][i] != 0){
				DFST_tranverse(g,j);
			}
		}		
	
}
void DFST(graph* g){	
	for (int j = 0; j < vertexnum; j++){	
		if (g->istranverse[j]==0)
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
void main(){
	graph* g=(graph*)malloc(sizeof(graph));
	g->graphtype = 0;
	int vtex[5] = {1,2,3,4,5};
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
	DFST(g);
	
	
	//displaygraph(g);
	system("PAUSE");
}