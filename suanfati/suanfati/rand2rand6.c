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
	// CPUƵ��
	LARGE_INTEGER liQPF;

	// ��¼��ʼ�ͽ���ʱ��
	LARGE_INTEGER liStartTime, liEndTime;

	// ��¼����ʱ��
	LONGLONG llLastTime;

	// ��ȡCPUƵ��
	QueryPerformanceFrequency(&liQPF);

	// ��ȡ��ʼʱ��
	QueryPerformanceCounter(&liStartTime);

	Sleep(10);

	// ��ȡ����ʱ��
	QueryPerformanceCounter(&liEndTime);

	// �������ʱ��(us)
	llLastTime = 1000000 * (liEndTime.QuadPart - liStartTime.QuadPart) / liQPF.QuadPart;

	return llLastTime;
}
int getrand(){
	LARGE_INTEGER litmp;
	LONGLONG qt1, qt2;
	double dft, dff, dfm;
	QueryPerformanceFrequency(&litmp);//���ʱ��Ƶ��
	//printf("%d\n", litmp);
	dff = (double)litmp.QuadPart;
	QueryPerformanceCounter(&litmp);//��ó�ʼֵ
	qt1 = litmp.QuadPart; Sleep(1);
	QueryPerformanceCounter(&litmp);//�����ֵֹ
	qt2 = litmp.QuadPart;
	dfm = (double)(qt2 - qt1);
	dft = dfm / dff;//��ö�Ӧ��ʱ��ֵ
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

