#include "stdio.h"
#include "time.h"
#define ARRSIZE 160000
void insertsort(int* a, int len){
	for (int i = 1; i < len; i++){
		int j;
		int tmp = a[i];
		for (j = i - 1; j >= 0 && tmp<a[j]; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}
}
void hillsort(int* a, int len){
	int bu = len / 2;
	while (bu >= 1){
		for (int i = bu; i <len; i++){
			int j;
			int tmp = a[i];
			for (j = i - bu; j >= 0 && tmp < a[j]; j -= bu){
				a[j + bu] = a[j];
			}
			a[j + bu] = tmp;
		}
		bu /= 2;
	}
}
void merge(int*a, int*tmp, int left, int right){
	int mid = (left + right) / 2;
	int leftstart = left;
	int rightstart = mid + 1;
	int tmplen = right - left + 1;
	int k = left;
	while (leftstart <= mid&&rightstart <= right){
		if (a[leftstart] < a[rightstart]){
			tmp[k++] = a[leftstart++];
		}
		else{
			tmp[k++] = a[rightstart++];
		}
	}
	while (leftstart <= mid){
		tmp[k++] = a[leftstart++];
	}
	while (rightstart <= right){
		tmp[k++] = a[rightstart++];
	}
	for (int ii = 0; ii <tmplen; ii++){
		a[right] = tmp[right];
		right--;
	}
}
void mergesort(int* a, int* b, int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		mergesort(a, b, left, mid);
		mergesort(a, b, mid + 1, right);
		merge(a, b, left, right);
	}

}
int compInc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int zhebanfind(int*a, int key,int len){
	int left = 0;
	int right = len - 1;	
	while (left <= right){
		int mid = (left + right) / 2;
		if (key == a[mid]){
			return mid;
		}
		else{
			if (key < a[mid]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
	}
	return -1;
}
int zhijiefind(int*a, int key,int len){
	for (int i = 0; i < len; i++){
		if (a[i] == key)
			return i;
	}
	return -1;
}
void main(){	
	int a[ARRSIZE], b[ARRSIZE], c[ARRSIZE];	
	for (int i = 0; i < ARRSIZE; i++){
		b[i] = a[i] = rand();
	}
	clock_t t1, t2;
	double duration;
	for (int i = 0; i<50; i++){
		printf("%d\n", a[i]);
	}
	int* tmp;	
	tmp = c;
	mergesort(a, tmp, 0, ARRSIZE-1);
	t1 = clock();
	int d = zhijiefind(a,57,ARRSIZE);
	printf("57的位置%d：\n",d);
	t2 = clock();
	for (int i = 0; i<50; i++){
		printf("%d\n", a[i]);
	}
	duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("直接查找用时：%f\n", duration);
	qsort(b, ARRSIZE, sizeof(b[0]), compInc);
	t1 = clock();
	d = zhebanfind(b, 57, ARRSIZE);
	printf("57的位置%d：\n", d);
	t2 = clock();
	duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("二分查找用时：%f\n", duration);
	
	getchar();
}
