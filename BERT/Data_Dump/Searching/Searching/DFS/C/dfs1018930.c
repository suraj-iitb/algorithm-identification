#include<stdio.h>
#define N 101
#define WHITE 5
#define GRAY 2
#define BLACK 3

int stack[N],top=0;
int color[N],d[N],A[N][N],f[N],time,n;
void push(int r){
  stack[top]=r;
  top++;
}

int pop(){
  top--;
  return stack[top];
}

int next(int v){
  int i;
  for(i=0;i<n;i++){
    if(A[v][i]==1&&color[i]==WHITE){
      return i;
    }
  }
  return NULL;
}

void dfsVisit(int r){
  int u,i,v;
  push(r);
  color[r] =GRAY;
  d[r] = ++time;
  while(top!=0){
    u = stack[top-1];
    v = next(u);
    if(v!=NULL){
      if(color[v]==WHITE){
	push(v);
	color[v] = GRAY;
	d[v]=++time;
      }
    }
      else{
	pop();
	color[u]=BLACK;
	f[u]=++time;
      }
    
  }
}

void dfs(void){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;
    time = 0;
  }
  for(i=0;i<n;i++){
    if(color[i]==WHITE)
      dfsVisit(i);
  }
  
  
}





int main(){
  int m,l,i,j,s;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&l,&m);
    for(j=0;j<m;j++){
      scanf("%d",&s);
      A[l-1][s-1]=1;
    }
  }
  dfs();
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
  
}
