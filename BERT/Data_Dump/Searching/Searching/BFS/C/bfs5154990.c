#include<stdio.h>
#define MAX 100
#define INF 100000000

int head,tail;
int Q[MAX];

void push(int );
int pop(void);
int isEmpty(void);

int main(){
  int i,j;
  int n,u,k,v,d[MAX],G[MAX][MAX],ans;
  
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=0;
    } 
  }
  
  for(i=0;i<n;i++){
    Q[i]=-1;
    d[i]=INF;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      G[u][v]=1;
    }
  }
  head=tail=0;
  d[0]=0;
  push(0);
  
  while(!isEmpty()){
    v=pop();
    for(i=0;i<n;i++){
      if(G[v][i]==0)continue;
      if(d[v]+1<d[i]){
	d[i]=d[v]+1;
	push(i);
      }
    }
  }
  
  
  
  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,(d[i]==INF ? -1:d[i]));
  }
  
  return 0;
}


void push(int x){
  Q[tail]=x;
  tail++;
}
int pop(){
  int x;
  x=Q[head];
  Q[head]=-1;
  head++;
  return x;
}
int isEmpty(){
  return head==tail;
}

  

