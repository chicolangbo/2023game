#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIC_SIZE 5
#define WORD_LEN 20

// 전역변수 : 정답 단어북
char g_dic[DIC_SIZE][WORD_LEN] = {
"father", "mother", "wonderful", "security", "hello"
};

// 전역변수 : 스텝 개수
int g_step = 0;

// 함수 : 정답, 힌트 초기화
void Init(char*com,char*p)
{
  int index;
  int i;
  int len;

  srand(time(NULL));
  index = rand()%DIC_SIZE;
  strcpy(com,g_dic[index]);
  len = strlen(com);
  for(i=0;i<len;i++)
    {
      p[i] = '*';
    }
  p[i] = '\0';
}

// 함수 : 유저 스캔, 힌트 수정
int InputChar(char com[WORD_LEN], char p[WORD_LEN])
{
  char msg[5];
  char key;

  int len;
  int check;
  int i;

  printf("Hint:%s\n",p);
  printf("input char:");
  scanf("%s",msg);
  key = msg[0];

  len = strlen(p);
  check = 0;
  for(i=0;i<len;i++)
    {
      if(com[i]==key&&p[i]=='*')
      {
        p[i] = key;
        check = 1;
      }
    }
  return check;
}

// 함수 : 교수형 샘플
void GoNextStep(void)
{
  g_step++;
  printf("hang man step:%d\n",g_step);
}
void ShowHangman(void)
{
  switch(g_step)
    {
      case 0:
        printf("hangman 0단계\n");
        break;
      case 1:
        printf("hangman 1단계\n");
        break;
      case 2:
        printf("hangman 2단계\n");
        break;
      case 3:
        printf("hangman 3단계\n");
        break;
      case 4:
        printf("hangman 마지막\n");
        break;
      default:
        break;
    }
}

// 함수 : 게임 종료
int CheckGameOver(char*com,char*p)
{
  if(4==g_step)
  {
    return 1;
  }
  if(0==strcmp(com,p))
  {
    return 1;
  }
  return 0;
}

// 메인 함수
int main(void) {
  char com[WORD_LEN];
  char p[WORD_LEN];

  Init(com,p);
  while(1)
    {
      if(0==InputChar(com,p))
      {
        GoNextStep();
        ShowHangman();
      }
      if(1==CheckGameOver(com,p))
      {
        break;
      }
    }
  
  return 0;
}