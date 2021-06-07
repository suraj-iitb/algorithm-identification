#include<stdio.h>

void input(int);
void shokika(int);
void shori(int, int);

typedef struct{
  int num;
  int min;
  int next[100];
} Data;

int cnt, min;
Data data[101];

int main(){

  int i, n;

  scanf("%d",&n);

  for(i = 1; i <= n; i++)shokika(i);
  for(i = 1; i <= n; i++)input(i);
  shori(1, 0);
  for(i = 1; i <= n; i++)
  {
    if(data[i].min != 9999)printf("%d %d\n",i,data[i].min);
    else printf("%d -1\n",i);
  }
  return 0;
}

void shori(int now, int keiro)
{
  int i;

  if(data[now].min > keiro)
  {
    data[now].min = keiro;
    for(i = 0; data[now].next[i] != -1; i++)
    {
      //printf("data[%d].min = %d\n%d → %d\n",now,keiro,now,data[now].next[i]);
      shori(data[now].next[i], keiro + 1);
      //printf("%d ← %d\n",now,data[now].next[i]);
    }
  }
}

void input(int n)
{
  int i, x;

  cnt = 0;

  scanf("%d%d",&data[n].num,&x);

  for(i = 0; i < x; i++)scanf("%d",&data[n].next[i]);
}

void shokika(int n)
{
  int i;
  for(i = 0; i < 100; i++)data[n].next[i] = -1;
  data[n].min = 9999;
}

