#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>
#define N 101

enum COLOR{WHITE,BLACK,GRAY}color[N];
int G[N][N],d[N],f[N],n,A[N][N],edg[N]; 
int  Q[N];
int head, tail;
 
void enqueue(int x){
    Q[tail] = x;
    if (tail + 1 == N){
        tail = 0;
    }else{
        tail++;
    }
}
 
int dequeue(){
    int x = Q[head];
    if (head + 1 == N){
        head = 0;
    }else{
        head++;
    }
    return x;
}

void BFS(int s){
  int u,i,j;
  for(i=0;i<N;i++)d[i]=-1;
  for(u=1;u<=n-1;u++){
    color[u]  =WHITE;
    d[u]      =-1;
    color[s]  =GRAY;
  }
  d[s]=0;
  head=1;
  tail=1;
  enqueue(s);

  while(head!=tail){
    u=dequeue();
    for(i=1;i<=edg[u];i++){
      if(color[A[u][i]] == WHITE){
	color[A[u][i]]=GRAY;
	d[A[u][i]]=d[u]+1;
	enqueue(A[u][i]);
      }
    }
    color[u]=BLACK;
  }
}

int main(){
  int i ,j,k,ver,fff;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&ver,&edg[i]);
    for(j=1;j<=edg[i];j++){
      scanf("%d",&fff);
      A[i][j]=fff;
    } 
  }
    BFS(1);
    for(j=1;j<=n;j++)printf("%d %d\n",j,d[j]);
  return 0;
}
