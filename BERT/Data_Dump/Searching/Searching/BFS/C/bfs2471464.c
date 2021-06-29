#include<stdio.h>
#include <limits.h>
   
#define N 101
  
#define White 0
#define Gray  1
#define Black 2
   
   
int n=0;
int G[N][N];
int d[N];
int color[N];
int que[N];
int head=0;
int tail=0;
   
void Enqueue(int);
int Dequeue();
void BFS(int);
  
int main()
{
  int i,j,s,v,r;
  int p=1;
  
  scanf("%d",&n);
  
  for(i=1;i<=n;i++)
    {
    for(j=1; j<=n;j++)
      {
    G[i][j] = 0;
      }
    }
   
  for(i=1;i<=n;i++){
    scanf("%d%d", &v,&r);
    for(j=1;j<=r;j++){
      scanf("%d",&s);
      G[i][s] = 1;
    }
  }
  
  BFS(p);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i, d[i]);
  }
  return 0;
}
 
void Enqueue(int s)
{
  que[tail]=s;
  tail+=1;
}
  
int Dequeue()
{
  int sugiyama;
  sugiyama = que[head];
  head+=1;
  return sugiyama;
} 
  
void BFS(int s)
{
  int sugi,yama;
  for(sugi=1;sugi<=n;sugi++){
    color[sugi] = White;
    d[sugi] = -1;
  }
  color[s] = Gray;
  d[s] = 0;
  Enqueue(s);
  while(head != tail){
    sugi = Dequeue();
    for(yama=1;yama<=n;yama++){
      if(color[yama] == White && G[sugi][yama] == 1){
        color[yama] = Gray;
        d[yama] = d[sugi] + 1;
        Enqueue(yama);
      }
    }
    color[sugi] = Black;
  }
}
