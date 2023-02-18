#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 별명 만들기
#define END -1
#define GA 0
#define BA 1
#define BO 2
#define WIN 0
#define LOOSE 1

// 데이터 초기화 함수
void init(int*count,int*wcount)
{
 *count = 0;
 *wcount = 0;
  srand(time(NULL));
}

// 컴퓨터 답 함수
int ComPlay(void)
{
  int com;
  com = rand()%3;
  return com;
}

// 내 답 함수
int UPlay(void)
{
  int you;
  printf("-1(종료), 0(가위), 1(바위), 2(보)?");
  scanf("%d", &you);
  return you;
}

// 승부 결정 함수
int Result(int com, int you, int*wcount)
{
  if(you==GA && com==BO || you==BA && com==GA || you==BO && com==BA)
  {
    return WIN;}
  else{return LOOSE;}
}

// 메인 함수

int main(void) {
 int count;
  int wcount;
  int com;
  int you;
  int wl;
  float winrate;
  
  init(&count,&wcount);
  
  while(1)
    {
    count++;
  com = ComPlay();
  you = UPlay();
  wl = Result(com,you,&wcount);
    if(END == you)
    {
      break;}

    if(WIN==wl)
    {
      wcount++;
      printf("you win! com:%d you:%d\n", com,you);
    }
      else
    {
      printf("you loose! com:%d you:%d\n", com,you);
    }
    }

  winrate = (float)wcount/count;
  printf("winrate : %.2f",winrate);

  return 0;
}