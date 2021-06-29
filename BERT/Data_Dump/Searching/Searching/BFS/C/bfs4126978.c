#include<stdio.h>
#include <limits.h>
   
#define White 0
#define Gray  1
#define Black 2
#define MAX 101
   
   
int n=0, G[MAX][MAX], d[MAX], clr[MAX], que[MAX], head=0, tail=0;
   
void Enqueue(int);
int Dequeue();
void BFS(int);
  
int main()
{
  int i,j,s,u,r;
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
    scanf("%d%d", &u,&r);
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
  int y;
  y = que[head];
  head+=1;
  return y;
} 
  
void BFS(int s)
{
  int x,y;
  for(x=1;x<=n;x++){
    clr[x] = White;
    d[x] = -1;
  }
  clr[s] = Gray;
  d[s] = 0;
  Enqueue(s);
  while(head != tail){
    x = Dequeue();
    for(y=1;y<=n;y++){
      if(clr[y] == White && G[x][y] == 1){
        clr[y] = Gray;
        d[y] = d[x] + 1;
        Enqueue(y);
      }
    }
    clr[x] = Black;
  }
}

