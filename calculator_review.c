// 사칙연산 프로그램 만들기
#include<stdio.h>
int main(void)
{
  float a, b;
  float A, B, C, D;
  printf("실수 두 개를 입력하시오.");
  scanf("%f %f\n", &a, &b);
  A = a + b;
  B = a - b;
  C = a * b;
  D = a / b;
  printf("%.1f + %.1f = %.1f\n", a, b, A);
  printf("%.1f - %.1f = %.1f\n", a, b, B);
  printf("%.1f * %.1f = %.1f\n", a, b, C);
  printf("%.1f / %.1f = %.1f\n", a, b, D);
  return 0;
}