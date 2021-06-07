#include<stdio.h>

void input(int);
void shori(int);

typedef struct{
  int num;
  int have;
  int flag;
  int hakken;
  int kanryou;
  int next[100];
} Data;

int cnt;
Data data[101];

int main(){
  
  int i, n;

  scanf("%d",&n);

  for(i = 1; i <= n; i++)input(i);

  cnt = 1;
  for(i = 1; i <= n; i++)if(data[i].flag == 0)shori(i);
  
  for(i = 1; i <= n; i++)printf("%d %d %d\n",i ,data[i].hakken, data[i].kanryou);
  
  return 0;  
}

void shori(int n)
{
  int i;
  
  data[n].hakken = cnt;
  data[n].flag = 1;
  cnt++;
  
  for(i = 0; i < data[n].have; i++)if(data[n].next[i] != n && data[data[n].next[i]].flag == 0)shori(data[n].next[i]);
  
  data[n].kanryou = cnt;
  cnt++;
}

void input(int n)
{
  int i;

  cnt = 0;
  
  scanf("%d%d",&data[n].num,&data[n].have);

  for(i = 0; i < data[n].have; i++)
    {
      scanf("%d",&data[n].next[cnt]);
      cnt++;
    }
  data[n].flag = 0;
  data[n].hakken = data[n].kanryou = -1;
}

