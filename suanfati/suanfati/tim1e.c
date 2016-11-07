#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

long QuerySystemTime() 
{ 
        long CurTime, Freq; 
        CurTime = QueryPerformanceCounter(&Freq); 
        return (long)((CurTime.QuadPart * 1000)/Freq.QuadPart); 
} 
void main(){

}