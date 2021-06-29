#include<stdio.h>
#include<stdlib.h>
#define MAX 130

int num, S[MAX][MAX], c[MAX], ic[MAX], ba[MAX], st;

void pop(void);
void push(int x);
int main(){
  int i = 1, j = 1, p, q, a;
  scanf("%d", &num);
  while(i <= num){
    scanf("%d%d", &p, &q);
    for(j = 0; j < q; j++){
      scanf("%d", &a);
      S[i][a] = 1;
    }
    i++;
  }
  pop();
  int l = 1;
  while(l <= num){
    printf("%d %d %d\n", l, ic[l], ba[l]);
    l++;
  }
  return 0;
}

void pop(void)
{
  int i = 1, j = 1;
  while(i <= num){
    c[i] = -3;
    i++;
  }
  while(j <= num){
    if(c[j] == -3) push(j);
    j++;
  }
}
void push(int x)
{
  int i = 1;
  c[x] = -2;
  ic[x] = ++st;
  while(i <= num){
    if(S[x][i] == 1 && c[i] == -3){
      push(i);
    }
    i++;
  } c[x] = -1;
  ba[x] = ++st;
}


