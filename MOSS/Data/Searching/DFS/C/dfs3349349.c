#include <stdio.h>

#define N 100

#define W 1
#define G 2
#define B 3
#define MY_NULL -1

int a[N+1][N+1]={0};
int d[N+1]={0};
int f[N+1]={0};
int color[N+1]={0};
int stack[N+1]={0};
int top=0;
int time=0,n=0;

void dfs(void);
void visit(int);
int next(int);
void push(int);
int pop(void);

int main(){
  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d %d",&u,&k);
    for(j=0; j<k; j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  dfs();
  
  for(i=1; i<=n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}

void dfs(void){
  int i;
  for(i=1; i<=n; i++){
    color[i]=W;
  }
  time=0;
  for(i=1; i<=n; i++){
    //printf("DEBUG1\n");
    if(color[i]==W){
      visit(i);
    }
  }
}

void visit(int r){
  int u,v,i;
  int j;
  push(r);
  color[r]=G;
  d[r]=++time;
  while(top>0){
    //printf("DEBUG2\n");
    u=stack[top-1];
    v=next(u);
    //printf("u=%d,v=%d\n",u,v);
    //printf("top=%d, ",top);
    //for(j=0; j<=top; j++) printf("%d ",stack[j]);
    //printf("\n");
    if(v!=MY_NULL){
      //printf("DEBUG3\n");
      if(color[v]==W){
	//printf("DEBUG4\n");
	push(v);
	color[v]=G;
	d[v]=++time;
      }
    }else{
      pop();
      color[u]=B;
      f[u]=++time;
    }
  }
}

int next(int u){
  int i;
  for(i=1; i<=n; i++){
    if(a[u][i]==1){
      /*if(color[i]!=W) return MY_NULL;
	else return i;*/
      if(color[i]==W) return i;
    }
  }
  return MY_NULL;
}

void push(int n){
  stack[top]=n;
  top++;
}

int pop(void){
  int n;
  top--;
  n=stack[top];
  stack[top]=0;
  return n;
}

