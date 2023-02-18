#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 초기화 함수
void init(int*strike, int*ball)
{
  *strike = 0;
  *ball = 0;
  srand(time(NULL));
}

// 스트라이크 값 함수
int Strike(int com[3],int you[3])
{
  int i;
  int strike = 0;
  for(i=0;i<3;i++)
    {
     if(com[i]==you[i])
          {
            strike++;
          }
        }
  return strike;
}

// 볼 값 함수
int Ball(int com[3],int you[3])
{
  int i;
  int j;
  int ball = 0;
  for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        {
          if(you[i]==com[j])
          {
            ball++;
          }
        }
    }
  return ball;
}

// 메인 함수
int main(void) {
  int com[3];
  int you[3];
  int strike;
  int ball;
  int i;
  int j;

  // 컴퓨터 3개 수
  for(i=0;i<3;i++)
    {
  com[i] = rand()%10;
      for(j=0;j<i;j++)
        {
          if(com[i]==com[j])
          {
            i--;
          }
        }
      }

  //10번 트라이
  for(i=0;i<10;i++)
    {
  init(&strike,&ball);

      // 유저 3개 수
     printf("0~9까지 중복없이 숫자 3개를 넣으세요!");
      scanf("%d %d %d",&you[0],&you[1],&you[2]);

      // 스트라이크 값
      strike = Strike(com,you);

      // 볼 값
      ball = Ball(com,you);
      
      // 스트라이크, 볼 출력
      printf("s:%d h:%d\n", strike, ball);
      
      // 탈출
      if(strike==3)
      {
        break;
      }
      }

  // 마지막 결과 출력
  if(strike==3)
  {
    printf("you win!\ncom=> %d %d %d", com[0], com[1], com[2]);
  }
  else
  {
    printf("you loose!\ncom=> %d %d %d", com[0], com[1], com[2]);
  }
  
  return 0;
}