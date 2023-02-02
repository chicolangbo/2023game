#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void RandomData(int kor[10], int eng[10], int math[10]) // 국영수 랜덤값 부여
{
  int i;
  srand(time(NULL));
  for(i=0;i<10;i++){
    kor[i] = rand()%101;
    eng[i] = rand()%101;
    math[i] = rand()%101;
  }
}

void CalData(int kor[10], int eng[10], int math[10], float avr[10], int sum[10], int* maxindex) // 평균,합계,최대값 번호 구하기
{
  int i;
  int j;
  *maxindex = 0;
  
  for(i=0;i<10;i++){
    avr[i] = (float)(kor[i]+eng[i]+math[i])/3;
    sum[i] = avr[i]*3;
  }
  for(i=0;i<10;i++){
    if(sum[*maxindex]<sum[i]){
      *maxindex = i;
    }
      
      }
}

void PrintfData(int kor[10], int eng[10], int math[10], float avr[10], int sum[10], int max) // 출력 함수
{
  int i;
  for(i=0;i<10;i++){
    printf("[%d] %d\t%d\t%d\t%d\t%.1f\n",i,kor[i],eng[i],math[i],sum[i],avr[i]);
  }
  printf("max = %d",max);
}

int main(void) {
  int kor[10];
  int eng[10];
  int math[10];
  float avr[10];
  int sum[10];
  int maxindex;

  RandomData(kor,eng,math);  CalData(kor,eng,math,avr,sum,&maxindex);
PrintfData(kor,eng,math,avr,sum,maxindex);
  
  return 0;
  }