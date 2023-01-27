// 시험 점수 출력
#include<stdio.h>
#include<stdlib.h> // rand()함수 포함 라이브러리
#include<time.h> // time()함수 포함 라이브러리
int main(void)
{
  int kor[10]; // 난수용 변수 선언
  int eng[10];
  int math[10];
  int i = 0;

  int max;
  int total[10];
  float avr[10];
  srand(time(NULL)); // 매초 다른 시드값 생성
  
  for(i=0;i<10;i++){
    kor[i] = rand()%101;
    eng[i] = rand()%101;
    math[i] = rand()%101;}

  for(i=0;i<10;i++){
    total[i] = kor[i]+eng[i]+math[i];
    avr[i] = total[i]/3;}

  max = 0;
  for(i=0;i<10;i++){
    if(total[max]<total[i]){
      max = i;    }
  }

for(i=0;i<10;i++){
      printf("[%d] %d\t %d\t %d\t %d\t %.2f\n", i, kor[i], eng[i], math[i], total[i], avr[i]);}
  
  printf("maxindex : %d",max);
  
  return 0;
}