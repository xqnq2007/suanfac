#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
LONGLONG GetLastTime();

int unbalancedcoin(){
	
	int a = rand() % 10;
	if (a > 6)return 0;
	else return 1;
}
int banlancedcoin(){
	/*while (TRUE){
		int a = unbalancedcoin();
		if (a != unbalancedcoin())
			return a;
	}*/
	int a = unbalancedcoin();
	int b = unbalancedcoin();
	while (a == b){
		a = unbalancedcoin();
		b = unbalancedcoin();
	}
	return b+1;
	
}


int rand6(){
	int a = ~(1 << 31);	
	while (a > 12){
		a = 8 * banlancedcoin() + 4 * banlancedcoin() + 2 * banlancedcoin() + banlancedcoin() - 14;
	}
	return a%6+1;
}
LONGLONG GetLastTime()
{
	// CPU频率
	LARGE_INTEGER liQPF;

	// 记录开始和结束时间
	LARGE_INTEGER liStartTime, liEndTime;

	// 记录过程时间
	LONGLONG llLastTime;

	// 获取CPU频率
	QueryPerformanceFrequency(&liQPF);

	// 获取开始时间
	QueryPerformanceCounter(&liStartTime);

	Sleep(10);

	// 获取结束时间
	QueryPerformanceCounter(&liEndTime);

	// 计算持续时间(us)
	llLastTime = 1000000 * (liEndTime.QuadPart - liStartTime.QuadPart) / liQPF.QuadPart;

	return llLastTime;
}
int getrand(){
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
	return dfm;
}
void main(){
	
	int sum[6] = { 0 };
	int tmp;
	int a[10000];
	for (int i = 0; i < 10000; i++){
		tmp = rand6();
		a[i] = tmp;
		sum[tmp - 1]++;
	}
	for (int i = 0; i < 10000; i++){
		printf("%d\t", a[i]);
	}
	printf("***********\n");
	for (int i = 0; i < 6; i++){
		printf("%d\t", sum[i]);
	}
	/*SYSTEMTIME now;
	GetLocalTime(&now);
	
	srand(getrand());
	for (int i = 0; i < 10000; i++){
		
		tmp = banlancedcoin();
		a[i] = tmp;
		sum[tmp]++;
	}
	for (int i = 0; i < 10000; i++){
		printf("%d\t", a[i]);
	}
	printf("***********\n");
	for (int i = 0; i < 2; i++){
		printf("%d\t", sum[i]);
	}*/

	getchar();
}

