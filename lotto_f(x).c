#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void RandomData(int num[6]) // 중복되지 않는 랜덤숫자 뽑기
{
  srand(time(NULL));
  int i;
  int j;
  
  for(i=0;i<6;i++)
    {
      num[i] = rand()%46 + 1;
      for(j=0;j<i;j++)
        {
          if(num[i] == num[j])
          {
            i--;
            break;
          }
        }
      
    }
}

void PrintData(int num[6]) //  출력 함수
{
  int i;
  for(i=0;i<6;i++)
    {
      printf("%d\n",num[i]);
    }
}

int main(void) {
  int num[6];
  RandomData(num);
  PrintData(num);
  
  return 0;
  }