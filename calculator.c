// 사칙연산 프로그램 만들기
#include<stdio.h>
int main(void)
{
  int a, b;
  printf("input 2 data:");
  scanf("%d %d",&a, &b);
  printf("%d + %d = %d\n", a, b, a+b);
  printf("%d - %d = %d\n", a, b, a-b);
  printf("%d * %d = %d\n", a, b, a*b);
  printf("%d / %d = %d\n", a, b, a/b);
  if(a>=b){
   printf("max = %d", a);
  }
  else{
    printf("max = %d", b);
  }
  return 0;
}