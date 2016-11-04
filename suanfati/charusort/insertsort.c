#include "stdio.h"
#include "time.h"
void insertsort(int* a, int len){
	for (int i = 1; i < len; i++){
		int j;
		for (j = i-1; j>=0&&a[i]<a[j]; j--){
			
		}
		int tmp = a[j + 1];
		a[j + 1] = a[i];
		a[i] = tmp;
		/*int tmp = a[i];
		for (j = i - 1; j >= 0 && tmp<a[j]; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;*/
	}
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
	printf("排序后：\n");
	insertsort(a, 5000);
	t2 = clock();
	for (int i = 0; i<50; i++){
		printf("%d\n", a[i]);
	}
	duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
	/*printf("自己写的堆排序用时：%f\n", duration);
	t1 = clock();
	qsort(b, 5000, sizeof(b[0]), compInc);
	t2 = clock();
	duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("系统快速排序用时：%f\n", duration);*/
	//}

	getchar();
}
