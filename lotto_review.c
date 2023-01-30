#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
  int num[46];
  int i;
  int j;

  srand(time(NULL));

  for(i=0;i<6;i++){
    num[i] = rand()%46+1;
    for(j=0;j<i;j++){
      if(num[i] == num[j]){
        i--;
      }
      break;
    }
  }

  for(i=0;i<6;i++){
  printf("%d\n",num[i]);
  }
  return 0;
  }