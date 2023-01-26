#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b;
  int c, d, e;
  float f;
  printf("input 2 data:");
  scanf("%d %d", &a, &b);
  c = a + b;
  d = a - b;
  e = a * b;
  f = (float)a / b;

  printf("%d + %d = %d\n", a, b, c);
  printf("%d - %d = %d\n", a, b, d);
  printf("%d * %d = %d\n", a, b, e);
  printf("%d / %d = %.2f\n", a, b, f);
  if (a >= b) {
    printf("max = %d", a);
  } else {
    printf("max = %d", b);
  }
  return 0;
}