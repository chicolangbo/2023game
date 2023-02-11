#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define END -1
#define GA 0
#define BA 1
#define BO 2

#define WIN 0
#define LOSE 1

// 컴퓨터와 플레이어로부터 가위 바위 보 중 하나를 받는 함수
int ComPlay(void)
{
  return rand()&3;
}
int ManPlay(void)
{
  int you;
  printf("-1(종료), 0(가위), 1(바위), 2(보)?");
  scanf("%d", &you);
  return you;
}

// 승패를 결정하는 함수
int MyCheck(int com,int you)
{
  if(GA==you && BO==com)
  {
    return WIN;
  }
  if(BA==you && BA==com)
  {
    return WIN;
  }
  if(BO==you && BA==com)
  {
    return WIN;
  }
  return LOSE;
}

// 초기화 함수
void Mylni(int *count, int *wcount) {
  *count = 0;
  *wcount = 0;
  srand(time(NULL));
}

// 승률 함수
void ShowWRate(int count, int wcount)
{
  float wrate;
  wrate = (float)wcount/count;
  printf("Win Rate:%.2f\n", wrate);
}


int main(int argc, char *argv[]) {
  
  int you;
  int com;
  int re;
  int count;
  int wcount;

  Mylni(&count, &wcount);
  
  while(1)
    {
      count++;
      com = ComPlay();
      you = ManPlay();

      if(END==you)
      {
        break;
      }
      re = MyCheck(com,you);
  if(WIN==re)
  {
    wcount++;
    printf("You Win! c:%d you:%d\n", com, you);
  }
  else
  {
    printf("You Lose! c:%d you:%d\n", com, you);
  }
    }

  
  ShowWRate(count,wcount);

  return 0;
}