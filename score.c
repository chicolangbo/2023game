// 시험 점수 출력
#include<stdio.h>
#include<stdlib.h> // rand()함수 포함 라이브러리
#include<time.h> // time()함수 포함 라이브러리
int main(void)
{
  int k; // 난수용 변수 선언
  int e;
  int m;
  srand(time(NULL)); // 매초 다른 시드값 생성
  for(int i=0; i <10; i++){ // 100번 반복
    k = rand()%101;
    e = rand()%101;
    m = rand()%101;
    int sum = k + e + m;
  float average = (float)(k + e + m)/3;
    printf("%d] %d\t%d\t%d\t%d\t%.2f\n",
            i+1, k, e, m, sum, average);
  }
  return 0;
}