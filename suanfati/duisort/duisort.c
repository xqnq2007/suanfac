#include "stdio.h"
#include "time.h"
void heapadjust(int* a,int parent,int length){
	int key = a[parent];
	int left = 2 * parent + 1;
	while(left < length){
		if (left + 1 < length){
			if (a[left] < a[left + 1]){
				left++;
			}			
		}
		if (key>=a[left]){
			break;
		}
		a[parent] = a[left];
		parent = left;
		left = 2 * parent + 1;
	}
	a[parent] = key;
}
void heapsort(int* a, int length){
	for (int i = length / 2 - 1; i >= 0; i--){
		heapadjust(a, i, length);
	}
	for (int i = length - 1; i > 0; i--){
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		heapadjust(a, 0, i);
	}
}
void zhijiesort(int* a,int len){	
	for (int i = 0; i < len - 1; i++){
		int keyi = i;
		for (int j = i+1; j < len; j++){
			if (a[j] < a[keyi]){
				keyi = j;
			}
		}
		if (a[i]>a[keyi]){
			int tmp = a[i];
			a[i] = a[keyi];
			a[keyi] = tmp;
		}			
	}
}
int compInc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int compDec(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
void main(){
	int a[5000], b[5000];
	//for (int ii = 0; ii<5000; ii++){
		//printf("第%d次：\n", ii);
		for (int i = 0; i < 5000; i++){
			b[i] = a[i] = rand();
		}		
		clock_t t1, t2;
		double duration;
		for (int i = 0; i<50; i++){
			printf("%d\n", a[i]);
		}
		t1 = clock();
		//heapsort(a, 50000000);
		zhijiesort(a,5000);
		t2 = clock();
		for (int i = 0; i<50; i++){
			printf("%d\n", a[i]);
		}
		duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
		printf("自己写的堆排序用时：%f\n", duration);
		t1 = clock();
		qsort(b, 5000, sizeof(b[0]), compInc);
		t2 = clock();
		duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
		printf("系统快速排序用时：%f\n", duration);
	//}
	
	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
		printf("%d\t",a[i]);
	}*/
	getchar();
}