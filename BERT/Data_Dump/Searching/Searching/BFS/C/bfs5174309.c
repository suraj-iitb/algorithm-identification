#include<stdio.h>
#include<stdlib.h>
#define MAX 130

void bork(int x);
void kit(int x);
int gyokuro(void);

int S[MAX][MAX], c[MAX], P[MAX], Q[MAX], num, head, tail;

int main()
{
  int i = 1, j = 0, k = 1, num1, num2, num3;
  scanf("%d", &num);
  while(i <= num){
    scanf("%d%d", &num1, &num2);
    for(j = 0; j < num2; j++){
      scanf("%d", &num3);
      S[i][num3] = 1;
    }
    i++;
  }
  bork(1);

  while(k <= num){
    printf("%d %d\n", k, P[k]);
    k++;
  }
  return 0;
}void bork(int x)
{
  int i = 1, s, t;

  while(i <= num){
    c[i] = -3;
    P[i] = -1;
    i++;
  }
  c[x] = -2;
  P[x] = 0;
  kit(x);
  while(head != tail){
    s = gyokuro();
    for(t = 1; t <= num; t++){
      if(S[s][t] == 1 && c[t] == -3){
        c[t] = -2;
        P[t] = P[s] + 1;
        kit(t);

      }
    }
    c[s] = -1;
  }
}

void kit(int x)
{
  Q[tail] = x;
  tail+=1;
  if(tail == MAX) tail = 0;
}

int gyokuro(void)
{
  int p;
  p = Q[head];
  head+=1;
  if(head == MAX) head = 0;
  return p;
}

