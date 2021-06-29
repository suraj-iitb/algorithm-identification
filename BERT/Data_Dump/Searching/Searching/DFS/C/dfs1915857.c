#include<stdio.h>
#define N 1000
#define WHITE 0
#define BLACK 2
#define GRAY 1
typedef struct Node{
  int num;
  int A[N];
}node;

void push(int);
int pop();
void DFS();
void Visit(int);

int n,time,top=0,D[N],F[N],S[N],color[N];
node L[N];

int main(){

  int i,k,j,a;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&k);
    L[a].num=0;
    for(j=1;j<=k;j++){
      scanf("%d",&L[a].A[j]);
    }
  }
  
  DFS();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,D[i+1],F[i+1]);
  }


  return 0;
}


void DFS(){

  int i;

  for(i=1;i<=n;i++)color[i]=WHITE;

  time=0;

  for(i=1;i<=n;i++){
    if(color[i]==WHITE) Visit(i);
  }

}

void Visit(int r){

  int u,v,num=0; 

  push(r);
  color[r]=GRAY;
  D[r]=++time;

  while(top!=0){
    u=S[top];
    v=L[u].A[++L[u].num];

    if(v > 0){
      if(color[v]==WHITE){
	push(v);
	color[v]=GRAY;
	D[v]=++time;
      }
    }
    else{
      pop();
      color[u]=BLACK;
      F[u]=++time;
    }
  }

}

void push(int u){

  top++;
  S[top]=u;

}

int pop(){

  top--;
  return S[top+1];

}
