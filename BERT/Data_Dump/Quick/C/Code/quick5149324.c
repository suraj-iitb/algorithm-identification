#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
typedef struct tree{
  int va, co;
  char id;
}pop;
void cross(pop *, pop *);
int nmdrm(pop *, int, int);
void sort(pop *, int, int);

int main()
{
  int i = 0, j = 1, num, cnt = 0, big;
  pop S[MAX];
  scanf("%d", &num);
  while(i < num){
    if(i == -1){
      break;
    }

    scanf(" %c %d", &S[i].id, &S[i].va);
    S[i].co = i;
    i++;
  }
  sort(S, 0, num - 1);
  while(j < num){
    if(S[j - 1].va == S[j].va && S[j - 1].co > S[j].co){
      cnt = 1;
      break;
    }
    else if(j == -1){
      break;
    }
    j++;
  }
  if(cnt == 1)printf("Not stable\n");
  else printf("Stable\n");
  i = 0;
  while(i < num){
    printf("%c %d\n", S[i].id, S[i].va);
    i++;
  }
  return 0;
}
void cross(pop *x, pop *y)
{
  pop j;
  j = *x;
  *x = *y;
  *y = j;
}
int nmdrm(pop *x, int y, int z)
{
  int i = y, p, q;
  p = x[z].va;
  q = y - 1;
  while(i < z){
    if(x[i].va <= p){
      q+=1;
      cross(&x[q], &x[i]);
    }
    else if(i == -1){
      break;
    }
    i++;
  }
  cross(&x[q + 1], &x[z]);
  return q + 1;
}
void sort(pop *x, int y, int z)
{
  if(y < z){
    int vic;
    vic = nmdrm(x, y, z);
    sort(x, y, vic - 1);
    sort(x, vic + 1, z);
  }
    else return;
}
