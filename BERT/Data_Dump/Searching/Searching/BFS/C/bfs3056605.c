#include<stdio.h>
#define N 100

int isEmpty(void);
void enqueue(int);
int dequeue(void);
void BFS(int);

int n;
int A[N][N],c[N],d[N];
int Q[N];
int head=0,tail=0;

int main(){

  int i,j,l;
  int u,k;

  scanf("%d",&n);
  int B[n][n];
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(l=0;l<k;l++){
      scanf("%d",&B[i][l]);
    }
    for(j=0;j<n;j++){
      A[i][j]=0;
      for(l=0;l<k;l++){
	if(B[i][l]==j+1){
	  A[i][j]=1;
	}
      }
    }
  }
  BFS(0);
  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}
int isEmpty(){
  if(head==tail) return 1;
  return 0;
}

void enqueue(int n){
  
  Q[tail]=n;
  if(tail+1==N){
    tail=0;
  }
  else{
    tail++;
  }
}

int dequeue(){

  int n;

  n=Q[head];
  if(head+1==N){
    head=0;
  }
  else{
    head++;
  }
  return n;
}

void BFS(int s){
  int i;
  int u,v;
  for(i=0;i<n;i++){
    c[i]=0;
    d[i]=-1;
  }
  c[s]=1;
  d[s]=0;
  enqueue(s);

  while(isEmpty()!=1){
    u=dequeue();
    for(v=0;v<n;v++){
      if(A[u][v]==1){
	if(c[v]==0){
	  c[v]=1;
	  d[v]=d[u]+1;
	  enqueue(v);
	}
      }
    }
    c[u]=2;
  }
}

