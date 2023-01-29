// 시험 점수 출력
#include<stdio.h>
#include<stdlib.h> // rand()함수 포함 라이브러리
#include<time.h> // time()함수 포함 라이브러리
int main(void)
{
  int kor[10];
  int eng[10];
  int mat[10];
  int i;
  srand(time(NULL));

  for(i=0;i<10;i++){
    kor[i] = rand()%101;
    eng[i] = rand()%101;
    mat[i] = rand()%101;
  }

  int sum[10];
  float avr[10];

  for(i=0;i<10;i++){
    sum[i] = kor[i] + eng[i] + mat[i];
    avr[i] = sum[i]/3;
  }

  int max = 0;

  for(i=0;i<10;i++){
    if(max<sum[i]){
      max = sum[i];
    }
  }

  for(i=0;i<10;i++){
    printf("a[%d] %d\t%d\t%d\t%d\t%f\n", i, kor[i], eng[i], mat[i], sum[i], avr[i]);
  }
  printf("max = %d", max);
  
  return 0;
  }