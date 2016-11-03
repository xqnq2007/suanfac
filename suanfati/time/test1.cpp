#include<iostream>
#include<Windows.h>
using namespace std;
void main(){
	for (int i = 0; i < 1000; i++){
		LARGE_INTEGER litmp;
		LONGLONG qt1, qt2;
		double dft, dff, dfm;
		QueryPerformanceFrequency(&litmp);//获得时钟频率
		//printf("%d\n", litmp);
		dff = (double)litmp.QuadPart;
		QueryPerformanceCounter(&litmp);//获得初始值
		qt1 = litmp.QuadPart; Sleep(1);
		QueryPerformanceCounter(&litmp);//获得终止值
		qt2 = litmp.QuadPart;
		dfm = (double)(qt2 - qt1);
		dft = dfm / dff;//获得对应的时间值
		//printf("%d\n", qt1);
		//printf("%d\n", qt2);
		int tmp = (int)dfm % 10;
		printf("%d\n", tmp);
	}	
	getchar();
}