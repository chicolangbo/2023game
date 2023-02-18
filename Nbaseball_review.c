#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 초기화 함수
void init(void) {
  srand(time(NULL));
  printf("Baseball game ver 0.1 by chico\n");
}

// 랜덤으로 뽑은 값이 중복될 시 1 리턴하는 함수
int IsFind(int com[3], int index) {
  int re;
  int i;
  re = 0;
  for (i = 0; i < index; i++) {
    if (com[i] == com[index]) {
      return 1;
    }
  }
  return re;
}

// 컴퓨터 3개 뽑기
void ComPlay(int com[3]) {
  int i;
  for (i = 0; i < 3; i++) {
    com[i] = rand() % 10;
    if (1 == IsFind(com, i)) {
      i--;
      break;
    }
  }
}

// 유저 3개 뽑기
void PPlay(int p[3]) {
  int i;
  printf("0~9까지의 중복 없이 숫자 3개를 넣으세요?");
  for (i = 0; i < 3; i++) {
    scanf("%d", &p[i]);
  }
}

// 스트라이크,볼값 구하는 함수
void CheckScore(int com[3], int p[3], int *s, int *b) {
  int i;
  int j;
  int ts;
  int tb;
  ts = 0;
  tb = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (p[i] == com[j]) {
        if (i == j) {
          ts++;
        } else {
          tb++;
        }
        break;
      }
    }
  }
  *s = ts;
  *b = tb;
}

// 게임 닫기 함수
int CheckNextGame(void) {
  int go;
  int re;
  re = 0;
  printf("-1:end else continue game?");
  scanf("%d", &go);
  if (-1 == go) {
    re = -1;
  }
  return re;
}

// 메인 함수
int main(void) {
  int com[3];
  int p[3];
  int s;
  int b;
  int i;

  init();

  while (1) {
    ComPlay(com);
    for (i = 0; i < 10; i++) {
      b = 0;
      s = 0;
      PPlay(p);
      CheckScore(com, p, &s, &b);
      if (s == 3) {
        break;
      } else {
        printf("s:%d b:%d\n", s, b);
      }
    }
    if (3 == s) {
      printf("3 strike! you win\n");
    } else {
      printf("you loose...\n");
      printf("com => %d %d %d\n", com[0], com[1], com[2]);
    }
    if (-1 == CheckNextGame()) {
      printf("Thank you!\n");
      break;
    }
  }

  return 0;
}