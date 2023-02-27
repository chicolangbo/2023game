#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 전역변수 : 단어장
char dic[5][20] = {"apple", "carrot", "help", "cake", "life"};

// 전역변수 : g_step
int g_step = 0;

// 초기화 함수 : 정답 고르기, 힌트 생성
void Init(char*answer, char*p)
{
  int index;
  int len;
  int i;
  srand(time(NULL));
  index = rand()%5;
  strcpy(answer, dic[index]);
  len = strlen(answer);
  for(i=0;i<len;i++)
    {
      p[i] = '*';
    }
  p[i] = '\0';
}

// 유저 함수 : 힌트 출력, 유저 답 받기, 정답 판결
int User(char p[20], char answer[20])
{
  char temp[5];
  int len;
  int i;
  int check = 0;
  char key;
  printf("hint:%s\n",p);
  printf("input char:");
  scanf("%s",temp);
  key = temp[0];
  len = strlen(p);

  for(i=0;i<len;i++)
    {
      if(answer[i]==key&&p[i]=='*')
      {
        p[i] = key;
        check = 1;
      }
    }
  return check;
}

// 틀렸을 때 행맨스텝 업뎃 함수
void Next(void)
{
  g_step++;
  printf("hangman step:%d\n",g_step);
}

// 틀렸을 때 행맨 출력 함수
void Hangman(void)
{
  switch(g_step)
    {
      case 0 :
      break;
      case 1 :
      printf("case 1\n");
      break;
      case 2 :
      printf("case 2\n");
      break;
      case 3 :
      printf("case 3\n");
      break;
      case 4 :
      printf("case 4\n");
      break;
      default :
      break;
    }
}

// 게임 종료 함수
int GameOver(char*p, char*answer)
{
  if(4==g_step)
  {
    return 1;
  }
  if(0==strcmp(p,answer))
  {
    return 1;
  }
  return 0;
}

// 메인 함수
int main(void) {
  char answer[20];
  char p[20];
  Init(answer, p);
  while(1)
    {
      if(0==User(p,answer))
      {
        Next();
        Hangman();
      }
      if(1==GameOver(p,answer))
      {
        break;
      }
    }
  return 0;
}